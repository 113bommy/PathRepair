#include <bits/stdc++.h>
using namespace std;
typdef long long ll;

int A[200005], B[200005];

inline int mod(int i, int m) { return i >= m ? i - m : i; }

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < N; ++i) cin >> B[i];

	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < N; ++i) {
		if (A[i] < B[i]) {
			pq.emplace(B[i], i);
		}
		else if (A[i] > B[i]) {
			cout << -1 << '\n';
			return 0;
		}
	}

	ll ans = 0;
	while (!pq.empty()) {
		pair<int, int> p = pq.top();
		pq.pop();
		int i = p.second, d = B[mod(i - 1 + N, N)] + B[mod(i + 1, N)];
		if (B[i] - A[i] < d) {
			cout << -1 << '\n';
			return 0;
		}
		ans += (B[i] - A[i]) / d;
		B[i] -= d * ((B[i] - A[i]) / d);
		if (A[i] < B[i]) {
			pq.emplace(B[i], i);
		}
	}
	cout << ans << '\n';
	return 0;
}
