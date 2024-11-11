#include <bits/stdc++.h>
using namespace std;
struct Line {
  int nxt, t, c, l;
} g[35500];
int fir[5500], tl = 1;
void adl(int f, int t, int c, int cost) {
  g[++tl] = (Line){fir[f], t, c, cost};
  fir[f] = tl;
  g[++tl] = (Line){fir[t], f, 0, -cost};
  fir[t] = tl;
}
int S, T, pre[5500], lp[5500], flow[5500], dis[5500];
bool in[5500];
queue<int> q;
int spfa() {
  for (int i = 1; i <= T; i++) {
    dis[i] = 1000000000;
    flow[i] = 0;
  }
  flow[S] = 1000000000;
  dis[S] = 0;
  q.push(S);
  in[S] = 1;
  while (!q.empty()) {
    int u = q.front();
    in[u] = 0;
    q.pop();
    for (int i = fir[u], v; i; i = g[i].nxt)
      if (g[i].c && dis[v = g[i].t] > dis[u] + g[i].l) {
        dis[v] = dis[u] + g[i].l;
        flow[v] = min(flow[u], g[i].c);
        lp[v] = i;
        pre[v] = u;
        if (!in[v]) {
          in[v] = 1;
          q.push(v);
        }
      }
  }
  return flow[T];
}
int n, m, k, C, D, pl[105][105], st[105][105];
struct Data {
  int f, t;
} s[105];
int main() {
  scanf("%d%d%d%d%d", &n, &m, &k, &C, &D);
  S = ((2 * n) * n + (n)) + 1;
  T = S + 2;
  adl(((0) * n + (1)), T, 1000000000, 0);
  for (int i = 1, p; i <= k; i++) {
    scanf("%d", &p);
    adl(S, ((0) * n + (p)), 1, 0);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &s[i * 2].f, &s[i * 2].t);
    s[i * 2 - 1] = (Data){s[i * 2].t, s[i * 2].f};
  }
  m *= 2;
  for (int t = 1; t <= n + n; t++) {
    for (int i = 1; i <= n; i++)
      adl(((t - 1) * n + (i)), ((t)*n + (i)), 1000000000, 0);
    for (int i = 1; i <= m; i++) {
      adl(((t - 1) * n + (s[i].f)), ((t)*n + (s[i].t)), 1, D);
      pl[t][i] = tl;
      st[t][i] = 1;
    }
    adl(((t)*n + (1)), T, 1000000000, t * C);
  }
  int sav, cans = 0;
  while (sav = spfa()) {
    int u = T;
    while (u != S) {
      int las = pre[u];
      g[lp[u]].c -= sav;
      g[lp[u] ^ 1].c += sav;
      u = las;
    }
    cans += dis[T] * sav;
    for (int t = 1; t <= n + n; t++)
      for (int i = 1; i <= m; i++)
        if (g[pl[t][i]].c) {
          st[t][i]++;
          adl(((t - 1) * n + (s[i].f)), ((t)*n + (s[i].t)), 1,
              D * (st[t][i] * 2 - 1));
          pl[t][i] = tl;
        }
  }
  printf("%d\n", cans);
  return 0;
}
