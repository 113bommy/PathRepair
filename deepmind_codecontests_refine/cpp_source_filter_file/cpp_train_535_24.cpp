#include <bits/stdc++.h>
#pragma GCC optimize("inline", 3)
using namespace std;
const int B = 105, N = 50 * (B + 1) + 10, M = N * 300, inf = 1e8;
int n, m, K, C, D, S, T, tot = 1;
int hd[N], dis[N], pre[N], inq[N];
struct edge {
  int nx, to, fl, cs;
} e[M];
void ad(int a, int b, int c, int d) {
  e[++tot] = {hd[a], b, c, d};
  hd[a] = tot;
}
void add(int a, int b, int c, int d) { ad(a, b, c, d), ad(b, a, 0, -d); }
int spfa() {
  memset(dis, 63, sizeof dis), dis[S] = 0;
  queue<int> Q;
  Q.push(S);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    inq[u] = 0;
    for (int i = hd[u]; i; i = e[i].nx) {
      int v = e[i].to;
      if (e[i].fl && dis[v] > dis[u] + e[i].cs) {
        dis[v] = dis[u] + e[i].cs;
        pre[v] = i;
        if (!inq[v]) inq[v] = 1, Q.push(v);
      }
    }
  }
  return dis[T] < inf;
}
int mcmf() {
  int cst = 0, flw = 0;
  while (spfa()) {
    int f = inf;
    for (int i = pre[T]; i; i = pre[e[i ^ 1].to]) f = min(f, e[i].fl);
    flw += f;
    for (int i = pre[T]; i; i = pre[e[i ^ 1].to]) {
      cst += f * e[i].cs;
      e[i].fl -= f;
      e[i ^ 1].fl += f;
    }
  }
  return cst;
}
int main() {
  ios::sync_with_stdio(0);
  int x, y;
  cin >> n >> m >> K >> C >> D;
  S = n * (B + 1) + 1, T = n * (B + 1) + 2;
  for (int i = 1; i <= K; ++i) cin >> x, add(S, x, 1, 0);
  for (int i = 1; i <= m; ++i) {
    cin >> x >> y;
    for (int t = 1; t <= B; ++t)
      for (int w = min(24, K); w >= 1; --w) {
        add(n * (t - 1) + x, n * t + y, 1, C + D * (2 * w - 1));
        add(n * (t - 1) + y, n * t + x, 1, C + D * (2 * w - 1));
      }
  }
  for (int u = 1; u <= n; ++u)
    for (int t = 1; t <= B; ++t)
      for (int w = min(24, K); w >= 1; --w) {
        add(n * (t - 1) + u, n * t + u, 1, C);
      }
  for (int t = 1; t <= B; ++t) add(n * t + 1, T, inf, 0);
  cout << mcmf();
}
