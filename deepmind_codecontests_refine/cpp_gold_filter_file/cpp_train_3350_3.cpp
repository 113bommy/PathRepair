#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int maxn = 200000 + 10;
const int DEBUG = 0;
inline int inc(int a, int b) {
  return (a + b >= MOD) ? (a + b - MOD) : (a + b);
}
inline int dec(int a, int b) { return (a >= b) ? (a - b) : (a + MOD - b); }
inline int mul(int a, int b) { return 1LL * a * b % MOD; }
inline int power(int x, int k) {
  int tmp = 1;
  while (k) {
    if (k & 1) tmp = mul(tmp, x);
    x = mul(x, x);
    k >>= 1;
  }
  return tmp;
}
int n, k, p[maxn], pcnt, mu[maxn], cnt[maxn];
bool isp[maxn];
inline void prepare(int N) {
  isp[0] = isp[1] = 1;
  pcnt = 0;
  mu[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (!isp[i]) {
      p[++pcnt] = i;
      mu[i] = dec(MOD, 1);
    }
    for (int j = 1; j <= pcnt && i * p[j] <= N; j++) {
      isp[i * p[j]] = 1;
      if (i % p[j] == 0) {
        mu[i * p[j]] = 0;
        break;
      }
      mu[i * p[j]] = dec(MOD, mu[i]);
    }
  }
}
int main() {
  scanf("%d%d", &n, &k);
  prepare(200000);
  int Ans = 0;
  for (int d = 1; d <= n - 1; d++) {
    int lim = (2 * n - 2) / d;
    for (int _s = 1; _s <= lim; _s++) {
      for (int t = _s; t <= lim; t += _s) {
        int l = max(0, (t * d - n) / d);
        int r = min((n - 1) / d, t - 1);
        int tmp = dec(r / _s, l / _s);
        cnt[t] = inc(cnt[t], mul(mu[_s], tmp));
      }
    }
    for (int _s = 1; _s <= lim; _s++) {
      int tmp = power(k, max(_s * d - n, d));
      if (DEBUG) printf("cnt[%d][%d] = %d\n", d, _s * d, cnt[_s]);
      Ans = inc(Ans, mul(tmp, cnt[_s]));
    }
    if (DEBUG) puts("");
    for (int i = 1; i <= lim + 1; i++) cnt[i] = 0;
  }
  Ans = mul(Ans, power(power(k, n), MOD - 2));
  printf("%d\n", Ans);
  return 0;
}
