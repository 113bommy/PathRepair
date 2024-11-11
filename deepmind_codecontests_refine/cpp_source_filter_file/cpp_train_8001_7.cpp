#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	string word, ans;

	getline(cin, word);
	transform(word.begin(), word.end(), word.begin(), toupper);
	cout << word << endl;

	return 0;    
}