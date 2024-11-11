#include <bits/stdc++.h>
using namespace std;
inline void cmax(int &a, int b) { a = max(a, b); }
inline void cmin(int &a, int b) { a = min(a, b); }
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct edge {
  int to, cap, rev;
  edge(int x, int y, int z) { to = x, cap = y, rev = z; }
};
struct Max_flow {
  int Siz;
  int src, snk;
  vector<vector<edge> > G;
  vector<int> dist, seen;
  Max_flow() {
    Siz = 0;
    src = -1;
    snk = -1;
    G.clear();
    dist.clear();
    seen.clear();
  }
  void Set(int x, int y) { src = x, snk = y; }
  void resize(int s) {
    Siz = s;
    G.resize(s + 1);
    dist.resize(s + 1);
    seen.resize(s + 1);
  }
  void add_edge(int u, int v, int c) {
    edge t1(v, c, G[v].size()), t2(u, 0, G[u].size());
    G[u].push_back(t1);
    G[v].push_back(t2);
  }
  void bfs(int s) {
    for (int i = 0; i < dist.size(); i++) dist[i] = -1;
    queue<int> Q;
    dist[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      for (int i = 0; i < G[x].size(); i++) {
        int v = G[x][i].to;
        if (G[x][i].cap && dist[v] == -1) {
          dist[v] = dist[x] + 1;
          Q.push(v);
        }
      }
    }
  }
  int dfs(int x, int dest, int flow) {
    if (x == dest) return flow;
    for (int &i = seen[x]; i < G[x].size(); i++) {
      edge &e = G[x][i];
      if (e.cap && dist[e.to] == dist[x] + 1) {
        int ff = dfs(e.to, dest, min(flow, e.cap));
        if (ff) {
          e.cap -= ff;
          G[e.to][e.rev].cap += ff;
          return ff;
        }
      }
    }
    return 0;
  }
  int dinic(int u, int v) {
    int ans = 0;
    while (1) {
      for (int i = 0; i < seen.size(); i++) seen[i] = 0;
      bfs(u);
      if (dist[v] == -1) break;
      int f;
      while (f = dfs(u, v, 2147483647)) {
        ans += f;
      }
    }
    return ans;
  }
  int Maxflow() { return dinic(src, snk); }
};
const int Maxn = 1000005;
int n, a[Maxn], m, k[Maxn];
int tree[Maxn * 4];
void build(int push, int l, int r) {
  if (l == r) {
    tree[push] = a[l];
    return;
  }
  int mid = l + r >> 1;
  build(push * 2, l, mid);
  build(push * 2 + 1, mid + 1, r);
  tree[push] = min(tree[push * 2], tree[push * 2 + 1]);
}
int Front(int push, int l, int r, int pos, int val) {
  if (!pos) return -1;
  if (tree[push] > val) {
    return -1;
  }
  if (l == r) {
    return l;
  }
  int mid = l + r >> 1;
  if (pos <= mid) {
    return Front(push * 2, l, mid, pos, val);
  }
  if (tree[push * 2 + 1] > val) {
    return Front(push * 2, l, mid, pos, val);
  } else {
    int res = Front(push * 2 + 1, mid + 1, r, pos, val);
    if (res != -1) return res;
    return Front(push * 2, l, mid, pos, val);
  }
}
int Back(int push, int l, int r, int pos, int val) {
  if (tree[push] >= val) return -1;
  if (pos == n + 1) return -1;
  if (l == r) {
    return l;
  }
  int mid = l + r >> 1;
  if (pos > mid) {
    return Back(push * 2 + 1, mid + 1, r, pos, val);
  }
  if (tree[push * 2] >= val) {
    return Back(push * 2 + 1, mid + 1, r, pos, val);
  } else {
    int res = Back(push * 2, l, mid, pos, val);
    if (res != -1)
      return res;
    else
      return Back(push * 2 + 1, mid + 1, r, pos, val);
  }
}
int pr[Maxn], nx[Maxn];
long long res1[Maxn], res2[Maxn], res3[Maxn];
double ans[Maxn];
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
  }
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    pr[i] = Front(1, 1, n, i - 1, a[i]);
    if (pr[i] == -1) pr[i] = 0;
    nx[i] = Back(1, 1, n, i + 1, a[i]);
    if (nx[i] == -1) nx[i] = n + 1;
    pr[i]++;
    nx[i]--;
    int len = nx[i] - pr[i] + 1;
    int R = min(nx[i] - i, i - pr[i]);
    res1[R + 1] += a[i] * (R + 1);
    res1[len - R + 1] -= a[i] * (R + 1);
    res2[1] += a[i];
    res2[R + 1] -= a[i];
    res3[R + 1] -= a[i] * R;
    res3[len + 1] += a[i] * R;
    res2[len - R + 1] -= a[i];
    res3[len - R + 1] += (R + 1) * a[i];
    res3[len + 1] -= (R + 1) * a[i];
    res2[len + 1] += a[i];
  }
  for (int i = 1; i <= n; i++) {
    res1[i] += res1[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    res3[i] += res3[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    res2[i] += res2[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    res2[i] += res2[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    res2[i] += res1[i];
    res2[i] += res3[i];
  }
  int m;
  m = read();
  for (int i = 0; i < m; i++) {
    k[i] = read();
    printf("%.10lf\n", (double)res2[k[i]] / (double)(n - k[i] + 1));
  }
}
