#include <iostream>
using namespace std;

int n, ans;

int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		int a; cin >> a;
		while (a % 2 == 0) { a /= 2; ++ans; }
	}
	cout << ans << endl;
	return 0;
}