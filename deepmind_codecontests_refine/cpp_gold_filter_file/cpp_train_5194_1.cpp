#include<iostream>
using namespace std;
int main() {
	int a[7], b[7], i;
	for (i = 0; i < 7; i++) {
		cin >> a[i] >> b[i];
		cout << a[i] - b[i]<< endl;
	}
	return 0;


}