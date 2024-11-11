#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int n, m, d[10010], g, r, dist[10010], ans;
bool vis[10010][1010];
vector<int> v;
queue<int> q;
void dfs(int pos, int lft) {
  if (vis[pos][lft]) return;
  vis[pos][lft] = true;
  if (lft == 0) {
    v.push_back(pos);
    return;
  }
  if (pos - 1 >= 0 && lft - (d[pos] - d[pos - 1]) >= 0)
    dfs(pos - 1, lft - (d[pos] - d[pos - 1]));
  if (pos + 1 < m && lft - (d[pos + 1] - d[pos]) >= 0)
    dfs(pos + 1, lft - (d[pos + 1] - d[pos]));
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) scanf("%d", &d[i]);
  sort(d, d + m);
  cin >> g >> r;
  for (int i = 0; i < 10005; i++) dist[i] = 2e9;
  dist[0] = 0;
  vis[0][0] = true;
  q.push(0);
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    v.clear();
    dfs(i, g);
    for (int j = 0; j < v.size(); j++) {
      dist[v[j]] = dist[i] + g + r;
      q.push(v[j]);
    }
  }
  ans = dist[m - 1] - r;
  for (int i = 0; i < m - 1; i++)
    if (d[m - 1] - d[i] <= g) ans = min(ans, dist[i] + d[m - 1] - d[i]);
  if (ans > 1e9)
    puts("-1");
  else
    cout << ans << endl;
  return 0;
}
