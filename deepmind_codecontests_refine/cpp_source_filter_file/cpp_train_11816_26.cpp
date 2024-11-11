#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = (long long)1000 * MOD;
long long st(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    n >>= 1;
  }
  return res;
}
long long invv(long long a) { return st(a, MOD - 2); }
long long f[100500];
long long inv[100500];
long long c(int n, int k) { return f[n] * inv[k] % MOD * inv[n - k] % MOD; }
int main() {
  f[0] = 1;
  inv[0] = invv(f[0]);
  for (int i = 1; i < 100500; ++i) {
    f[i] = f[i - 1] * i % MOD;
    inv[i] = invv(f[i]);
  }
  int h, w, n;
  cin >> h >> w >> n;
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first >> p[i].second;
    --p[i].first;
    --p[i].second;
  }
  sort(p.begin(), p.end());
  p.push_back(make_pair(h - 1, w - 1));
  vector<long long> res(n + 1, 0);
  for (int i = 0; i <= n; ++i) {
    res[i] = (res[i] + c(p[i].first + p[i].second, p[i].first)) % MOD;
    for (int j = i + 1; j <= n; ++j) {
      if (p[i].first <= p[j].first && p[i].second <= p[j].second) {
        int di = p[j].first - p[i].first;
        int dj = p[j].second - p[i].second;
        res[j] = (res[j] + MOD - c(di + dj, di) * res[i] % MOD) % MOD;
      }
    }
  }
  cout << res[n] << endl;
  return 0;
}
