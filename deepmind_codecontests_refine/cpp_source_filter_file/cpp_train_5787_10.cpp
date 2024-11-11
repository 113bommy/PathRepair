#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
vector<pair<int, int> > d;
vector<int> w, c;
void build(int l, int r, int p) {
  if (l == r) {
    d[p].first = w[l] * (100 - (c[l] % 100));
    if (!(c[l] % 100)) {
      d[p].first = inf;
    }
    d[p].second = l;
    return;
  }
  int m = (l + r) >> 1;
  build(l, m, (p << 1));
  build(m + 1, r, ((p << 1) | 1));
  d[p] = {inf, 0};
  if (d[p].first > d[(p << 1)].first) {
    d[p] = d[(p << 1)];
  }
  if (d[p].first > d[((p << 1) | 1)].first) {
    d[p] = d[((p << 1) | 1)];
  }
  return;
}
void update(int l, int r, int t, int del, int p) {
  if (l == r) {
    d[p].first = del;
    return;
  }
  int m = (l + r) >> 1;
  if (t <= m) {
    update(l, m, t, del, (p << 1));
  } else {
    update(m + 1, r, t, del, ((p << 1) | 1));
  }
  d[p] = {inf, 0};
  if (d[p].first > d[(p << 1)].first) {
    d[p] = d[(p << 1)];
  }
  if (d[p].first > d[((p << 1) | 1)].first) {
    d[p] = d[((p << 1) | 1)];
  }
  return;
}
pair<int, int> get(int l, int r, int tl, int tr, int p) {
  pair<int, int> res = {inf, 0}, pr;
  if (l == tl && r == tr) {
    return d[p];
  }
  int m = (l + r) >> 1;
  if (tl <= m) {
    pr = get(l, m, tl, min(m, tr), (p << 1));
    if (res.first > pr.first) {
      res = pr;
    }
  }
  if (tr > m) {
    pr = get(m + 1, r, max(tl, m + 1), tr, ((p << 1) | 1));
    if (res.first > pr.first) {
      res = pr;
    }
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, m;
  cin >> n >> m;
  c.resize(n);
  d.resize(4 * n, {inf, 0});
  w.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  build(0, n - 1, 1);
  int ans = 0;
  vector<bool> how(n, false);
  for (int i = 0; i < n; i++) {
    if (c[i] % 100 > m) {
      pair<int, int> f = get(0, n - 1, 0, i, 1);
      how[f.second] = true;
      ans += f.first;
      m += 100;
      update(0, n - 1, f.second, inf, 1);
    }
    m -= (c[i] % 100);
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    int y = (c[i] / 100);
    int g = (c[i] % 100);
    if (how[i]) {
      if (g) {
        y++;
        g = 0;
      }
    }
    cout << y << ' ' << g << endl;
  }
  return 0;
}
