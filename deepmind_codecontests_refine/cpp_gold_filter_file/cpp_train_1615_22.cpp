#include <bits/stdc++.h>
using namespace std;
struct edge {
  int x, y;
};
int n, m, x, y;
edge a[200005], b[200005];
vector<int> adj[200005];
bool infected[200005];
int d[200005], subt[200005], num;
set<int> s;
vector<int> v;
void dfs(int x, int p, int dep) {
  if (infected[x]) subt[x] = 1;
  d[x] = dep;
  for (int i = 0; i < adj[x].size(); i++) {
    if (adj[x][i] == p) continue;
    dfs(adj[x][i], x, dep + 1);
    subt[x] += subt[adj[x][i]];
  }
}
void rebuild() {
  for (int i = 1; i <= n; i++) adj[i].clear();
  for (int i = 0; i < num; i++) {
    x = b[i].x;
    y = b[i].y;
    s.insert(x);
    s.insert(y);
  }
  for (auto it = s.begin(); it != s.end(); it++) v.push_back(*it);
  for (int i = 0; i < num; i++) {
    x = b[i].x;
    y = b[i].y;
    x = (int)(lower_bound(v.begin(), v.end(), x) - v.begin()) + 1;
    y = (int)(lower_bound(v.begin(), v.end(), y) - v.begin()) + 1;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
}
void diam(int x, int p, int dep) {
  d[x] = dep;
  for (int i = 0; i < adj[x].size(); i++) {
    if (adj[x][i] == p) continue;
    dfs(adj[x][i], x, dep + 1);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    adj[a[i].x].push_back(a[i].y);
    adj[a[i].y].push_back(a[i].x);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &x);
    infected[x] = true;
  }
  if (m == 1) {
    int start = 0;
    for (int i = 1; i <= n; i++)
      if (infected[i]) start = i;
    cout << start << endl << 0 << endl;
    return 0;
  }
  dfs(1, 1, 0);
  for (int i = 0; i < n - 1; i++) {
    x = a[i].x;
    y = a[i].y;
    if (d[x] < d[y]) swap(x, y);
    if (subt[x] == 0 || subt[x] == m) continue;
    b[num].x = x;
    b[num].y = y;
    num++;
  }
  int ans = num * 2;
  rebuild();
  memset(d, 0, sizeof(d));
  diam(1, 1, 0);
  int maxlvl = 0;
  for (int i = 1; i <= n; i++)
    if (d[i] > maxlvl) maxlvl = d[i];
  int f;
  for (int i = 1; i <= n; i++)
    if (d[i] == maxlvl) {
      f = i;
      break;
    }
  memset(d, 0, sizeof(d));
  diam(f, f, 0);
  maxlvl = 0;
  for (int i = 1; i <= n; i++)
    if (d[i] > maxlvl) maxlvl = d[i];
  int g;
  for (int i = 1; i <= n; i++)
    if (d[i] == maxlvl) {
      g = i;
      break;
    }
  f = min(f, g);
  ans -= maxlvl;
  cout << v[f - 1] << endl << ans << endl;
}
