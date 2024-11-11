#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > c;
vector<int> cp;
vector<vector<int> > dp;
int n, k;
long long m;
int const mod = 1e9 + 7;
int rem;
int f(int i, int k) {
  if (k < 0) return 0;
  if (i == n) {
    if (k > 0)
      return 0;
    else
      return 1;
  }
  int& res = dp[i][k];
  if (res != -1) return res;
  res = 0;
  for (int j = 0; j <= n; ++j) {
    long long r = cp[j];
    if (i < rem) r = (r * c[n][j]) % mod;
    r = (r * f(i + 1, k - j)) % mod;
    res = (res + r) % mod;
  }
  return res;
}
int bpow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}
int main() {
  cin >> n >> m >> k;
  c.assign(n + 1, vector<int>(n + 1, 0));
  cp.assign(n + 1, 0);
  for (int i = 1; i < c.size(); ++i) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; ++j) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  }
  long long p = m / n;
  for (int i = 0; i < cp.size(); ++i) cp[i] = bpow(c[n][i], p);
  dp.assign(n, vector<int>(k + 1, -1));
  rem = m % n;
  cout << f(0, k) << endl;
  return 0;
}
