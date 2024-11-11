#include <bits/stdc++.h>
using namespace std;
vector<int> adj[500006];
vector<int> depth[500006];
int par[500006];
int ancestor[500006][20];
int cnt[500006][27];
int vis[500006];
int height[500006];
int prev_2[500006];
int idx[500006];
int mp[500006];
char s[500006];
void bfs() {
  queue<pair<int, int> > q;
  q.push(make_pair(1, 1));
  vis[1] = 1;
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    int u = p.first;
    int h = p.second;
    depth[h].push_back(u);
    height[u] = h;
    idx[u] = int(depth[p.second].size()) - 1;
    for (int i = 0; i < adj[u].size(); i++) {
      if (!vis[adj[u][i]]) {
        vis[adj[u][i]] = 1;
        q.push(make_pair(adj[u][i], h + 1));
      }
    }
  }
}
void pre_process(int n) {
  int i, j, h;
  for (i = 1; i <= n; i++) {
    ancestor[i][0] = par[i];
  }
  for (h = 2, j = 1; h <= n; h *= 2, j++) {
    for (i = 1; i <= n; i++)
      ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
  }
  int val = 2;
  j = 0;
  for (i = 1; i <= n; i++) {
    if (i == val) {
      val *= 2;
      j++;
    }
    prev_2[i] = j;
  }
}
int find_par(int x, int h) {
  int hx = height[x];
  if (h < 0) return -1;
  if (h == 0) return x;
  return find_par(ancestor[x][prev_2[h]], h - (1 << prev_2[h]));
}
int bs(int h, int x, bool f) {
  int hx = height[x];
  if (h >= hx) return -1;
  int lo = 0;
  int hi = int(depth[h].size()) - 1;
  int ans;
  if (f)
    ans = 1000000000;
  else
    ans = -1;
  while (hi >= lo) {
    int mid = (hi + lo) / 2;
    int u = depth[h][mid];
    int v = find_par(u, h - hx);
    int i = idx[v];
    if (i > idx[x])
      hi = mid - 1;
    else if (i < idx[x])
      lo = mid + 1;
    else if (f) {
      hi = mid - 1;
      ans = min(ans, mid);
    } else {
      lo = mid + 1;
      ans = max(ans, mid);
    }
  }
  if (ans == 1000000000 || ans == -1) return -1;
  return depth[h][ans];
}
bool solve(int l, int r) {
  int i, tot = 0;
  for (i = 0; i < 26; i++) {
    if ((cnt[r][i] - cnt[l - 1][i]) & 1) tot++;
  }
  return (tot < 2);
}
int main() {
  int n, m, i, j, x, y;
  scanf("%d %d", &n, &m);
  for (i = 2; i <= n; i++) {
    scanf("%d", &x);
    par[i] = x;
    adj[i].push_back(x);
    adj[x].push_back(i);
  }
  scanf("%s", s);
  bfs();
  pre_process(n);
  x = 1;
  int k;
  for (i = 1; i <= n; i++) {
    for (j = 0; j < int(depth[i].size()); j++) {
      mp[depth[i][j]] = x;
      for (k = 0; k < 26; k++)
        cnt[x][k] = cnt[x - 1][k] + (s[depth[i][j] - 1] - 'a' == k);
      x++;
    }
  }
  while (m--) {
    scanf("%d %d", &x, &y);
    int l = bs(y, x, true);
    int r = bs(y, x, false);
    bool ans;
    if (l == -1 || r == -1)
      ans = true;
    else
      ans = solve(mp[l], mp[r]);
    if (ans)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
