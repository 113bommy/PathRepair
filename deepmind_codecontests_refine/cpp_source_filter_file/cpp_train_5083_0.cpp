#include <bits/stdc++.h>

#define bit(x) (1 << (x))
#define For(i, j, k) for (int i = j; i <= k; i++)
#define Forr(i, j, k) for (int i = j; i >= k; i--)

const int N = 21;

int buffer[1 << N][N];
int n, k;

int& dp(int l, int ls, int r, int rs) {
	return buffer[bit(l + r) | (ls << r) | rs][r];
}

char S[1 << N];

int main() {

	scanf("%d%d", &n, &k);
	For(i, 0, n) {
		scanf("%s", S);
		For(j, 0, bit(i) - 1) if (S[j] == '1') 
			dp(0, 0, i, j) = 1;
	}

	Forr(r, n, 1) For(rs, 0, bit(r) - 1) {	
		int p1 = -1, p0 = -1;
		Forr(i, r - 1, 0) if (rs & bit(i)) { p1 = i; break; }
		Forr(i, r - 1, 0) if (!(rs & bit(i))) { p0 = i; break; }

		For(l, 0, n - r) For(ls, 0, bit(l) - 1) {
			int w = dp(l, ls, r, rs);
			if (!w) continue;
			if (p1 != -1) dp(l + 1, ls << 1 | 1, p1, rs & (bit(p1) - 1)) += w;
			if (p0 != -1) dp(l + 1, ls << 1, p0, rs & (bit(p0) - 1)) += w;
			dp(l, ls, 0, 0) += w;
		}
	}

	Forr(l, n, 0) Forr(st, bit(l) - 1)
		if (dp(l, st, 0, 0) >= k) {
			Forr(j, l - 1, 0) putchar(st & bit(j) ? '1' : '0'); 
			puts("");
			return 0;
		}

	return 0;
}