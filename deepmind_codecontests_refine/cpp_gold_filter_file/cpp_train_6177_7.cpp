#include <bits/stdc++.h>
using namespace std;
int a, s, f[100002], ds[100002], fx[100002], fx1[100002], low[100002],
    cur[100002], y, g, h, j, k, l, i, n, m;
vector<pair<int, int> > v[100002];
struct edge {
  int val;
  int a;
  int b;
  int idx;
};
edge d[100005];
bool cmp(edge a, edge b) { return a.val < b.val; }
int gpar(int i) { return ds[i] == i ? i : ds[i] = gpar(ds[i]); }
void dsu(int i1, int i2) { ds[gpar(i1)] = gpar(i2); }
void dfs(int idx, int par) {
  if (fx1[idx] == h) return;
  fx1[idx] = h;
  y++;
  cur[idx] = y;
  low[idx] = y;
  for (auto it : v[idx]) {
    if (it.second == par) continue;
    dfs(it.first, it.second);
    if (low[it.first] > cur[idx]) f[it.second] = 1;
    low[idx] = min(low[idx], low[it.first]);
  }
}
void sol(int l, int r) {
  int e, R;
  for (int i = l; i < r; i++) {
    e = gpar(d[i].a);
    R = gpar(d[i].b);
    if (e == R) {
      f[d[i].idx] = 3;
      continue;
    }
    if (fx[e] != h) {
      fx[e] = h;
      v[e].clear();
    }
    if (fx[R] != h) {
      fx[R] = h;
      v[R].clear();
    }
    v[e].push_back({R, d[i].idx});
    v[R].push_back({e, d[i].idx});
  }
  for (int i = l; i < r; i++) {
    y = 0;
    if (fx1[gpar(d[i].a)] != h) dfs(gpar(d[i].a), -1);
    dsu(d[i].a, d[i].b);
  }
}
int main() {
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    scanf("%d%d%d", &d[i].a, &d[i].b, &d[i].val);
    d[i].idx = i;
  }
  for (i = 1; i <= n; i++) ds[i] = i;
  sort(d, d + m, cmp);
  for (i = 0; i < m; i++) {
    if (d[i].val == d[l].val) continue;
    h++;
    sol(l, i);
    l = i;
  }
  h++;
  sol(l, m);
  for (i = 0; i < m; i++) {
    if (f[i] == 1) cout << "any\n";
    if (f[i] == 0) cout << "at least one\n";
    if (f[i] == 3) cout << "none\n";
  }
}
