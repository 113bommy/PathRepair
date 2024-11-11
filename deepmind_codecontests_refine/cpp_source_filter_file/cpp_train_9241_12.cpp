#include <iostream>
using namespace std;

int main(){
	int a;
	string b;
	cin >> a;
	cin >> b;

	if (b.size() > k) {
		b = b.substr(0, k) + "...";
	}

	cout << b << endl;
}