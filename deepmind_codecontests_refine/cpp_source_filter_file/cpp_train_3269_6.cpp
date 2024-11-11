#include <bits/stdc++.h>
using namespace std;
int n, d, m;
int a[100005];
vector<int> V[100005];
int D[100005][2];
bool vis[100005];
bool inef[100005];
void dfs(int idx, int l, int k) {
  D[idx][k] = l;
  vis[idx] = 1;
  int sz = V[idx].size();
  for (int i = 0; i < sz; i++)
    if (!vis[V[idx][i]]) dfs(V[idx][i], l + 1, k);
}
int main() {
  memset(vis, 0, sizeof vis);
  memset(inef, 0, sizeof vis);
  cin >> n >> m >> d;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    inef[a[i]] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    V[x].push_back(y);
    V[y].push_back(x);
  }
  dfs(a[0], 0, 0);
  int mn = 0;
  int ans = 0;
  int idx;
  for (int i = 0; i < m; i++) {
    if (D[a[i]][0] >= mn) {
      mn = D[a[i]][0];
      idx = a[i];
    }
  }
  memset(vis, 0, sizeof vis);
  mn = 0;
  dfs(idx, 0, 1);
  idx = 0;
  for (int i = 0; i < m; i++) {
    if (D[a[i]][1] >= mn) {
      mn = D[a[i]][1];
      idx = a[i];
    }
  }
  memset(vis, 0, sizeof vis);
  dfs(idx, 0, 0);
  for (int i = 1; i <= n; i++)
    if (D[i][0] <= d && D[i][1] <= d) ans = i;
  cout << ans << endl;
  return 0;
}
