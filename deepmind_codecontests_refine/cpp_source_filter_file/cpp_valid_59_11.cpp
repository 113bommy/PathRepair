#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e3 + 1;
vector<int> g[MAXN];
int n, m, a[MAXN], b[MAXN];
bool vis[MAXN];
long long dis[MAXN];
int pre[MAXN];
bool check(int x) {
  memset(vis, 0, sizeof(vis));
  vis[1] = 1;
  long long totb = 0;
  while (true) {
    for (int i = 1; i <= n; ++i) dis[i] = -1;
    totb = 0;
    bool ok = false;
    for (int i = 1; i <= n; ++i)
      if (vis[i]) totb += b[i];
    for (int i = 1; i <= n; ++i) ok |= !vis[i];
    if (!ok) break;
    totb += x;
    queue<int> q;
    for (int i = 1; i <= n; ++i)
      if (vis[i])
        for (auto it : g[i]) {
          if (!vis[it] && a[it] < totb && dis[it] == -1) {
            q.push(it);
            dis[it] = totb;
            pre[it] = i;
          }
        }
    ok = false;
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (auto it : g[now])
        if (it != pre[now]) {
          if (vis[it]) {
            ok = 1;
            while (!vis[now]) {
              vis[now] = 1;
              now = pre[now];
            }
            break;
          } else {
            if (dis[now] + b[now] <= a[it]) {
              continue;
            }
            if (dis[it] != -1) {
              ok = 1;
              while (!vis[now]) {
                vis[now] = 1;
                now = pre[now];
              }
              now = it;
              while (!vis[now]) {
                vis[now] = 1;
                now = pre[now];
              }
              break;
            } else {
              pre[it] = now;
              dis[it] = dis[now] + b[now];
              q.push(it);
            }
          }
        }
      if (ok) break;
    }
    if (!ok) return false;
  }
  return true;
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 2; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 2; i <= n; ++i) scanf("%d", &b[i]);
  for (int i = 1; i <= n; ++i) g[i].clear();
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long long l = 0, r = 1e9;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
