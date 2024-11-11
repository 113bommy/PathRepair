#include <bits/stdc++.h>
using namespace std;
const int N = 3 * 1e5 + 5;
int v[N], n, m;
vector<pair<int, int> > e[N];
vector<int> ans;
bool vis[N], e_vis[N];
void dfs(int u, int e_id) {
  vis[u] = true;
  bool flag = false;
  int len = e[u].size();
  for (int i = 0; i < e[u].size(); i++) {
    pair<int, int> p = e[u][i];
    if (vis[p.first]) continue;
    dfs(p.first, p.second);
    if (e_vis[p.second]) flag = !flag;
  }
  if (v[u] == -1 || flag == v[u]) return;
  if (e_id != -1) {
    e_vis[e_id] = true;
    ans.push_back(e_id);
  }
}
int main() {
  cin >> n >> m;
  int st = -1, sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    if (st == -1 && v[i] == -1) st = i;
    if (v[i] != -1) sum += v[i];
  }
  for (int i = 1; i <= m; i++) {
    int f, t;
    scanf("%d%d", &f, &t);
    e[f].push_back(make_pair(t, i));
    e[t].push_back(make_pair(f, i));
  }
  if (st == -1 && sum & 1) {
    puts("-1");
    return 0;
  }
  if (st == -1)
    dfs(1, -1);
  else
    dfs(st, -1);
  int len = ans.size();
  sort(ans.begin(), ans.end());
  printf("%d\n", len);
  for (int i = 0; i < len; i++) printf("%d\n", ans[i]);
  return 0;
}
