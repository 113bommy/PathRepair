#include <bits/stdc++.h>
using namespace std;
const int Max = 2e5 + 110;
int ti = 0, seg[4 * Max], h[Max], a[Max];
pair<int, int> t[Max];
bool mark[Max];
vector<int> g[Max];
void dfs(int v) {
  t[v].first = ti++;
  mark[v] = 1;
  for (int i = 0; i < g[v].size(); i++) {
    int u = g[v][i];
    if (!mark[u]) {
      h[u] = h[v] + 1;
      dfs(u);
    }
  }
  t[v].second = ti;
}
void add(int val, int id, int L, int R, int l, int r) {
  if (R <= l || r <= L) return;
  if (l <= L && R <= r) {
    seg[id] += val;
    return;
  }
  int mid = (L + R) / 2;
  add(val, 2 * id + 1, L, mid, l, r);
  add(val, 2 * id + 2, mid, R, l, r);
  return;
}
int get(int v, int id, int L, int R) {
  if (R - L == 1) return seg[id];
  int mid = (L + R) / 2;
  int ans;
  if (v < mid)
    ans = get(v, 2 * id + 1, L, mid);
  else
    ans = get(v, 2 * id + 2, mid, R);
  ans += seg[id];
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    int v, u;
    cin >> v >> u;
    v--;
    u--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  for (int i = 0; i < m; i++) {
    int q;
    cin >> q;
    if (q == 1) {
      int v, x;
      cin >> v >> x;
      v--;
      if (h[v] % 2) x *= -1;
      add(x, 0, 0, n, t[v].first, t[v].second);
    }
    if (q == 2) {
      int v;
      cin >> v;
      v--;
      int x = get(v, 0, 0, n);
      if (h[v] % 2)
        cout << -1 * x + a[v] << '\n';
      else
        cout << x + a[v] << '\n';
    }
  }
}
