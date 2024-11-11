#include <iostream>
using namespace std;

int main() {
	int a, b, c, k;
	cin >> a >> b >> c >> k;

	int answer = min(a, k) - min(c, max(0, k - a - b));
	cout << answer << endl;
}