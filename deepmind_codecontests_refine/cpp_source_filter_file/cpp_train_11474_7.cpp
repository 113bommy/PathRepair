#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353, inv2 = (MOD + 1) / 2;
int p = 1e7 + 19;
long double eps = 1e-6;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
long double pi = acos(-1.0L);
int head[1000000 + 10], vet[1000000 + 10], nxt[1000000 + 10],
    len1[1000000 + 10], len2[1000000 + 10], dis[1000000 + 10],
    inq[1000000 + 10], q[1000000 + 10], pre[1000000 + 10][2],
    save[1000000 + 10], ans[55][55], b[55][55], num[55][55], edge[55][55],
    Num[55][2], d[1000000 + 10], n, m, s, S, T, flow, tot;
int read() {
  int v = 0, f = 1;
  char c = getchar();
  while (c < 48 || 57 < c) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (48 <= c && c <= 57) v = (v << 3) + v + v + c - 48, c = getchar();
  return v * f;
}
long long readll() {
  long long v = 0, f = 1;
  char c = getchar();
  while (c < 48 || 57 < c) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (48 <= c && c <= 57) v = (v << 3) + v + v + c - 48, c = getchar();
  return v * f;
}
void add(int a, int b, int c, int d) {
  nxt[++tot] = head[a];
  vet[tot] = b;
  len1[tot] = c;
  len2[tot] = d;
  head[a] = tot;
  nxt[++tot] = head[b];
  vet[tot] = a;
  len1[tot] = 0;
  len2[tot] = -d;
  head[b] = tot;
}
int spfa() {
  for (int i = (int)1; i <= (int)s; i++) dis[i] = -1e9, inq[i] = 0;
  int t = 0, w = 1;
  q[1] = S, dis[S] = 0, inq[S] = 0;
  while (t < w) {
    t++;
    int u = q[t % (s + 5)];
    inq[u] = 0;
    int e = head[u];
    while (e) {
      int v = vet[e];
      if (len1[e] && dis[u] + len2[e] > dis[v]) {
        dis[v] = dis[u] + len2[e];
        pre[v][0] = u;
        pre[v][1] = e;
        if (!inq[v]) {
          w++;
          q[w % (s + 5)] = v;
          inq[v] = 1;
        }
      }
      e = nxt[e];
    }
  }
  if (dis[T] == -1e9) return 0;
  return 1;
}
void mcf() {
  int k = T;
  int t = 1e9;
  while (k != S) {
    int e = pre[k][1];
    if (len1[e] < t) t = len1[e];
    k = pre[k][0];
  }
  k = T;
  while (k != S) {
    int e = pre[k][1];
    len1[e] -= t;
    len1[e ^ 1] += t;
    flow += t * len2[e];
    k = pre[k][0];
  }
}
void init() {
  n = read(), m = read();
  for (int i = (int)1; i <= (int)m; i++) {
    int x = read(), y = read();
    d[x]++;
    ans[x][y] = 1;
    b[x][y] = b[y][x] = -1;
  }
}
void solve() {
  s = 0;
  S = ++s, T = ++s;
  tot = 1;
  for (int i = (int)1; i <= (int)n; i++)
    for (int j = (int)0; j <= (int)1; j++) Num[i][j] = ++s;
  for (int i = (int)1; i <= (int)n; i++)
    for (int j = (int)i + 1; j <= (int)n; j++)
      if (b[i][j] != -1) {
        s++;
        num[i][j] = s;
        add(S, num[i][j], 1, 0);
        add(num[i][j], Num[i][0], 1, 0);
        edge[i][j] = tot;
        add(num[i][j], Num[j][0], 1, 0);
      }
  for (int i = (int)1; i <= (int)n; i++)
    for (int j = (int)0; j <= (int)n - 1; j++)
      add(Num[i][0], Num[i][1], 1, d[i] + j);
  for (int i = (int)1; i <= (int)n; i++) add(Num[i][1], T, n, 0);
  for (int i = (int)1; i <= (int)tot; i++) save[i] = len1[i];
  int Ans = n * (n - 1) * (n - 2) / 6;
  for (int i = (int)1; i <= (int)n; i++) Ans -= d[i] * (d[i] - 1) / 2;
  flow = 0;
  while (spfa()) mcf();
  Ans -= flow;
  for (int i = (int)1; i <= (int)n; i++)
    for (int j = (int)i + 1; j <= (int)n; j++)
      if (b[i][j] != -1) {
        if (save[edge[i][j]] != len1[edge[i][j]])
          ans[i][j] = 1;
        else
          ans[j][i] = 1;
      }
  for (int i = (int)1; i <= (int)n; i++) {
    for (int j = (int)1; j <= (int)n; j++) printf("%d", ans[i][j]);
    printf("\n");
  }
}
int main() {
  init();
  solve();
  return 0;
}
