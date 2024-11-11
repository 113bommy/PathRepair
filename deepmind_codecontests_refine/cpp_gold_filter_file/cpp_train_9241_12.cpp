#include <iostream>
using namespace std;

int main(){
	int a;
	string b;
	cin >> a;
	cin >> b;

	if (b.size() > a) {
		b = b.substr(0, a) + "...";
	}

	cout << b << endl;
}