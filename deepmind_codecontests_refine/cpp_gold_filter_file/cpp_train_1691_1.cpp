#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("avx2")
using namespace std;
using ll = long long;
using ld = long double;
const int p = 1000000007;
int mul(int a, int b) { return (1LL * a * b) % p; }
int add(int a, int b) {
  int s = (a + b);
  if (s >= p) s -= p;
  return s;
}
int sub(int a, int b) {
  int s = (a + p - b);
  if (s >= p) s -= p;
  return s;
}
int po(int a, int deg) {
  if (deg == 0) return 1;
  if (deg % 2 == 1) return mul(a, po(a, deg - 1));
  int t = po(a, deg / 2);
  return mul(t, t);
}
int inv(int n) { return po(n, p - 2); }
mt19937 rnd(time(0));
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  vector<int> cnt(n, 1);
  vector<int> pos(n);
  for (int i = 0; i < n; i++) pos[a[i]] = i;
  set<int> free;
  for (int i = 0; i < n; i++) free.insert(i);
  set<pair<int, int>> res;
  for (int i = 0; i < n; i++) res.insert(make_pair(1, i));
  for (int i = 0; i < n; i++) {
    int maxx = prev(res.end())->first;
    if (cnt[pos[i]] != maxx) {
      cout << "No" << endl;
      return;
    }
    free.erase(pos[i]);
    res.erase(make_pair(cnt[pos[i]], pos[i]));
    auto it = free.lower_bound(pos[i]);
    if (it != free.end()) {
      int x = *it;
      res.erase(make_pair(cnt[x], x));
      cnt[x] += maxx;
      res.insert(make_pair(cnt[x], x));
    }
  }
  cout << "Yes" << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
