#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	double a, l, x;
	cout.precision(10);
	while (cin >> a >> l >> x) {
		double area = sqrt(l * l - a * a / 4.0) * a / 2.0 + sqrt((l + x) * (l + x) / 4.0 - l * l / 4.0) * l;
		cout << fixed << area << endl;
	}
	return 0;
}