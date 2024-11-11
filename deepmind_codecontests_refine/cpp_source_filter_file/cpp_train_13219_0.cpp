#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N, M, T; cin >> N >> M >> T;
	vector<ll> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];
	ll ans = 0;
	ans += a[0] - M;
	for (int i = 1; i < N;i++) {
		if (a[i] - a[i - 1] <= 2 * M) continue;
		else {
			ans += a[i] - a[i - 1] - 2 * M;
		}
	ans += max(0LL, T - a[N - 1] - M);
	cout << ans << endl;
}