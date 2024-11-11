#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
long long binpow(long long x, long long ind) {
  if (!ind) return 1;
  if (ind % 2) return (binpow(x, ind - 1) * x) % mod;
  long long y = binpow(x, ind / 2);
  return (y * y) % mod;
}
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long place = m % n;
  vector<long long> d(n + 1);
  d[0] = 1;
  d[1] = 1;
  for (int j = 2; j <= n; ++j) {
    vector<long long> e(n + 1);
    e[0] = 1;
    for (int i = 1; i <= min(k, n); ++i) e[i] = (d[i] + d[i - 1]) % mod;
    d = e;
  }
  vector<vector<long long> > c(n + 1, vector<long long>(2));
  for (int i = 0; i <= min(k, n); ++i) c[i][0] = binpow(d[i], (m + 1) / n);
  if (m % n)
    for (int i = 0; i <= min(k, n); ++i) c[i][1] = (c[i][0] * d[i]) % mod;
  vector<vector<long long> > dyn(n, vector<long long>(k + 1));
  for (int i = 0; i <= min(k, n); ++i)
    if (place)
      dyn[0][i] = c[i][1];
    else
      dyn[0][i] = c[i][0];
  for (long long i = 1; i < n; ++i) {
    long long start = 0;
    if (k - (n - i - 1) * n > 0) start = k - (n - i - 1) * n;
    for (long long j = start; j <= min(k, (i + 1) * n); ++j)
      for (long long u = 0; u <= min(k, n); ++u)
        if (j >= u)
          if (i >= place)
            dyn[i][j] = (dyn[i][j] + dyn[i - 1][j - u] * c[u][0]) % mod;
          else
            dyn[i][j] = (dyn[i][j] + dyn[i - 1][j - u] * c[u][1]) % mod;
  }
  cout << dyn[n - 1][k];
  return 0;
}
