#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 5e5 + 5;
const int base = 300;
int n, m, t, ans, k, a[N], tong, b[N], d[N];
pair<int, int> st[N * 4];
void build(int id, int l, int r) {
  if (l == r) {
    st[id].first = 0;
    st[id].second = l;
    return;
  }
  int mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);
  st[id] = max(st[id * 2], st[id * 2 + 1]);
}
void update(int id, int l, int r, int pos, int val) {
  if (l == r) {
    st[id].first = val;
    return;
  }
  int mid = (l + r) / 2;
  if (mid >= pos)
    update(id * 2, l, mid, pos, val);
  else
    update(id * 2 + 1, mid + 1, r, pos, val);
  st[id] = max(st[id * 2], st[id * 2 + 1]);
}
pair<int, int> get(int id, int l, int r, int u, int v) {
  if (u <= l && r <= v) return st[id];
  if (u > r || l > v || u > v) return {-1, -1};
  int mid = (l + r) / 2;
  return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
void dfs(int u) {
  if (get(1, 1, n, u, u).first == -1) return;
  update(1, 1, n, u, -1);
  if (b[u] <= n) dfs(b[u]);
  while (true) {
    pair<int, int> v = get(1, 1, n, 1, a[u] - 1);
    if (v.first <= u) break;
    dfs(v.second);
  }
  d[u] = ++t;
}
void sol() {
  cin >> n;
  fill_n(b, n + 2, n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > 0)
      b[a[i]] = i;
    else
      a[i] = n + 1;
  }
  build(1, 1, n);
  for (int i = 1; i <= n; i++) update(1, 1, n, i, b[i]);
  for (int i = 1; i <= n; i++) {
    if (get(1, 1, n, i, i).first >= 0) dfs(i);
  }
  for (int i = 1; i <= n; i++) cout << d[i] << " ";
}
int main() {
  if (fopen("slingshot"
            ".in",
            "r")) {
    freopen(
        "slingshot"
        ".in",
        "r", stdin);
    freopen(
        "slingshot"
        ".out",
        "w", stdout);
  }
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int ntest = 1;
  while (ntest-- > 0) sol();
}
