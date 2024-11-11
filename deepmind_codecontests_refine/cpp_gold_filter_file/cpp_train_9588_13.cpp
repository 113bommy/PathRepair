#include <bits/stdc++.h>
using namespace std;
const long long N = 1e18;
void mul(long long &x, long long y) {
  if (N / y < x)
    x = N + 1;
  else
    x *= y;
}
long long binpow(long long u, int v) {
  long long ans = 1;
  while (v) {
    if (v & 1) mul(ans, u);
    mul(u, u);
    v >>= 1;
  }
  return ans;
}
long long p[70][70];
int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i < 70; ++i) {
    p[i][0] = 1;
    for (int j = 1; j < 70; ++j) {
      p[i][j] = p[i][j - 1];
      mul(p[i][j], i);
    }
  }
  while (T--) {
    long long n;
    scanf("%lld", &n);
    vector<long long> f(61, 0);
    for (int i = 60; i >= 1; --i) {
      long long lo = 1, hi = n;
      if (i >= 10) {
        int x = 1;
        while (p[x + 1][i] <= n) ++x;
        f[i] = x - 1;
      } else
        while (lo <= hi) {
          long long m = (lo + hi) >> 1;
          long long v = 1;
          for (int k = 1; k <= i; ++k) mul(v, m);
          if (v <= n) {
            f[i] = m - 1;
            lo = m + 1;
          } else
            hi = m - 1;
        }
      for (int j = i + i; j <= 60; j += i) {
        f[i] -= f[j];
      }
    }
    cout << f[1] << endl;
  }
  return 0;
}
