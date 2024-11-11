#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9, MOD = 998244353;

string s;

int n, cntr, cntg, cntb, r[N], g[N], b[N], pos[N * 3]; 

long long ans = 1, A, B, C; 

inline int min(int x, int y, int z) {
	return std::min(std::min(x, y), z);
}

inline int max(int x, int y, int z) {
	return std::max(std::max(x, y), z);
}

void solve() {
	A = n;
	for (int i = 0; i < n * 3; ++i) {
		if (s[i]== 'R') {
			r[cntr++] = i;
		} else if (s[i] == 'G') {
			g[cntg++] = i;
		} else {
			b[cntb++] = i;
		}
	}
	for (int i = 0; i < n; ++i) {
		pos[min(r[i], g[i], b[i])] = -1;
		pos[max(r[i], g[i], b[i])] = 1;
	} 
	for (int i = 0; i < n * 3; ++i) {
		if (pos[i] == -1) 
			ans = ans * A % MOD, A--, B++;
		else if (pos[i] == 0) 
			ans = ans * B % MOD, B--, C++;
		else 
			ans = ans * C % MOD, C--;
	}
	printf("%lld\n", ans);
}

int main() {
	cin >> n >> s;
	solve();
	return 0;
}