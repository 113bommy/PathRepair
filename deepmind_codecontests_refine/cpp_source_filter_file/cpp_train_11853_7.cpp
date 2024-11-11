#include<iostream>
#include<string>
using namespace std;

int main(){
	int h, w;
	cin >> h >> w;
	string l(w+2, '#');
	cout << l << endl;
	for(int i=0; i<h; i++){
		sting tmp;
		cin >> tmp;
		cout << '#' << tmp << "#\n";
	}
	cout << l << endl;
	return 0;
}