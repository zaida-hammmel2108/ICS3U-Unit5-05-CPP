// Copyright (c) 2022 Zaida Hammel All rights reserved
//
// Created by: Zaida Hammel
// Created on: Dec 2022
//  This program formats your address for post

#include <algorithm>
#include <cstring>
#include <iostream>
#include <locale>
#include <stdexcept>
#include <string>

std::string address(std::string fullName,
                    std::string streetNumber,
                    std::string streetName,
                    std::string city,
                    std::string province,
                    std::string postalCode,
                    std::string apartmentNumber = "") {
    std::string formatted;

    std::for_each(fullName.begin(),
                  fullName.end(), [](char& c) { c = ::toupper(c); });
    std::for_each(streetName.begin(),
                  streetName.end(), [](char& c) { c = ::toupper(c); });
    std::for_each(city.begin(),
                  city.end(), [](char& c) { c = ::toupper(c); });
    std::for_each(province.begin(),
                  province.end(), [](char& c) { c = ::toupper(c); });
    std::for_each(postalCode.begin(),
                  postalCode.end(), [](char& c) { c = ::toupper(c); });

    formatted = fullName + "\n";
    formatted = formatted + streetNumber;
    if (std::string(apartmentNumber) != "") {
        formatted = formatted + "-" + apartmentNumber;
    }
    formatted = formatted + " " + streetName + "\n";
    formatted = formatted + city + " ";
    formatted = formatted + province + "  ";
    formatted = formatted + postalCode;

    return formatted;
}

int main() {
    std::string fullName;
    std::string question;
    std::string streetNumber;
    std::string streetName;
    std::string city;
    std::string province;
    std::string postalCode;
    std::string properAddress;
    std::string apartmentNumber = "";
    int apartmentNumberAsInt = 0;
    int streetNumberAsInt = 0;

    // input
    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullName);
    std::cout << "Do you live in an apartment? (y/n): ";
    std::getline(std::cin, question);
    if (question == "y") {
        std::cout << "Enter your apartment number: ";
        std::getline(std::cin, apartmentNumber);
    }
    std::cout << "Enter your street number: ";
    std::getline(std::cin, streetNumber);
    std::cout << "Enter your street name and type: ";
    std::getline(std::cin, streetName);
    std::cout << "Enter your city: ";
    std::getline(std::cin, city);
    std::cout << "Enter your province (as an abbreviation): ";
    std::getline(std::cin, province);
    std::cout << "Enter your postal code: ";
    std::getline(std::cin, postalCode);
    std::cout << "" << std::endl;

    // process
    try {
        if (apartmentNumber == "y") {
            apartmentNumberAsInt = stoi(apartmentNumber);
        }
        streetNumberAsInt = stoi(streetNumber);
        // calls function
        properAddress = address(fullName, streetNumber, streetName, city,
                                province, postalCode, apartmentNumber);
        std::cout << properAddress << std::endl;
    // output
    } catch (std::invalid_argument) {
        std::cout << "Invalid Input." << std::endl;
    }

    std::cout << "\nDone." << std::endl;
}
