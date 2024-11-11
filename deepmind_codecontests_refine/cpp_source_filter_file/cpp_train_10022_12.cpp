#include <bits/stdc++.h>
using namespace std;
int n, m, S, T, ans = 0;
char s[210][210];
struct edge {
  int y, z, next;
} e[100010 << 2];
int first[100010], len = 1;
void buildroad(int x, int y, int z) {
  e[++len] = (edge){y, z, first[x]};
  first[x] = len;
}
void ins(int x, int y, int z = 1) {
  buildroad(x, y, z);
  buildroad(y, x, 0);
}
int h[100010], q[100010], st, ed, cur[100010];
bool bfs() {
  memset(h, 0, (T + 1) << 2);
  h[q[st = ed = 1] = S] = 1;
  while (st <= ed) {
    int x = q[st++];
    cur[x] = first[x];
    for (int i = first[x]; i; i = e[i].next)
      if (!h[e[i].y] && e[i].z) h[q[++ed] = e[i].y] = h[x] + 1;
  }
  return h[T];
}
int dfs(int x, int flow) {
  if (x == T) return flow;
  int tt = 0;
  for (int i = cur[x]; i; i = e[i].next) {
    int y = e[i].y;
    cur[x] = i;
    if (h[y] == h[x] + 1 && e[i].z) {
      int p = dfs(y, min(flow - tt, e[i].z));
      tt += p;
      e[i].z -= p;
      e[i ^ 1].z += p;
    }
    if (tt == flow) break;
  }
  if (!tt) h[x] = 0;
  return tt;
}
int main() {
  scanf("%d %d", &n, &m);
  S = n * (m - 1) + m * (n - 1) + 1;
  T = S + 1;
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '#') {
        int L = j > 1 && s[i][j - 1] == '#' ? (i - 1) * (m - 1) + j - 1 : 0;
        int R = j < m && s[i][j + 1] == '#' ? (i - 1) * (m - 1) + j : 0;
        int U = i > 1 && s[i - 1][j] == '#' ? (i - 2) * m + j + n * (m - 1) : 0;
        int D = i < n && s[i + 1][j] == '#' ? (i - 1) * m + j + n * (m - 1) : 0;
        if (L && U) ins(L, U);
        if (L && D) ins(L, D);
        if (R && U) ins(R, U);
        if (R && D) ins(R, D);
      }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '#') {
        ans++;
        if (j < m && s[i][j + 1] == '#') ins(S, (i - 1) * (m - 1) + j), ans--;
        if (i < n && s[i + 1][j] == '#')
          ins((i - 1) * m + j + n * (m - 1), T), ans--;
      }
  }
  while (bfs()) ans += dfs(S, n * m);
  printf("%d", ans);
}
