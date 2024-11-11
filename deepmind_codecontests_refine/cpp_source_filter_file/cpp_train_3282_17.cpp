#include <bits/stdc++.h>
using namespace std;
inline long long bip(long long x, long long n, long long mod) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res = (res * x) % mod;
    }
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}
const int maxn = 1e9;
const long long inf = 1e18;
const int mod = 1e9 + 7;
const int N = 1e2 + 10;
int n, ti[N], x[N], ty[N], ans[N], t[N];
map<int, vector<pair<pair<int, int>, int>>> g;
void upd(int v, int tl, int tr, int pos, int val) {
  if (tl == tr)
    t[v] += val;
  else {
    int tm = (tl + tr) >> 1;
    if (pos <= tm)
      upd(v + v, tl, tm, pos, val);
    else
      upd(v + v + 1, tm + 1, tr, pos, val);
    t[v] = t[v + v] + t[v + v + 1];
  }
}
int get(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) >> 1;
  return get(v + v, tl, tm, l, min(tm, r)) +
         get(v + v + 1, tm + 1, tr, max(tm + 1, l), r);
}
void solve() {
  cin >> n;
  map<int, int> m;
  for (int i = 1; i <= n; i++)
    cin >> ty[i] >> ti[i] >> x[i], m[ti[i]]++, ans[i] = -1;
  int k = 1;
  for (auto &it : m) {
    it.second = k;
    k++;
  }
  for (int i = 1; i <= n; i++) {
    ti[i] = m[ti[i]];
    g[x[i]].push_back({{ty[i], ti[i]}, i});
  }
  for (auto it : g) {
    for (auto v : it.second) {
      if (v.first.first == 1) {
        upd(1, 1, n, v.first.second, 1);
      } else if (v.first.first == 2) {
        upd(1, 1, n, v.first.second, -1);
      } else {
        ans[v.second] = get(1, 1, n, 1, v.first.second - 1);
      }
    }
    for (auto v : it.second) {
      if (v.first.first == 1) {
        upd(1, 1, n, v.first.second, -1);
      } else if (v.first.first == 2) {
        upd(1, 1, n, v.first.second, 1);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (ans[i] > -1) cout << ans[i] << endl;
  }
}
int main() {
  int tt = 1;
  while (tt--) {
    solve();
    cout << '\n';
  }
}
