#include <bits/stdc++.h>

typedef long long LL;
typedef unsigned long long ULL;
1
#define debug printf("fuck %d\n", __LINE__);

inline LL read() {
	LL res = 0, bo = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') { if (ch == '-') bo = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') { res = (res << 1) + (res << 3) + ch - '0'; ch = getchar(); }
	return bo * res;
}

template<typename T> void read(T &x) { x = read(); }
template<typename T, typename ...Argv> void read(T &a, Argv &...argv) { read(a); read(argv...); }

const int mod = 998244353;

inline int add(int a, int b) {
	a += b;
	return a >= mod ? a - mod : a;
}

inline int sub(int a, int b) {
	a -= b;
	return a < 0 ? a + mod : a;
}

inline int mul(int a, int b) { return (LL)a * b % mod; }

inline int ksm(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}	
const int inv2 = ksm(2, mod - 2);

int n, s;

inline void FWT(int *t, int n, int type) {	
	for (int step = 1; step < n; step <<= 1) {
		for (int i = 0; i < n; i += step << 1) {
			for (int j = 0; j < step; ++ j) {
				int x = t[i + j], y = t[i + j + step];
				t[i + j] = add(x, y), t[i + j + step] = sub(x, y);
				if (type == -1) {
					t[i + j] = mul(t[i + j], inv2);
					t[i + j + step] = mul(t[i + j + step], inv2);
				}
			}
		}
	}
}

const int N = 1 << 18;
int p[N], a[N];

int main() {
	read(n);
	for (int i = 0; i < 1 << n; ++ i) read(p[i]), s = add(s, p[i]);
	s = ksm(s, mod - 2);
	for (int i = 0; i < 1 << n; ++ i) p[i] = mul(p[i], s);
	for (int i = 1; i < 1 << n; ++ i) a[i] = mod - 1;
	a[0] = (1 << n) - 1;
	p[0] = sub(p[0], 1); 
	FWT(a, 1 << n, 1), FWT(p, 1 << n, 1);
	for (int i = 0; i < 1 << n; ++ i) a[i] = mul(a[i], ksm(p[i], mod - 2));
	FWT(a, 1 << n, -1);
	for (int i = 0; i < 1 << n; ++ i) {
		printf("%d\n", sub(a[i], a[0]));
	}
}