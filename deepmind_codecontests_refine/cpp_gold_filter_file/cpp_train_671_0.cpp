#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 7;
const int Q = 1e9 + 7;
inline int pls(int x, int y) { return ((long long)x + y) % Q; }
inline int mns(int x, int y) { return pls(x, Q - y); }
inline int mul(int x, int y) { return 1LL * x * y % Q; }
inline int ri() {
  int x = 0;
  bool f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = 0;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
  return f ? x : -x;
}
int n, L, R;
char str[M];
int d[M], s[M];
int pw[M];
int fac[M], ifac[M];
int inv[M];
int f[M];
inline int binom(int x, int y) {
  if (x < y) return 0;
  return mul(fac[x], mul(ifac[y], ifac[x - y]));
}
int calc(int m) {
  if (m < 0) return 0;
  int i, res = 0;
  for (f[0] = 1, i = 1; i <= n; i++)
    f[i] = mns(mul(2, f[i - 1]), binom(i - 1, m));
  for (i = 1; i <= n; i++) res = pls(res, mul(mul(d[i], pw[n - i]), f[i - 1]));
  for (i = 0; i <= n - 2; i++)
    res = pls(res, mul(mul(s[n - i - 1], pw[i]),
                       mns(f[n - i - 2], binom(n - i - 2, m))));
  return res;
}
void init() {
  int i;
  for (i = 1; i <= n; i++) d[i] = str[i] - '0';
  for (s[0] = 0, i = 1; i <= n; i++) s[i] = pls(d[i], s[i - 1]);
  for (pw[0] = 1, i = 1; i <= n; i++) pw[i] = mul(pw[i - 1], 10);
  for (inv[1] = 1, i = 2; i <= n; i++) inv[i] = mul(inv[Q % i], Q - Q / i);
  for (fac[0] = 1, i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
  for (ifac[0] = 1, i = 1; i <= n; i++) ifac[i] = mul(ifac[i - 1], inv[i]);
}
int main() {
  int i;
  n = ri();
  L = ri();
  R = L;
  scanf("%s", str + 1);
  init();
  printf("%d\n", mns(calc(R), calc(L - 1)));
  return 0;
}
