#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
struct cht {
  vector<long double> m, b, k;
  int ptr = 0;
  bool bad(int l1, int l2, int l3) {
    return 1.0 * (b[l3] - b[l1]) * (m[l1] - m[l2]) <=
           1.0 * (b[l2] - b[l1]) * (m[l1] - m[l3]);
  }
  void add(long double _m, long double _b, int _k) {
    m.push_back(_m);
    b.push_back(_b);
    k.push_back(_k);
    int s = m.size();
    while (s >= 3 && bad(s - 3, s - 2, s - 1)) {
      s--;
      m.erase(m.end() - 2), b.erase(b.end() - 2);
      k.erase(k.end() - 2);
    }
  }
  long double f(int i, long double x) { return m[i] * x + b[i]; }
  pair<long double, int> query(long double x) {
    if (ptr >= m.size()) ptr = m.size() - 1;
    while (ptr < m.size() - 1 && f(ptr, x) > f(ptr + 1, x)) ptr++;
    return {f(ptr, x), k[ptr]};
  }
  void clear() { m.clear(), b.clear(), k.clear(), ptr = 0; }
} ds;
const int N = 2e5 + 10;
long double p[N], f[N], r[N];
pair<long double, int> dp[N];
int n, k;
pair<long double, int> get(long double C) {
  ds.clear();
  ds.add(0, 0, 0);
  for (int i = 1; i <= n; ++i) {
    pair<long double, int> tmp = ds.query(r[i]);
    dp[i].first = tmp.first + f[i] + C;
    dp[i].second = tmp.second + 1;
    if (i < n) ds.add(-p[i], dp[i].first - f[i] + r[i] * p[i], dp[i].second);
  }
  return dp[n];
}
int main(int argc, char const *argv[]) {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    p[i] = p[i - 1] + x;
    r[i] = r[i - 1] + 1.0 / (long double)x;
    f[i] = f[i - 1] + p[i] / x;
  }
  cout << fixed << setprecision(10);
  long double lo = 0, hi = 1e17;
  int l = 0, r = n + 1;
  long double lval, rval;
  for (int i = 0; i < 100; i++) {
    long double mid = (lo + hi) / 2;
    pair<long double, int> tmp = get(mid);
    if (tmp.second == k) {
      cout << tmp.first - k * mid << endl;
      return 0;
    }
    if (tmp.second < k) {
      hi = mid;
      if (l < tmp.second) {
        l = tmp.second;
        lval = tmp.first - l * mid;
      }
    } else {
      lo = mid;
      if (tmp.second < r) {
        r = tmp.second;
        rval = tmp.first - r * mid;
      }
    }
  }
  long double ans = (lval * (k - r) - rval * (k - l)) / (l - r);
  cout << ans << endl;
}
