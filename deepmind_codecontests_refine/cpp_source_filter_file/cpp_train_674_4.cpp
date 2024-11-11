#include <bits/stdc++.h>
const int maxn = 210;
inline int Max(int a, int b) { return a > b ? a : b; }
inline int Min(int a, int b) { return a > b ? b : a; }
inline int read() {
  int f = 1, r = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') {
      f = -1;
    }
    c = getchar();
  }
  while (isdigit(c)) {
    r = 10 * r + c - '0';
    c = getchar();
  }
  return f * r;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writesp(int x) { write(x), putchar(' '); }
inline void writeln(int x) { write(x), puts(""); }
int N, M, Q, tot, ver[maxn * maxn], head[maxn * maxn], next[maxn * maxn],
    in[maxn * maxn], chess[maxn * maxn], stk[maxn * maxn];
int top, cnt, dfn[maxn * maxn], low[maxn * maxn], ai[15], bi[15], len;
bool used[maxn * maxn][15], instk[maxn * maxn], vis[maxn * maxn];
char str[1000000 + 10], input[300];
inline void add(int u, int v) {
  in[v]++, ver[++tot] = v, next[tot] = head[u], head[u] = tot;
}
inline int getid(int x, int y) { return (x - 1) * M + y; }
inline int in_bound(int x, int y) {
  return !(x < 0 || x > N || y < 0 || y > M);
}
void tarjan(int u) {
  dfn[u] = low[u] = ++cnt, stk[++top] = u, instk[u] = 1;
  for (int i = head[u]; i; i = next[i]) {
    if (!dfn[ver[i]]) {
      tarjan(ver[i]), low[u] = Min(low[u], low[ver[i]]);
    } else if (instk[ver[i]]) {
      low[u] = Min(low[u], dfn[ver[i]]);
    }
  }
  if (dfn[u] == low[u]) {
    while (top) {
      int v = stk[top--];
      used[u][chess[v]] = 1, instk[v] = 0;
      if (u != v) {
        vis[v] = 0, in[u] = 0;
      } else {
        break;
      }
    }
  }
}
bool dfs(int u, int pos) {
  if (pos == 0) {
    return 1;
  }
  bool t = false;
  for (int i = head[u]; i; i = next[i]) {
    if (!vis[ver[i]]) {
      continue;
    }
    if (used[ver[i]][str[pos] - '0']) {
      t = t || dfs(ver[i], pos - 1);
    } else {
      t = t || dfs(ver[i], pos);
    }
    if (t) break;
  }
  return t;
}
signed main() {
  N = read(), M = read(), Q = read(), memset(vis, true, sizeof(vis));
  for (register int i = 1; i <= N; ++i) {
    scanf("%s", input + 1);
    for (int j = 1; j <= M; ++j) {
      int id = getid(i, j);
      chess[id] = input[j] - '0';
    }
  }
  for (register int i = 0; i <= 9; ++i) {
    ai[i] = read(), bi[i] = read();
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      int id = getid(i, j);
      if (!in_bound(ai[chess[id]] + i, j + bi[chess[id]])) {
        continue;
      }
      add(getid(ai[chess[id]] + i, j + bi[chess[id]]), id);
    }
  }
  for (int i = 1; i <= N * M; ++i) {
    if (!dfn[i]) tarjan(i);
  }
  while (Q--) {
    scanf("%s", str + 1), len = strlen(str + 1);
    int flag = 0;
    for (register int i = 1; i <= N * M; ++i) {
      if (!in[i]) {
        int pos = len;
        while (pos) {
          if (used[i][str[pos] - '0']) {
            pos--;
          } else {
            break;
          }
        }
        if (pos == 0) {
          puts("YES"), flag = 1;
          break;
        }
        if (dfs(i, pos)) {
          puts("YES"), flag = 1;
          break;
        }
      }
    }
    if (!flag) {
      puts("NO");
    }
  }
  return 0;
}
