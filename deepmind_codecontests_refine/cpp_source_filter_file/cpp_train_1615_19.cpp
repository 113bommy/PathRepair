#include <bits/stdc++.h>
using namespace std;
const int MAXN = 130000;
vector<int> tree[MAXN];
int d[MAXN];
bool mark[MAXN];
int size[MAXN];
void dfs(int p, int v) {
  size[v] = 0;
  if (mark[v] == true) size[v] = 1;
  for (int i = 0; i < tree[v].size(); i++) {
    if (tree[v][i] != p) {
      d[tree[v][i]] = d[v] + 1;
      dfs(v, tree[v][i]);
      size[v] += size[tree[v][i]];
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int m, n;
  cin >> m >> n;
  int u, v;
  for (int i = 0; i < m - 1; i++) {
    cin >> u >> v;
    u--, v--;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    cin >> u;
    mark[--u] = true;
  }
  dfs(-1, 0);
  v = -1;
  for (int i = 0; i < m; i++) {
    if (mark[i] && ((v == -1) || d[i] > d[v])) v = i;
  }
  memset(d, 0, sizeof(d));
  dfs(-1, v);
  int ans = 0, mx = 0;
  for (int i = 0; i < m; i++) {
    if (size[i] > 0 && size[i] < n) ans += 2;
    if (mark[i]) mx = max(mx, d[i]);
  }
  for (int i = 0; i < m; i++)
    if (mark[i] && d[i] == mx) {
      v = i;
      break;
    }
  cout << v + 1 << endl << ans - mx << endl;
  return 0;
}
