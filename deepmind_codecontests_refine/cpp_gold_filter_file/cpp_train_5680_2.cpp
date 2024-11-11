#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 100100, INF = 1000010000;
int n, m, S, T, u, v, c, f, fl = 1, mic;
int hd[N], di[N], in[N], vi[N];
struct edge {
  int n, v, w, c;
} e[M];
queue<int> q;
void add_(int u, int v, int w, int c) {
  e[++fl] = (edge){hd[u], v, w, c};
  hd[u] = fl;
}
void adde(int u, int v, int w, int c) {
  add_(u, v, w, c);
  add_(v, u, -w, 0);
}
bool SPFA() {
  for (int i = 1; i <= T; i++) di[i] = INF;
  q.push(T);
  di[T] = 0;
  while (q.size()) {
    int u = q.front();
    q.pop();
    in[u] = 0;
    for (int i = hd[u], v, w, c; v = e[i].v, w = e[i].w, c = e[i].c, i;
         i = e[i].n)
      if (e[i ^ 1].c && di[v] > di[u] - w) {
        di[v] = di[u] - w;
        if (!in[v]) q.push(v);
      }
  }
  return di[S] < INF;
}
int dfs(int u, int E) {
  vi[u] = 1;
  if (u == T) return E;
  int F = 0;
  for (int i = hd[u], v, w, c; v = e[i].v, w = e[i].w, c = e[i].c, i;
       i = e[i].n)
    if (c && !vi[v] && di[v] == di[u] - w) {
      int t = dfs(v, min(E, c));
      mic += t * w;
      F += t;
      e[i ^ 1].c += t;
      E -= t;
      e[i ^ 0].c -= t;
      if (!E) break;
    }
  return F;
}
int main() {
  scanf("%d%d", &n, &m);
  S = n + 1, T = n + 2;
  adde(n, 1, 0, INF);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d%d", &u, &v, &c, &f);
    in[v] += f, in[u] -= f;
    if (c >= f) {
      adde(u, v, 1, c - f);
      adde(u, v, 2, INF);
      adde(v, u, 1, f);
    } else {
      mic += f - c;
      adde(u, v, 2, INF);
      adde(v, u, 0, f - c);
      adde(v, u, 1, c);
    }
  }
  for (int i = 1; i <= n; i++)
    in[i] > 0 ? adde(S, i, 0, in[i]) : adde(i, T, 0, -in[i]), in[i] = 0;
  while (SPFA()) {
    do {
      for (int i = 1; i <= T; i++) vi[i] = 0;
      dfs(S, INF);
    } while (vi[T]);
  }
  cout << mic << '\n';
}
