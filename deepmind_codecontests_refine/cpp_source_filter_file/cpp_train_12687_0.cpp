#include<iostream>
using namespace std;

int main(void) {
	char c;
	int a, b, sum, ave, i;
	sum = ave = i = 0;
	while (cin >> a >> c >> b) {
		sum += a*b;
		ave += b;
		i++
	}
	cout << sum << endl;
	cout << (int)(((double)ave / i) + 0.5) << endl;
}