#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
inline void upd(int &n, int k) {
  n += k;
  if (n >= 314000000) n = 314000000;
}
int zhu[maxn], qian[maxn];
vector<int> V[maxn];
int d[maxn], dd[maxn];
int is[maxn], vis[maxn], can[maxn];
vector<int> fang[maxn];
int first[maxn], nxt[maxn << 1], vv[maxn << 1];
int dp1[maxn];
int dp[maxn];
queue<int> q;
struct NN {
  int ind, dp1;
  NN(int n = 0, int d = 0) {
    ind = n;
    dp1 = d;
  }
};
bool operator<(NN a, NN b) { return a.dp1 > b.dp1; }
priority_queue<NN> qq;
void topo1(int n, int m) {
  int i, j, e, u, M = 2100, v;
  for (i = 1; i <= n; i++) dp1[i] = 314000000;
  for (i = 1; i <= n; i++)
    if (can[i]) {
      M = 314000000;
      for (j = 0; j < fang[i].size(); j++)
        if (V[fang[i][j]].size() == 0) M = min(M, qian[fang[i][j]]);
      qq.push(NN(i, M));
      dp1[i] = M;
    }
  while (!qq.empty()) {
    u = qq.top().ind;
    qq.pop();
    if (is[u]) continue;
    is[u] = 1;
    int f;
    for (e = first[u]; e; e = nxt[e]) {
      d[vv[e]]--;
      if (d[vv[e]] == 0) {
        v = zhu[vv[e]];
        M = 0;
        f = vv[e];
        for (j = 0; j < V[f].size(); j++) upd(M, dp1[V[f][j]]);
        upd(M, qian[f]);
        if (dp1[v] > M) dp1[v] = M;
        qq.push(NN(zhu[vv[e]], dp1[v]));
      }
    }
  }
}
void topo2(int n, int m) {
  int i, j, u, v, e;
  memset(vis, 0, sizeof(vis));
  int M = 0;
  for (i = 1; i <= n; i++) {
    M = 0;
    for (j = 0; j < fang[i].size(); j++)
      if (V[fang[i][j]].size())
        break;
      else
        M = max(M, qian[fang[i][j]]);
    if (j < fang[i].size()) continue;
    q.push(i);
    dp[i] = M;
  }
  for (i = 1; i <= m; i++) d[i] = V[i].size();
  int f;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (e = first[u]; e; e = nxt[e]) {
      d[vv[e]]--;
      if (d[vv[e]] == 0) {
        dd[zhu[vv[e]]]--;
        if (dd[zhu[vv[e]]] == 0) {
          q.push(zhu[vv[e]]);
          v = zhu[vv[e]];
          for (i = 0; i < fang[u].size(); i++) {
            M = 0;
            f = fang[u][i];
            for (j = 0; j < V[f].size(); j++) upd(M, dp[V[f][j]]);
            upd(M, qian[f]);
            if (dp[v] < M) dp[v] = M;
          }
        }
      }
    }
  }
}
void add(int u, int v, int &e) { nxt[e] = first[u], vv[e] = v, first[u] = e++; }
int main() {
  int i, j, k, n, m;
  cin >> m >> n;
  int e = 2;
  for (i = 1; i <= m; i++) {
    scanf("%d", &zhu[i]);
    scanf("%d", &k);
    fang[zhu[i]].push_back(i);
    while (k--) {
      scanf("%d", &j);
      if (j == -1)
        qian[i]++;
      else
        V[i].push_back(j), add(j, i, e);
    }
    d[i] = V[i].size();
    if (V[i].size() == 0)
      can[zhu[i]] = 1;
    else
      dd[zhu[i]]++;
  }
  topo1(n, m);
  memset(first, 0, sizeof(first));
  for (i = 1; i <= n; i++) fang[i].clear();
  e = 2;
  memset(dd, 0, sizeof(dd));
  for (i = 1; i <= m; i++)
    if (is[zhu[i]]) {
      for (j = 0; j < V[i].size(); j++)
        if (!is[V[i][j]]) break;
      if (j < V[i].size()) continue;
      for (j = 0; j < V[i].size(); j++) add(V[i][j], i, e);
      fang[zhu[i]].push_back(i);
      if (V[i].size() == 0)
        can[zhu[i]] = 1;
      else
        dd[zhu[i]]++;
    }
  topo2(n, m);
  for (i = 1; i <= n; i++) {
    if (!is[i])
      puts("-1 -1");
    else if (!vis[i])
      printf("%d -2\n", dp1[i]);
    else
      printf("%d %d\n", dp1[i], dp[i]);
  }
}
