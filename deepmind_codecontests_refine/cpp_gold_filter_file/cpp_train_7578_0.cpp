#include <bits/stdc++.h>

using namespace std;

template <class T> T gcd(T a, T b) {
	if (a < b) swap(a, b);
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

vector<int> sieve(int n) {
	vector<int> primes;
	vector<bool> isPrime(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (!isPrime[i]) continue;
		primes.push_back(i);
		for (int j = i + i; j <= n; j += i) {
			isPrime[j] = false;
		}
	}
	return primes;
}

class Solution {
public:
	void solve() {
		int n;
		cin >> n;
		vector<int> a(n + 1, 0);
		vector<int> ans;
		vector<int> primes = sieve(1000000);
		for (auto& x : a) cin >> x;
		int y = abs(a[0]);
		for (auto x : a)
			if (x != 0) y = gcd(y, abs(x));
		for (auto p : primes) {
			if (!(y % p)) {
				ans.push_back(p);
				while (!(y % p)) y /= p;
			}
			if (y == 1) break;
		}
		if (y != 1) ans.push_back(y);

		for (auto p : primes) {
			if (p > n) break;
			if (abs(a[n]) % p) continue;
			vector<long long> f(p);
			for (int i = 0; i < n; i++) {
				f[i % (p - 1)] += a[i];
			}
			bool ok = true;
			for (int i = 0; i < p; i++) {
				if (f[i] % p) {
					ok = false;
					break;
				}
			}
			if (ok) ans.push_back(p);
		}

		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		for (auto x : ans) cout << x << " ";
		cout << "\n";

		return;
	};
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	Solution solution;
	solution.solve();
	return 0;
}