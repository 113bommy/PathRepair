#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int out = 0, fh = 1;
  char jp = getchar();
  while ((jp > '9' || jp < '0') && jp != '-') jp = getchar();
  if (jp == '-') fh = -1, jp = getchar();
  while (jp >= '0' && jp <= '9') out = out * 10 + jp - '0', jp = getchar();
  return out * fh;
}
void print(int x) {
  if (x >= 10) print(x / 10);
  putchar('0' + x % 10);
}
void write(int x, char c) {
  if (x < 0) putchar('-'), x = -x;
  print(x);
  putchar(c);
}
const int P = 1e9 + 7;
int add(int a, int b) { return a + b >= P ? a + b - P : a + b; }
void inc(int &a, int b) { a = add(a, b); }
int mul(int a, int b) { return 1LL * a * b % P; }
int fpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
const int N = 2e5 + 10;
int fac[N], invfac[N];
int S(int n, int k) {
  if (n < k) return 0;
  int s = 0;
  for (int i = 0; i <= k; ++i) {
    int t = mul(mul(invfac[k - i], invfac[i]), fpow(k - i, n));
    if (i & 1)
      inc(s, P - t);
    else
      inc(s, t);
  }
  return s;
}
int n, k, ans = 0;
int main() {
  n = read(), k = read();
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) inc(ans, read()), fac[i] = mul(fac[i - 1], i);
  invfac[n] = fpow(fac[n], P - 2);
  for (int i = n - 1; i >= 0; --i) invfac[i] = mul(invfac[i + 1], i + 1);
  int coef = add(mul(S(n - 1, k), n - 1), S(n, k));
  ans = mul(ans, coef);
  cout << ans << '\n';
  return 0;
}
