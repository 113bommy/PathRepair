#include<iostream>
#include<string>
#include<algorithm>


int main(){
	std::string word, ans;

	getline(cin, word);
	std::transform(word.begin(), word.end(), word.begin(), toupper);
	std::cout << word << std::endl;

	return 0;
}