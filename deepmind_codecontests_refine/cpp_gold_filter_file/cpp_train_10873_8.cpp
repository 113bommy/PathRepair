#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 10, MAX = 2e5 + 1e4, MOD = 1e9 + 7, MAXL = 25;
void OUT(long double o, int x) {
  cout << fixed << setprecision(x) << o;
  return;
}
long long a[MAX], seg[4 * MAX], lazy[4 * MAX];
set<pair<pair<int, int>, int> > st;
void shift(int id, int b, int e) {
  lazy[id * 2] += lazy[id];
  lazy[id * 2 + 1] += lazy[id];
  int m = (b + e) / 2;
  seg[id * 2] += (m - b) * lazy[id];
  seg[id * 2 + 1] += (e - m) * lazy[id];
  lazy[id] = 0;
}
void upd(int id, int b, int e, int l, int r, long long x) {
  if (e <= l || r <= b) return;
  if (l <= b && e <= r) {
    seg[id] += (e - b) * x;
    lazy[id] += x;
    return;
  }
  int m = (b + e) / 2;
  shift(id, b, e);
  upd(id * 2, b, m, l, r, x);
  upd(id * 2 + 1, m, e, l, r, x);
  seg[id] = (seg[id * 2] + seg[id * 2 + 1]);
}
long long g(int id, int b, int e, int l, int r) {
  if (e <= l || r <= b) return 0;
  if (l <= b && e <= r) return seg[id];
  int m = (b + e) / 2;
  shift(id, b, e);
  return g(id * 2, b, m, l, r) + g(id * 2 + 1, m, e, l, r);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n + 1; i++) st.insert({{i, i}, i});
  while (m--) {
    int t, l, r, x;
    cin >> t >> l >> r;
    if (t == 1) {
      cin >> x;
      vector<pair<pair<int, int>, int> > v;
      auto it = st.lower_bound({{l, -INF}, -INF});
      it--;
      while (1) {
        pair<pair<int, int>, int> z = *it;
        if (z.first.first <= r)
          v.push_back(z);
        else
          break;
        it++;
      }
      pair<pair<int, int>, int> p = v[0];
      if (p.first.second >= l) {
        upd(1, 1, n + 1, l, min(r, p.first.second) + 1, abs(x - p.second));
        st.insert({{p.first.first, l - 1}, p.second});
        st.erase(p);
      }
      if (p.first.second > r) st.insert({{r + 1, p.first.second}, p.second});
      for (int i = 1; i < int(v.size()) - 1; i++) {
        p = v[i];
        upd(1, 1, n + 1, p.first.first, p.first.second + 1, abs(p.second - x));
        st.erase(p);
      }
      if (v.size() != 1) {
        p = v.back();
        st.erase(p);
        upd(1, 1, n + 1, p.first.first, r + 1, abs(p.second - x));
        if (p.first.second > r) st.insert({{r + 1, p.first.second}, p.second});
      }
      st.insert({{l, r}, x});
    } else
      cout << g(1, 1, n + 1, l, r + 1) << "\n";
  }
  return 0;
}
