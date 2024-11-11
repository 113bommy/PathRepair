#include <bits/stdc++.h>
using namespace std;
int n, m, dis, x, y, us[100005], k[100005], h[100005], ans;
vector<int> v[100005];
pair<int, int> d[100005];
void dfs1(int x, int p) {
  d[x] = {-1, -1};
  if (!us[x]) h[x] = -1;
  for (int i = 0; i < v[x].size(); i++) {
    int V = v[x][i];
    if (V == p) continue;
    dfs1(V, x);
    if (h[V] == -1) continue;
    h[x] = max(h[x], h[V] + 1);
    if (h[V] + 1 >= d[x].first)
      d[x] = {h[V] + 1, d[x].first};
    else if (h[V] + 1 > d[x].second)
      d[x] = {d[x].first, h[V] + 1};
  }
}
void dfs2(int x, int p, int F) {
  k[x] = F;
  for (int i = 0; i < v[x].size(); i++) {
    int V = v[x][i];
    if (V == p) continue;
    int nF = F;
    if (d[x].first == h[V] + 1)
      nF = max(nF, d[x].second);
    else
      nF = max(nF, d[x].first);
    if (us[V]) nF = max(nF, 0);
    if (nF != -1) nF++;
    dfs2(V, x, nF);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> dis;
  while (m--) cin >> x, us[x] = 1;
  for (int i = 1; i < n; i++)
    cin >> x >> y, v[x].push_back(y), v[y].push_back(x);
  dfs1(1, 0);
  dfs2(1, 0, (us[1]) ? 0 : -1);
  for (int i = 1; i <= n; i++)
    if (h[i] <= dis && k[i] <= dis) ans++;
  cout << ans << endl;
  return 0;
}
