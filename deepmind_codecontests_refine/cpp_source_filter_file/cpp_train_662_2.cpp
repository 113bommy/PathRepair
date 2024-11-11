#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool Q;
struct Line {
  mutable long long k, m, p;
  bool operator<(const Line& o) const { return Q ? p < o.p : k < o.k; }
};
struct LineContainer : multiset<Line> {
  const long long inf = LLONG_MAX;
  long long div(long long a, long long b) {
    return a / b - ((a ^ b) < 0 && a % b);
  }
  bool isect(iterator x, iterator y) {
    if (y == end()) {
      x->p = inf;
      return false;
    }
    if (x->k == y->k)
      x->p = x->m > y->m ? inf : -inf;
    else
      x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(long long m, long long k) {
    m = -m;
    k = -k;
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
  }
  long long query(long long x) {
    assert(!empty());
    Q = 1;
    auto l = *lower_bound({0, 0, x});
    Q = 0;
    return -(l.k * x + l.m);
  }
};
long long d[200005];
vector<long long> v, sum;
int32_t dp[100005][2];
void solve() {
  long long i, j, k, l, r, m, n, a, b, c, x, y, z, t, p;
  LineContainer sh;
  sh.add(3, 2);
  sh.add(0, 0);
  cin >> n >> m >> p;
  for (i = 1; i < n; i++) {
    cin >> d[i];
    d[i] += d[i - 1];
  }
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    x--;
    v.push_back(y - d[x]);
  }
  if (p >= m) {
    cout << 0 << endl;
    return;
  }
  sort(v.begin(), v.end());
  x = 0;
  for (auto& cv : v) {
    x += cv;
    sum.push_back(x);
  }
  for (j = 1; j <= p; j++) {
    sh.clear();
    for (i = 0; i < m; i++) {
      if (j == 1) {
        dp[i][j % 2] = (v[i] * i + v[i]) - sum[i];
      } else {
        if (sh.size() == 0) {
          dp[i][j] = 0;
        } else {
          dp[i][j % 2] = sh.query(v[i]) + v[i] * i - sum[i];
        }
        sh.add(dp[i][(j + 1) % 2] + sum[i], -i);
      }
    }
  }
  cout << dp[m - 1][p % 2] << endl;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
