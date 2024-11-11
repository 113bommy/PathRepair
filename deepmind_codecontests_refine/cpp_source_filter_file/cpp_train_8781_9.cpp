#include <bits/stdc++.h>
const int maxn = 200 + 10;
const int maxm = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const double eps = 1e-7;
using namespace std;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char p[maxn];
bool vis[maxn];
int n, s, t, dis[maxn], pre[maxn], last[maxn], flow[maxn], maxflow, mincost,
    tot[26];
struct Edge {
  int to, next, dis, flow;
} edge[maxm];
int head[maxn], cnt;
queue<int> q;
void add(int u, int v, int flow, int dis) {
  ++cnt;
  edge[cnt].to = v;
  edge[cnt].flow = flow;
  edge[cnt].dis = dis;
  edge[cnt].next = head[u];
  head[u] = cnt;
}
bool spfa() {
  memset(dis, inf, sizeof(dis));
  memset(flow, inf, sizeof(flow));
  memset(vis, 0, sizeof(vis));
  q.push(s);
  vis[s] = 1;
  dis[s] = 0;
  pre[t] = -1;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    vis[now] = 0;
    for (int i = head[now]; i != -1; i = edge[i].next) {
      int v = edge[i].to;
      if (edge[i].flow > 0 && dis[v] > dis[now] + edge[i].dis) {
        dis[v] = dis[now] + edge[i].dis;
        pre[v] = now;
        last[v] = i;
        flow[v] = min(flow[now], edge[i].flow);
        if (!vis[v]) {
          q.push(v);
          vis[v] = 1;
        }
      }
    }
  }
  return pre[t] != -1;
}
void MCMF() {
  while (spfa()) {
    int now = t;
    maxflow += flow[t];
    mincost += flow[t] * dis[t];
    while (now != s) {
      edge[last[now]].flow -= flow[t];
      edge[last[now] ^ 1].flow += flow[t];
      now = pre[now];
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  memset(head, -1, sizeof(head));
  cnt = -1;
  cin >> p + 1 >> n;
  s = 100;
  t = 101;
  for (int i = 1; i <= n; i++) {
    int x;
    char tmp[maxn];
    cin >> tmp + 1 >> x;
    add(s, i, x, i);
    add(i, s, 0, -i);
    memset(tot, 0, sizeof tot);
    for (int j = 1; j <= strlen(tmp + 1); j++) tot[tmp[j] - 'a']++;
    for (int j = 0; j < 26; j++)
      if (tot[j]) add(i, n + j + 1, tot[j], 0), add(n + j + 1, i, 0, 0);
  }
  memset(tot, 0, sizeof tot);
  for (int i = 1; i <= strlen(p + 1); i++) tot[p[i] - 'a']++;
  for (int j = 0; j < 26; j++)
    if (tot[j]) add(n + j + 1, t, tot[j], 0), add(t, n + j + 1, 0, 0);
  MCMF();
  if (maxflow == strlen(p + 1))
    cout << mincost;
  else
    cout << -1;
  return ~~(0 - 0);
}
