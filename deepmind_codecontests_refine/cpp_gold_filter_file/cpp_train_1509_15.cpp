#include <bits/stdc++.h>
using namespace std;
const int nsz = 2e3, msz = 1e5;
;
const long long inf = 0x3f3f3f3f3f3f3f3f;
bool vis[nsz + 5];
int n, m, s, t, w[nsz + 5];
int es, hd[nsz + 5];
long long suf[nsz + 5][nsz + 5], cnt[nsz + 5][nsz + 5], dis[2][nsz + 5],
    dp[nsz + 5][nsz + 5][2];
struct edge {
  int nxt, to, w;
  edge(int nxt = 0, int to = 0, int w = 0) {
    this->nxt = nxt, this->to = to, this->w = w;
  }
};
edge e[2 * msz + 5];
void inline link(int u, int v, int w) {
  e[++es] = edge(hd[u], v, w), hd[u] = es;
  e[++es] = edge(hd[v], u, w), hd[v] = es;
}
void inline dijkstra(int s, long long dis[]) {
  fill(vis + 1, vis + n + 1, 0);
  fill(dis + 1, dis + n + 1, inf);
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      q;
  for (q.push(make_pair(dis[s] = 0, s)); q.size();) {
    int u = q.top().second;
    q.pop();
    vis[u] = 1;
    for (int i = hd[u]; i; i = e[i].nxt) {
      int v = e[i].to, w = e[i].w;
      if (vis[v] || dis[v] <= dis[u] + w) continue;
      q.push(make_pair(dis[v] = dis[u] + w, v));
    }
  }
}
void inline discrete(long long a[], int sz) {
  int cnt = 0;
  map<long long, int> to;
  for (int i = 1; i <= sz; ++i) {
    to[a[i]] = 0;
  }
  for (__typeof(to.begin()) it = to.begin(); it != to.end(); ++it) {
    it->second = ++cnt;
  }
  for (int i = 1; i <= sz; ++i) {
    a[i] = to[a[i]];
  }
}
long long inline qry(long long a[][nsz + 5], int x1, int y1, int x2, int y2) {
  return a[x1][y1] - a[x1][y2 + 1] - a[x2 + 1][y1] + a[x2 + 1][y2 + 1];
}
void inline solve() {
  dijkstra(s, dis[0]), dijkstra(t, dis[1]);
  discrete(dis[0], n), discrete(dis[1], n);
  for (int u = 1; u <= n; ++u) {
    suf[dis[0][u]][dis[1][u]] += w[u];
    ++cnt[dis[0][u]][dis[1][u]];
  }
  for (int i = n; i >= 1; --i) {
    for (int j = n; j >= 1; --j) {
      suf[i][j] += suf[i + 1][j] + suf[i][j + 1] - suf[i + 1][j + 1];
      cnt[i][j] += cnt[i + 1][j] + cnt[i][j + 1] - cnt[i + 1][j + 1];
    }
  }
  for (int i = n; i >= 1; --i) {
    for (int j = n; j >= 1; --j) {
      dp[i][j][0] =
          (qry(cnt, i, j, i, n) ? max(dp[i + 1][j][0], -dp[i + 1][j][1])
                                : dp[i + 1][j][0]) +
          qry(suf, i, j, i, n);
      dp[i][j][1] =
          (qry(cnt, i, j, n, j) ? max(-dp[i][j + 1][0], dp[i][j + 1][1])
                                : dp[i][j + 1][1]) +
          qry(suf, i, j, n, j);
    }
  }
}
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &t);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &w[i]);
  }
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    link(u, v, w);
  }
  solve();
  printf(dp[1][1][0] == 0 ? "Flowers"
                          : (dp[1][1][0] > 0 ? "Break a heart" : "Cry"));
}
