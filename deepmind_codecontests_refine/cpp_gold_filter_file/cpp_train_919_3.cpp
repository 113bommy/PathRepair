#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<ll> a(N), sum(N + 1), good(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		sum[i + 1] = sum[i] + a[i];
		good[i + 1] = good[i] + max(a[i], 0ll);
	}
	ll res = 0;
	for (int i = 0; i <= N - K; i++) {
		res = max(res, good[N] - good[i + K] + good[i] - good[0]);
		res = max(res, good[N] - good[i + K] + good[i] - good[0] + sum[i + K] - sum[i]);
	}
	cout << res << endl;
	return 0;
}
