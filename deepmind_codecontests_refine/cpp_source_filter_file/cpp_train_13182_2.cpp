#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100, mod = 1e9 + 7, sz = 400, inf = 1e9;
vector<int> t[4 * N], mn[4 * N];
int b[N], a[N], p[N], h[N], left228[N], right228[N];
bool cmp(int i, int j) { return h[i] < h[j]; }
void build(int v, int l, int r) {
  if (l == r - 1) {
    t[v].push_back(l);
    mn[v].push_back(a[l]);
  } else {
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m, r);
    merge((t[2 * v]).begin(), (t[2 * v]).end(), (t[2 * v + 1]).begin(),
          (t[2 * v + 1]).end(), back_inserter(t[v]), cmp);
    for (auto u : t[v]) {
      if (mn[v].empty())
        mn[v].push_back(a[u]);
      else
        mn[v].push_back(min(a[u], mn[v].back()));
    }
  }
}
int res(int v, int k) {
  if (h[t[v][0]] > k) return 0;
  int l = 0, r = t[v].size(), m;
  while (r - l > 1) {
    m = (l + r) / 2;
    if (h[t[v][m]] > k)
      r = m;
    else
      l = m;
  }
  return mn[v][l];
}
int get(int v, int l, int r, int vl, int vr, int k) {
  if (l >= vr || vl >= r) return inf;
  if (vl <= l && r <= vr) {
    return res(v, k);
  }
  int m = (l + r) / 2;
  return min(get(2 * v, l, m, vl, vr, k), get(2 * v + 1, m, r, vl, vr, k));
}
vector<int> v[N], o;
void dfs(int x, int pr) {
  p[x] = o.size();
  a[p[x]] = b[x];
  left228[p[x]] = o.size();
  if (pr != -1) {
    h[p[x]] = h[p[pr]] + 1;
  }
  o.push_back(x);
  for (auto u : v[x]) {
    if (u != pr) dfs(u, x);
  }
  right228[p[x]] = o.size() - 1;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, r;
  cin >> n >> r;
  r--;
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n - 1; i++) {
    int f, t;
    cin >> f >> t;
    f--, t--;
    v[f].push_back(t);
    v[t].push_back(f);
  }
  dfs(r, -1);
  build(1, 0, n);
  int m, last = 0;
  cin >> m;
  while (m--) {
    int p1, q1;
    cin >> p1 >> q1;
    int x = p[(p1 + last) % n], k = (q1 + last) % n;
    last = get(1, 0, n, left228[x], right228[x] + 1, h[x] + k);
    cout << last << endl;
  }
}
