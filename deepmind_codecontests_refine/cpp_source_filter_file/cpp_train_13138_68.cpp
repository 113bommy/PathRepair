#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long cl(long double a) {
  if (a > (long long)a) {
    return (long long)a + 1;
  } else {
    return (long long)a;
  }
}
long long flr(long double a) { return (long long)a; }
const long long M = 2e5 + 100;
vector<long long> st(4 * M + 1);
long long a[M];
void update(long long v, long long tl, long long tr, long long pos,
            long long change) {
  if (tl == tr) {
    st[v] += change;
    return;
  }
  long long tm = (tl + tr) / 2;
  if (pos <= tm)
    update(2 * v, tl, tm, pos, change);
  else
    update(2 * v + 1, tm + 1, tr, pos, change);
  st[v] = st[2 * v] + st[2 * v + 1];
}
long long query(long long v, long long tl, long long tr, long long l,
                long long r) {
  if (tl > r || tr < l) return 0;
  if (tl >= l && tr <= r) return st[v];
  long long tm = (tl + tr) / 2;
  return query(2 * v, tl, tm, l, r) + query(2 * v + 1, tm + 1, tr, l, r);
}
vector<long long> z_function(string &s) {
  long long n = (long long)s.size();
  vector<long long> z(2 * n + 1);
  for (long long i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
void solve() {
  string s;
  cin >> s;
  vector<long long> zs = z_function(s);
  long long ans = 0;
  long long n = s.length();
  vector<long long> z = z_function(s);
  for (long long i = 1; i < n; i++) {
    update(1, 0, n, z[i], 1);
  }
  for (long long i = n - 1; i > 1; i--) {
    if (z[i] != n - i) continue;
    long long p1 = query(1, 0, n, 0, n);
    long long p2 = query(1, 0, n, 0, z[i] - 1);
    if (p1 - p2 >= 2) {
      ans = max(ans, z[i]);
    }
    update(1, 0, n, z[i], -1);
  }
  if (!ans) {
    cout << "Just a legend"
         << "\n";
    return;
  }
  cout << s.substr(0, ans) << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) solve();
}
