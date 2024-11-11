#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 150;
const int maxm = 5e5 + 550;
const int Inf = 0x3f3f3f3f;
int n, m, k, s;
int a[maxn];
int d[105][maxn];
int vis[maxn];
struct node {
  int u, v, nxt;
  int dist;
} edge[maxm];
struct hn {
  int s, d;
  bool operator<(const hn &b) const { return d > b.d; }
};
int head[maxn], cnt;
void init() { memset(head, -1, sizeof(head)); }
void addedge(int u, int v, int d) {
  edge[cnt] = node({u, v, head[u], d});
  head[u] = cnt++;
}
priority_queue<hn> q;
void dij(int dx, int s) {
  memset(vis, 0, sizeof(vis));
  memset(d[dx], Inf, sizeof(d[dx]));
  while (!q.empty()) q.pop();
  for (int i = head[s]; i != -1; i = edge[i].nxt) {
    int v = edge[i].v;
    d[dx][v] = 0;
    q.push(hn({v, d[dx][v]}));
  }
  while (!q.empty()) {
    hn u = q.top();
    q.pop();
    if (vis[u.s]) continue;
    vis[u.s] = 1;
    for (int i = head[u.s]; i != -1; i = edge[i].nxt) {
      int v = edge[i].v;
      if (d[dx][v] > d[dx][u.s] + edge[i].dist) {
        d[dx][v] = d[dx][u.s] + edge[i].dist;
        q.push(hn({v, d[dx][v]}));
      }
    }
  }
}
int main() {
  init();
  scanf("%d%d%d%d", &n, &m, &k, &s);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int u, v;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    addedge(u, v, 1);
    addedge(v, u, 1);
  }
  int kk;
  for (int i = 1; i <= n; i++) {
    kk = a[i] + n;
    addedge(kk, i, 0);
  }
  for (int i = 1; i <= k; i++) {
    kk = i + n;
    dij(i, kk);
  }
  for (int i = 1; i <= n; i++) {
    vector<int> vt;
    for (int j = 1; j <= k; j++) {
      vt.push_back(d[j][i]);
    }
    sort(vt.begin(), vt.end());
    long long answer = 0;
    for (int j = 0; j < s; j++) {
      answer += vt[j];
    }
    printf("%lld ", answer);
  }
  cout << endl;
  return 0;
}
