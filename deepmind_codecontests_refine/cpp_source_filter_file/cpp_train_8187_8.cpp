#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000;
const int INF = 0x3f3f3f3f;
int head[maxn], gap[maxn], cur[maxn], dist[maxn];
int N;
struct edge {
  int u, v, w, nxt;
};
vector<edge> E;
void addedge(int u, int v, int w) {
  E.push_back({u, v, w, head[u]});
  head[u] = E.size() - 1;
  E.push_back({u, v, 0, head[v]});
  head[v] = E.size() - 1;
}
void init() {
  E.clear();
  memset(head, -1, sizeof(head));
}
void init(int t) {
  memset(gap, 0, sizeof(gap));
  gap[0] = 1;
  memset(dist, -1, sizeof(dist));
  dist[t] = 0;
  memcpy(cur, head, sizeof(head));
  queue<int> que;
  que.push(t);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int i = head[u]; i != -1; i = E[i].nxt) {
      int v = E[i].v;
      if (dist[v] == -1) que.push(v), gap[dist[v] = dist[u] + 1]++;
    }
  }
}
int aug(int u, int s, int t, int mmin) {
  if (u == t) return mmin;
  int flow = 0;
  for (int i = cur[u]; i != -1; i = E[i].nxt) {
    int v = E[i].v;
    if (E[i].w && dist[u] == dist[v] + 1) {
      cur[u] = i;
      int tmp = aug(v, s, t, min(mmin, E[i].w));
      flow += tmp, mmin -= tmp, E[i].w -= tmp, E[i ^ 1].w += tmp;
      if (!mmin || dist[s] >= N) return flow;
    }
  }
  int tmpmin = N;
  for (int i = head[u]; i != -1; i = E[i].nxt)
    if (E[i].w && dist[E[i].v] < tmpmin) tmpmin = dist[E[i].v], cur[u] = i;
  if (!(--gap[dist[u]])) dist[s] = N;
  gap[dist[u] = tmpmin + 1]++;
  return flow;
}
int isap(int s, int t) {
  init(t);
  int res = 0;
  while (dist[s] < N) res += aug(s, s, t, INF);
  return res;
}
int s, t;
int degree[maxn];
int main(void) {
  init();
  int n1, n2, m;
  cin >> n1 >> n2 >> m;
  s = 0;
  t = n1 + n2 + 1;
  N = n1 + n2 + 2;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    degree[u]++;
    degree[n1 + v]++;
    addedge(u, n1 + v, 1);
  }
  int mind = INF;
  for (int i = 1; i <= n1; i++) {
    addedge(s, i, 1);
    mind = min(mind, degree[i]);
  }
  for (int i = n1 + 1; i <= n1 + n2; i++) {
    addedge(i, t, 1);
    mind = min(mind, degree[i]);
  }
  for (int k = 0; k <= mind; k++) {
    if (k == 0) {
      cout << 0 << endl;
      continue;
    }
    for (int i = 0; i < m + n1 + n2; i++) {
      E[i * 2].w = 1;
      E[(i * 2) ^ 1].w = 0;
    }
    for (int i = m; i < m + n1; i++) {
      int e = i * 2;
      E[e].w = degree[E[e].v] - k;
    }
    for (int i = m + n1; i < m + n1 + n2; i++) {
      int e = i * 2;
      E[e].w = degree[E[e].u] - k;
    }
    int cnter = m - isap(s, t);
    printf("%d", cnter);
    for (int i = 0; i < m; i++) {
      int e = i * 2;
      if (E[e].w) printf(" %d", i + 1);
    }
    cout << endl;
  }
}
