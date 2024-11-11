#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, s, b, c, d;
struct Edge {
  int to;
  int nex;
} e[1000005 << 1];
int head[1005], tot;
void add(int u, int v) {
  e[tot].to = v;
  e[tot].nex = head[u];
  head[u] = tot++;
}
vector<int> v[1005];
int sa[1005], sf[1005], sx[1005];
int dis[1005];
void bfs(int x) {
  queue<int> q;
  memset(dis, -1, sizeof(dis));
  dis[x] = 0;
  q.push(x);
  while (q.size() > 0) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < v[u].size(); i++) {
      int to = v[u][i];
      if (dis[to] == -1) {
        dis[to] = dis[u] + 1;
        q.push(to);
      }
    }
  }
}
bool vis[1005];
int match[1005];
bool dfs(int x) {
  for (int i = head[x]; i != -1; i = e[i].nex) {
    int y = e[i].to;
    if (!vis[y]) {
      vis[y] = 1;
      if (!match[y] || dfs(match[y])) {
        match[y] = x;
        return true;
      }
    }
  }
  return false;
}
int hungry() {
  int ans = 0;
  for (int i = 1; i <= b; i++) {
    memset(vis, 0, sizeof vis);
    if (dfs(i)) ans++;
  }
  return ans;
}
int main() {
  memset(head, -1, sizeof head);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  cin >> s >> b >> c >> d;
  for (int i = 1; i <= s; i++) {
    scanf("%d%d%d", &sx[i], &sa[i], &sf[i]);
  }
  for (int i = 1; i <= b; i++) {
    scanf("%d%d", &x, &y);
    bfs(x);
    for (int j = 1; j <= s; j++) {
      if (dis[sx[j]] != -1 && dis[sx[j]] <= sf[j] && sa[j] >= y) add(i, j);
    }
  }
  long long res = 1ll * c * hungry();
  long long ans = 1ll * s * d;
  ans = min(res, ans);
  cout << ans << endl;
}
