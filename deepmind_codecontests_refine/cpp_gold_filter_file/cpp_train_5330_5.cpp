#include <bits/stdc++.h>
using namespace std;
int inline read() {
  int num = 0, neg = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    num = (num << 3) + (num << 1) + c - '0';
    c = getchar();
  }
  return num * neg;
}
const int maxn = 1000010;
int n, m, T, head[maxn], cnt, d[maxn];
struct Edge {
  int nxt, to;
} edge[maxn];
void add_edge(int x, int y) {
  edge[++cnt].nxt = head[x];
  edge[cnt].to = y;
  head[x] = cnt;
}
int dfn[maxn], low[maxn], sta[maxn], top, ins[maxn], num, tot, c[maxn];
void Tarjan(int x) {
  dfn[x] = low[x] = ++num;
  ins[x] = 1;
  sta[++top] = x;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (!dfn[v]) {
      Tarjan(v);
      low[x] = min(low[x], low[v]);
    } else if (ins[v])
      low[x] = min(low[x], dfn[v]);
  }
  if (dfn[x] == low[x]) {
    int y;
    tot++;
    do {
      y = sta[top--];
      c[y] = tot;
      ins[y] = 0;
    } while (x != y);
  }
}
void Init() {
  for (int i = 1; i <= n; i++) dfn[i] = low[i] = head[i] = d[i] = 0;
  cnt = 0;
  num = 0;
  tot = 0;
}
int main() {
  T = read();
  while (T--) {
    n = read();
    m = read();
    for (int i = 1; i <= m; i++) {
      int x = read(), y = read();
      if (x != y) add_edge(x, y);
    }
    for (int i = 1; i <= n; i++)
      if (!dfn[i]) Tarjan(i);
    if (tot == 1) {
      printf("No\n");
      Init();
      continue;
    } else {
      printf("Yes\n");
      for (int i = 1; i <= n; i++)
        for (int j = head[i]; j; j = edge[j].nxt) {
          int v = edge[j].to;
          if (c[v] == c[i]) continue;
          d[c[i]]++;
        }
      int belong, ans = 0, total = 0;
      for (int i = 1; i <= tot; i++)
        if (!d[i]) belong = i;
      for (int i = 1; i <= n; i++)
        if (c[i] == belong) ans++;
      printf("%d %d\n", ans, n - ans);
      for (int i = 1; i <= n; i++)
        if (c[i] == belong) printf("%d ", i);
      printf("\n");
      for (int i = 1; i <= n; i++)
        if (c[i] != belong) printf("%d ", i);
      printf("\n");
    }
    Init();
  }
  return 0;
}
