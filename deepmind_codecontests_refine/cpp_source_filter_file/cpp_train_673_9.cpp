#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > one;
vector<int> g[100010], path, binary;
int vis[100010], up[100010], down[100010], level[100010], p[100010][20];
long long int two[1000010];
int n, m;
void dfs(int node, int parent = 1, int l = 1) {
  vis[node] = 1;
  level[node] = l;
  p[node][0] = parent;
  for (int i = 0; i < g[node].size(); i++) {
    if (vis[g[node][i]]) continue;
    dfs(g[node][i], node, l + 1);
  }
}
int findParent(int a, int b) {
  if (level[a] > level[b]) {
    int c = a;
    a = b;
    b = c;
  }
  int dif = level[b] - level[a];
  binary.clear();
  while (dif) {
    binary.push_back(dif % 2);
    dif /= 2;
  }
  for (int i = binary.size() - 1; i >= 0; i--) {
    if (binary[i]) b = p[b][i];
  }
  if (a == b) return a;
  for (int i = 17; i >= 0; i--) {
    if (p[a][i] == p[b][i]) continue;
    a = p[a][i];
    b = p[b][i];
  }
  return p[a][0];
}
void sum(int node, int parent = -1) {
  vis[node] = 1;
  for (int i = 0; i < g[node].size(); i++) {
    if (vis[g[node][i]]) continue;
    sum(g[node][i], node);
  }
  if (parent != -1) {
    up[parent] += up[node];
    down[parent] += down[node];
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    g[a].push_back(b);
    g[b].push_back(a);
    if (c) one.push_back(make_pair(a, b));
  }
  two[0] = 1;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int a;
    scanf("%d", &a);
    path.push_back(a);
    two[i] = (two[i - 1] * 2) % 1000000007;
  }
  dfs(1);
  for (int i = 1; i <= 17; i++) {
    for (int j = 1; j <= n; j++) {
      p[j][i] = p[p[j][i - 1]][i - 1];
    }
  }
  int before = 1;
  for (int i = 0; i < path.size(); i++) {
    int now = path[i];
    int parent = findParent(before, now);
    up[before]++;
    down[now]++;
    up[parent]--;
    down[parent]--;
    before = now;
  }
  memset(vis, 0, sizeof vis);
  sum(1);
  long long int ans = 0;
  for (int i = 0; i < one.size(); i++) {
    int a = one[i].first;
    int b = one[i].second;
    if (level[a] < level[b]) {
      ans = (ans + two[down[b]]) % 1000000007;
      ans--;
      if (ans < 0) ans += 1000000007;
    } else {
      ans = (ans + two[up[a]]) % 1000000007;
      ans--;
      if (ans < 0) ans += 1000000007;
    }
  }
  printf("%lld", ans);
  return 0;
}
