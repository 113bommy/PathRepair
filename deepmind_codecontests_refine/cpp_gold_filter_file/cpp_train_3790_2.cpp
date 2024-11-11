#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[100005], dpup[100005], dpdn[100005], ans;
vector<int> gr[100005];
void dfs(int x, int p) {
  if (a[x]) {
    dpup[x] = 1;
    dpdn[x] = 1;
  }
  if (dpup[p] != 0) dpup[x] = dpup[p] + 1;
  for (int i = 0; i < gr[x].size(); i++) {
    int u = gr[x][i];
    if (u == p) continue;
    dfs(u, x);
    if (dpdn[u] != 0) dpdn[x] = max(dpdn[x], dpdn[u] + 1);
  }
}
void rs(int x, int p, int mx) {
  multiset<int> ms;
  ms.insert(0);
  for (int i = 0; i < gr[x].size(); i++) {
    int u = gr[x][i];
    if (u == p) continue;
    ms.insert(dpdn[u]);
  }
  if (max(mx, max(dpup[x], dpdn[x])) - 1 <= k) ans++;
  for (int i = 0; i < gr[x].size(); i++) {
    int u = gr[x][i];
    if (u == p) continue;
    ms.erase(ms.lower_bound(dpdn[u]));
    int mmx = 0;
    if (mx) mmx = mx + 1;
    if (*--ms.end() != 0) mmx = max(mmx, (*--ms.end()) + 2);
    rs(u, x, mmx);
    ms.insert(dpdn[u]);
  }
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    gr[x].push_back(y);
    gr[y].push_back(x);
  }
  dfs(1, 0);
  rs(1, 0, 0);
  cout << ans;
}
