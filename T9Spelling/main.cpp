#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;
void translate();

// both methods result in same performance
string getNum(char);
string getNum2(char);

int cases;
string letterString, numberString, junk;
string infileName = "cLargeIn.in", outfileName = "cLargeOut2.out";
ifstream infile(infileName.c_str());
ofstream outfile(outfileName.c_str());

string alphabet[26] = {"2","22","222","3","33","333","4","44","444",
	"5","55","555","6","66","666","7","77","777","7777","8","88","888",
	"9","99","999","9999"};

int main() {

	clock_t tStart = clock();

	infile >> cases;
	getline(infile, junk);
	for (int i = 1; i <= cases; i++) {
		numberString = "";
		getline(infile, letterString);
		translate();
		outfile << "Case #" << i << ": " << numberString << endl;
	}

	infile.close();
	outfile.close();
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	cin.get();
	return 0;
}

void translate() {
	string numString;
	int numberStringLen;
	for (unsigned int i = 0; i < letterString.length(); i++) {
		numString = getNum2(letterString.at(i));
		numberStringLen = numberString.length();
		numberString = (numberStringLen > 0) &&
			(numberString.at(numberStringLen-1) == numString.at(0)) ?
			numberString + " " + numString : numberString + numString;
	}
}

string getNum(char letter) {
	switch(letter) {
		case 'a': return "2";
		case 'b': return "22";
		case 'c': return "222";
		case 'd': return "3";
		case 'e': return "33";
		case 'f': return "333";
		case 'g': return "4";
		case 'h': return "44";
		case 'i': return "444";
		case 'j': return "5";
		case 'k': return "55";
		case 'l': return "555";
		case 'm': return "6";
		case 'n': return "66";
		case 'o': return "666";
		case 'p': return "7";
		case 'q': return "77";
		case 'r': return "777";
		case 's': return "7777";
		case 't': return "8";
		case 'u': return "88";
		case 'v': return "888";
		case 'w': return "9";
		case 'x': return "99";
		case 'y': return "999";
		case 'z': return "9999";
		case ' ': return "0";
		default: return "-1";
	}
}

string getNum2(char letter) {
	if (letter == ' ') return "0";
	int intLetter = (int)letter;
	if (intLetter < 97 || intLetter > 122) return "-1";
	return alphabet[intLetter - 97];
}