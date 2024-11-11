#include <bits/stdc++.h>
using namespace std;
inline long long getint() {
  long long _x = 0, _tmp = 1;
  char _tc = getchar();
  while ((_tc < '0' || _tc > '9') && _tc != '-') _tc = getchar();
  if (_tc == '-') _tc = getchar(), _tmp = -1;
  while (_tc >= '0' && _tc <= '9') _x *= 10, _x += (_tc - '0'), _tc = getchar();
  return _x * _tmp;
}
long long md = 1000000007;
const long long inf = (long long)1e16;
long long _mx = -inf;
inline long long mulD(long long a, long long b) {
  long long r = 0;
  while (b > 0) {
    if (b & 1) {
      r = r + a % md;
      r = r % md;
    }
    b /= 2;
    a = 2 * a % md;
    a = a % md;
  }
  return r % md;
  ;
}
inline long long exp(long long a, long long b) {
  long long r = 1LL;
  while (b > 0) {
    if (b & 1) {
      r = r * (a % md);
      r = (r + md) % md;
    }
    b /= 2;
    a = (a % md) * (a % md);
    a = (a + md) % md;
  }
  return (r + md) % md;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
inline long long poww(long long a, long long b) {
  long long r = 1LL;
  while (b > 0) {
    if (b & 1) r = r * a;
    b /= 2;
    a = a * a;
  }
  return (long long)r;
}
long long a[200000 + 1], vis[200000 + 1], b[200000 + 1];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, i, s, j, m, x, y, z, k, q, n, p, T;
  string s1, s2, s3;
  x = 0;
  long long l, r;
  cin >> n;
  vector<vector<long long> > g(n + 1);
  for (i = 0; i < (n - 1); ++i) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (long long i = (1); i <= (n); ++i) cin >> a[i];
  for (long long i = (1); i <= (n); ++i) b[a[i]] = i;
  for (i = 1; i <= n; ++i) {
    sort(g[i].begin(), g[i].end(),
         [&](long long x, long long y) { return b[x] < b[y]; });
  }
  queue<long long> pq;
  vector<long long> v;
  v.push_back(0);
  pq.push(1);
  vis[1] = 1;
  y = 1;
  while (!pq.empty()) {
    long long cur = pq.front();
    pq.pop();
    v.push_back(cur);
    for (auto x : g[cur]) {
      if (!vis[x]) {
        vis[x] = 1;
        pq.push(x);
      }
    }
  }
  p = 1;
  for (long long i = (1); i <= (n); ++i)
    if (v[i] != a[i]) p = 0;
  if (p)
    cout << "Yes";
  else
    cout << "No";
}
