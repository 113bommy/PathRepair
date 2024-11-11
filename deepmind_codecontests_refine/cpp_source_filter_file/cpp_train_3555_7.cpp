#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mxn = 300100;
const int MOD = 1e9 + 7;
int n;
string s;
pair<long long, long long> a[mxn], b[mxn];
long long o[mxn];
struct z {
  long long i, j, add;
  z() { i = 0, j = 0, add = 0; }
  z(long long a, long long b, long long c) { i = a, j = b, add = c; }
};
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  return (a.first < b.first);
}
void solve() {
  sort(a + 1, a + n + 1, cmp), sort(b + 1, b + n + 1, cmp);
  pair<int, int> l[n], r[n];
  int l_ = 1, r_ = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i].first - b[i].first > 0)
      l[l_++] = {a[i].second, a[i].first - b[i].first};
    else if (a[i].first - b[i].first < 0)
      r[r_++] = {a[i].second, b[i].first - a[i].first};
  }
  int h = 0;
  for (int i = 1; i <= n; i++) {
    int c = b[i].first - a[i].first;
    h += c;
    if (h < 0) {
      puts("NO");
      return;
    }
  }
  if (h != 0) {
    puts("NO");
    return;
  }
  vector<z> v(3 * n);
  int sz = 0;
  int L = 1;
  for (int i = 1; i < l_; i++) {
    int to = l[i].second;
    int add = r[L].second;
    while (to > 0 && L < r_) {
      long long x = min(to, add), p, q;
      if (o[l[i].first] < o[r[L].first])
        p = l[i].first, q = r[L].first;
      else
        p = r[L].first, q = l[i].first;
      v[sz++] = z(p, q, x);
      l[i].second -= x;
      r[L].second -= x;
      add -= x;
      to -= x;
      while (add == 0 && L < r_) {
        L++;
        add = r[L].second;
      }
    }
  }
  bool fl = 0;
  cout << "YES" << endl;
  cout << sz << endl;
  for (int i = 0; i < sz; i++)
    cout << v[i].i << ' ' << v[i].j << ' ' << v[i].add << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i].first, a[i].second = i, o[i] = a[i].first;
  for (int i = 1; i <= n; i++) cin >> b[i].first, b[i].second = i;
  solve();
  return 0;
}
