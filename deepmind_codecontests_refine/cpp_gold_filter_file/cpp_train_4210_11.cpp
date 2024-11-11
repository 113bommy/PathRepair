#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
struct ty {
  long long a[90][90];
} rt, m;
int k, p;
;
long long n, c[45][45];
void pre(int k) {
  c[0][0] = 1;
  for (int i = 1; i <= k; i++) {
    c[0][i] = 1;
    for (int j = 1; j <= k; j++)
      c[j][i] = (c[j - 1][i - 1] + c[j][i - 1]) % mod;
  }
}
ty multi(ty x, ty y) {
  ty mn;
  for (int i = 0; i <= p; i++)
    for (int j = 0; j <= p; j++) {
      long long d = 0;
      for (int k = 0; k <= p; k++)
        d = (d + (long long)x.a[i][k] * y.a[k][j] % mod) % mod;
      mn.a[i][j] = d;
    }
  return mn;
}
ty quick(long long y) {
  ty s = rt;
  ty t = m;
  while (y != 0) {
    if (y & 1) {
      s = multi(t, s);
    }
    y >>= 1;
    t = multi(t, t);
  }
  return s;
}
int main() {
  scanf("%I64d%d", &n, &k);
  pre(k);
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= i; j++) m.a[i][j] = c[j][i];
    for (int j = k + 1; j <= k + 1 + i; j++) m.a[i][j] = m.a[i][j - k - 1];
  }
  for (int i = k + 1; i <= k + k + 1; i++)
    for (int j = 0; j <= k; j++) m.a[i][j] = m.a[i - k - 1][j];
  m.a[k + k + 2][k] = 1;
  m.a[k + k + 2][k + k + 2] = 1;
  p = k + k + 2;
  for (int i = 0; i < p; i++) rt.a[i][0] = 1;
  ty ans = quick(n);
  printf("%I64d", ans.a[p][0]);
  return 0;
}
