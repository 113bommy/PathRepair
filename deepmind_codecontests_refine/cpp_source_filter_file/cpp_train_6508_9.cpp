#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long linf = 100000000000000000LL;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
const int p = 1000000009;
int n, b, k, x;
int a[50005];
struct mtr {
  long long g[105][105];
  mtr() {
    for (int i = 0; i < 105; i++)
      for (int j = 0; j < 105; j++) g[i][j] = 0;
  }
} tr;
mtr _mul(mtr xx, mtr yy) {
  mtr ret;
  for (int i = 0; i < x; i++)
    for (int j = 0; j < x; j++)
      for (int k = 0; k < x; k++)
        ret.g[i][j] = (ret.g[i][j] + xx.g[i][k] * yy.g[k][j] % p) % p;
  return ret;
}
mtr _pow(mtr xx, int y) {
  mtr ret = xx;
  y--;
  while (y) {
    if (y & 1) ret = _mul(ret, xx);
    y >>= 1;
    xx = _mul(xx, xx);
  }
  return ret;
}
int main() {
  n = read(), b = read(), k = read(), x = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 0; i < x; i++)
    for (int j = 1; j <= n; j++) tr.g[i][(i * 10 + a[j]) % x]++;
  tr = _pow(tr, b);
  long long ans = 0;
  ans = (ans + tr.g[0][k]) % p;
  cout << ans << endl;
  return 0;
}
