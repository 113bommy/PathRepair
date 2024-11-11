#include <bits/stdc++.h>
#define ll long long
#define mk make_pair
using namespace std;
const int N = 2e2 + 5;
const int mod = 998244353;
bool bo[N][N];
int n, x[N], y[N];
vector<int> V;
ll ans, p[N];
bool line(int i, int j, int k) {
	return (x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]) == 0; 
}
int main() {
	p[0] = 1;
	for (int i = 1; i < N; i++) p[i] = p[i - 1] * 2 % mod;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (bo[i][j]) continue;
			V.clear();
			V.push_back(i);
			V.push_back(j);
			for (int k = j + 1; k <= n; k++) {
				if (line(i, j, k)) V.push_back(k);
			}
			for (int k = 0; k < V.size(); k++)
				for (int l = 0; l < V.size(); l++)
					bo[V[k]][V[l]] = 1;
			ans += p[V.size()] - V.size() - 1;
			ans %= mod;
		}
	}
	ans = p[n] - ans - n - 1;
	ans %= mod;
	ans += mod;
	ans %= mod;
	cout << ans;
}

