#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const long long llinf = 0x3f3f3f3f3f3f3f3f;
long long f[1005][11];
long long qpow(long long a, long long b) {
  long long ans = 1, bs = a;
  while (b) {
    if (b & 1) {
      ans *= bs;
    }
    bs *= bs;
    b >>= 1;
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  long long pr[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  memset(f, 0x3f, sizeof(f));
  long long lim = log(1e18) / log(pr[1]);
  f[1][0] = 1;
  for (int i = 2; i <= lim + 1; ++i) {
    long long tp = qpow(pr[1], i - 1);
    f[i][1] = tp;
  }
  for (int i = 1; i <= 1000; ++i) {
    for (int j = 2; j <= 10; ++j) {
      long long lim = log(1e18) / log(pr[j]);
      lim = min(lim, i * 1ll);
      for (int k = 1; k <= lim; ++k) {
        if (i % (k + 1) == 0) {
          long long tp = qpow(pr[j], k);
          long long tp1 = ((long long)(1e18) + tp - 1) / tp;
          if (f[i / (k + 1)][j - 1] >= tp1) continue;
          f[i][j] = min(f[i][j], f[i / (k + 1)][j - 1] * tp);
        }
      }
    }
  }
  long long mi = llinf;
  for (int i = 0; i <= 10; ++i) {
    mi = min(f[n][i], mi);
  }
  cout << mi << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
