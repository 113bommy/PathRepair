#include <iostream>
using namespace std;
int main() {
	long long int a, b, c;
	cin >> a >> b >> c;
	if (4*a*b>=(c-a-b)*(c-a-b)||c-a-b>0)
		cout << "No";
	else
		cout << "Yes";
