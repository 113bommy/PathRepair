#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
struct node {
  int dist;
  long long c;
  bool operator<(const node &temp) const {
    if (c == temp.c) return dist > temp.dist;
    return c < temp.c;
  }
};
set<node> heap[301000];
set<node>::iterator it;
vector<node> g[301000];
node now;
int n, m, u, v, c, dist[301000];
vector<int> adj[300100];
long long ans, dp[301000], ad[301000], sum, nw[301000];
void dfs(int id, int pa) {
  int i, j, s, p, q, ip;
  for (i = 0; i < adj[id].size(); i++) {
    ip = adj[id][i];
    if (ip == pa) continue;
    dist[ip] = dist[id] + 1;
    dfs(ip, id);
  }
}
void solve(int id, int pa) {
  int i, j, s, p, q, ip, la = -1, ax = 0;
  dp[id] = 0;
  for (i = 0; i < adj[id].size(); i++) {
    ip = adj[id][i];
    if (ip == pa) continue;
    solve(ip, id);
    while (heap[ip].size() != 0) {
      it = heap[ip].begin();
      if (it->dist > dist[id])
        heap[ip].erase(*it);
      else
        break;
    }
    if (heap[ip].size() == 0) {
      puts("-1");
      exit(0);
    }
    if (ax < heap[ip].size()) {
      ax = heap[ip].size();
      la = ip;
    }
    it = heap[ip].begin();
    nw[ip] = it->c + ad[ip];
    dp[id] += nw[ip];
  }
  if (ax > 0) {
    ad[id] = ad[la] + dp[id] - nw[la];
    swap(heap[id], heap[la]);
  }
  for (i = 0; i < adj[id].size(); i++) {
    ip = adj[id][i];
    if (ip == pa || ip == la) continue;
    while (heap[ip].size() != 0) {
      it = heap[ip].begin();
      now = *it;
      now.c = now.c + ad[ip] + dp[id] - nw[ip] - ad[id];
      heap[id].insert(now);
      heap[ip].erase(*it);
    }
  }
  for (i = 0; i < g[id].size(); i++) {
    now = g[id][i];
    now.c = now.c + dp[id] - ad[id];
    heap[id].insert(now);
  }
}
int main() {
  int i, j, s, p, q;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) adj[i].clear();
  for (i = 0; i < n - 1; i++) {
    scanf("%d%d", &u, &v);
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dist[0] = 0;
  dfs(0, -1);
  for (i = 0; i < m; i++) {
    scanf("%d%d%d", &u, &v, &c);
    u--;
    v--;
    now.dist = dist[v];
    now.c = c;
    g[u].push_back(now);
  }
  memset(ad, 0, sizeof(ad));
  solve(0, -1);
  ans = inf;
  printf("%I64d\n", dp[0]);
  return 0;
}
