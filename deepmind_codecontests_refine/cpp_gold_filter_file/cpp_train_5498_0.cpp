#include <bits/stdc++.h>

typedef long long ll;

const int MN = 305, P = 998244353;

typedef std::bitset<MN> bst;

bst val[MN], vec[MN];

int n, m, cnt;

inline int fpw(int x, int k) {
	int res = 1;
	for (; k; k >>= 1, x = (ll) x * x % P)
		if (k & 1) res = (ll) res * x % P;
	return res;
}

inline int read() {
	int x; bool f; char c;
	for (f = 0; (c = getchar()) < '0' || c > '9'; f = c == '-');
	for (x = c ^ '0'; (c = getchar()) >= '0' && c <= '9'; x = (x << 1) + (x << 3) + (c ^ '0'));
	return f ? -x : x;
}

int main() {
	n = read(), m = read();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			val[i][j] = read();

	for (int i = 0; i < n; ++i)
		for (int j = m; j--; )
			if (val[i][j]) {
				if (vec[j].count()) val[i] ^= vec[j];
				else {
					++cnt;
					vec[j] = val[i];
				/*	for (int k = j; k--; )
						if (vec[j][k]) vec[j] ^= vec[k];
					for (int k = j; ++k < m; )
						if (vec[k][j]) vec[k] ^= vec[j];*/
					break;
				}
			}

	printf("%lld\n", (ll)fpw(2, m - 1) * (fpw(2, n) - fpw(2, n - cnt) + P) % P);
	return 0;
}