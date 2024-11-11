#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
	ll N, A, B;
	int pre, now;
	ll ans = 0;

	cin >> N >> A >> B;
	cin >> now;
	for (int i = 1; i < N; i++) {
		pre = now;
		cin >> now;
		ans += min((now - pre) * A, B);
	}

	cout << ans << endl;

	return 0;
}