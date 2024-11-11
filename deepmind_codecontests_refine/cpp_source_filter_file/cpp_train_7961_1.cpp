#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v;
  long long w;
};
long long MOD = 1000000007;
long long _MOD = 1000000009;
int INF = INT_MAX / 10;
double EPS = 1e-10;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long solve(long long x) {
  vector<bool> p(1000001, true);
  p[0] = p[1] = false;
  for (int i = 2; i <= 1000000; i++)
    if (p[i])
      for (int j = i * 2; j <= 1000000; j += i) p[j] = false;
  vector<int> ps;
  for (int i = 2; i <= 1000000; i++)
    if (p[i]) ps.push_back(i);
  vector<long long> qs;
  for (int i = 2; i <= 1000000; i++)
    if (p[i])
      for (long long j = i; j <= x; j *= i)
        if (x % (j + 1) == 0) qs.push_back(j + 1);
  for (int d = 1; d <= 1000000; d++)
    if (x % d == 0) {
      long long y = x / d;
      bool ok = (y - 1 >= 2);
      for (int p : ps)
        if ((y - 1) % p == 0) ok = false;
      if (ok) qs.push_back(y);
    }
  sort(qs.begin(), qs.end());
  qs.erase(unique(qs.begin(), qs.end()), qs.end());
  map<long long, long long> mp;
  mp[x] = 1;
  for (long long q : qs) {
    map<long long, long long> _mp;
    for (pair<long long, long long> z : mp) {
      _mp[z.first] += z.second;
      if (z.first % q == 0) _mp[z.first / q] += z.second;
    }
    mp = _mp;
  }
  return mp[1];
}
int f(vector<int>& index, vector<int>& _index, long long x, long long y) {
  return y <= 1000000 ? index[y] : _index[x / y];
}
int main() {
  vector<bool> p(1000001, true);
  for (int i = 2; i <= 1000000; i++)
    if (p[i])
      for (int j = i * 2; j <= 1000000; j += i) p[j] = false;
  vector<int> ps;
  for (int i = 2; i <= 1000000; i++)
    if (p[i]) ps.push_back(i);
  long long x;
  cin >> x;
  vector<long long> ds;
  for (long long d = 1; d * d <= x; d++)
    if (x % d == 0) {
      ds.push_back(d);
      if (d * d < x) ds.push_back(x / d);
    }
  int N = ds.size();
  vector<int> index(1000001), _index(1000001);
  for (int i = 0; i < N; i++)
    if (ds[i] <= 1000000)
      index[ds[i]] = i;
    else
      _index[x / ds[i]] = i;
  vector<long long> dp(N);
  dp[f(index, _index, x, x)] = 1;
  for (int p : ps) {
    vector<long long> _dp = dp;
    for (long long q = p; q <= x; q *= p)
      if (x % (q + 1) == 0)
        for (long long d : ds)
          if (d % (q + 1) == 0)
            _dp[f(index, _index, x, d / (q + 1))] += dp[f(index, _index, x, d)];
    dp = _dp;
  }
  long long ans = dp[0];
  for (long long d : ds) {
    long long x = d - 1;
    if (x <= 1000000) continue;
    bool ok = true;
    for (int p : ps)
      if (x % p == 0) {
        ok = false;
        break;
      }
    if (ok) ans += dp[f(index, _index, x, d)];
  }
  cout << ans << endl;
}
