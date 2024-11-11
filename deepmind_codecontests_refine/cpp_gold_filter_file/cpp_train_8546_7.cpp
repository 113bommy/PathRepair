#include <bits/stdc++.h>
using namespace std;
int rd() {
  char c = getchar();
  int t = 0, f = 1;
  while (!isdigit(c)) f = (c == '-') ? -1 : 1, c = getchar();
  while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
  return t * f;
}
void wt(int x) {
  if (x < 0)
    putchar('-'), wt(-x);
  else {
    if (x > 9) wt(x / 10);
    putchar(x % 10 + 48);
  }
}
const int N = 1035;
const int M = 4000035;
int head[N], cnt = 1;
struct Edge {
  int to, nxt, fl;
} E[M];
void Link(int u, int v, int w) {
  E[++cnt] = (Edge){v, head[u], w}, head[u] = cnt;
  E[++cnt] = (Edge){u, head[v], 0}, head[v] = cnt;
}
vector<int> VI[N];
int d[N], vis[N], match[N], n, x, clk, ans, P[N], S, T;
bool bfs() {
  memset(d, -1, sizeof d);
  static int Q[N], h, t, x;
  h = 0, Q[t = 1] = S, d[S] = 0;
  while (h < t) {
    x = Q[++h];
    for (int y, i = head[x]; i; i = E[i].nxt)
      if (E[i].fl)
        if (d[y = E[i].to] == -1) {
          d[y] = d[x] + 1;
          if (y == T)
            return 1;
          else
            Q[++t] = y;
        }
  }
  return 0;
}
int dfs(int x, int fl) {
  int Ret, w = 0;
  if (x == T || !fl) return fl;
  for (int y, i = head[x]; i; i = E[i].nxt)
    if (E[i].fl)
      if (d[y = E[i].to] == d[x] + 1 && (Ret = dfs(y, min(fl - w, E[i].fl))))
        E[i].fl -= Ret, E[i ^ 1].fl += Ret, w += Ret;
  if (!w) d[x] = -1;
  return w;
}
bool hungry(int x) {
  if (vis[x] == clk) return 0;
  vis[x] = clk;
  for (int i = ((int)0); i <= ((int)VI[x].size() - 1); i++)
    if (!match[VI[x][i]] || hungry(match[VI[x][i]]))
      return match[VI[x][i]] = x, 1;
  return 0;
}
int main() {
  n = rd(), T = n + 1;
  for (int i = ((int)1); i <= ((int)n); i++) {
    x = rd();
    while (x--) VI[i].push_back(rd() + n);
  }
  for (int i = ((int)1); i <= ((int)n); i++) clk++, hungry(i);
  for (int i = ((int)1); i <= ((int)n); i++)
    for (int j = ((int)0); j <= ((int)VI[i].size() - 1); j++)
      Link(i, match[VI[i][j]], 1e9);
  for (int i = ((int)1); i <= ((int)n); i++) {
    P[i] = -rd();
    if (P[i] > 0)
      Link(S, i, P[i]), ans += P[i];
    else
      Link(i, T, -P[i]);
  }
  while (bfs()) ans -= dfs(S, 1e9);
  return printf("%d\n", -ans), 0;
}
