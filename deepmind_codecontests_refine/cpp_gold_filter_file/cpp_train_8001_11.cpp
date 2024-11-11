#include <iostream>
#include <string>

using namespace std;

int main(){
	string ch;
	int i;

	getline(cin, ch);

		for(i=0; i<ch.size(); i++){

		if(isalpha(ch[i])!=0){
			ch[i] = toupper(ch[i]);
		}
	}

	cout << ch << endl;
}