#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T &x, T y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, T y) {
  x = x > y ? y : x;
}
const int INF = 2139062143;
template <typename T>
void read(T &x) {
  x = 0;
  bool f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = 0;
  } while (ch > '9' || ch < '0');
  do {
    x = x * 10 + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  x = f ? x : -x;
}
template <typename T>
void write(T x) {
  if (x < 0) x = ~x + 1, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 2e5 + 7;
struct EDGE {
  int to, next;
} edge[N << 1];
int n, cnt, q, f[N], dep[N], max_d, p, head[N];
bool in[N];
inline void addedge(int u, int v) {
  edge[++cnt].to = v;
  edge[cnt].next = head[u];
  head[u] = cnt;
}
inline void dfs(int u, int fa) {
  f[u] = fa;
  for (int i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == fa) continue;
    dep[v] = dep[u] + 1;
    if (dep[v] > max_d) {
      max_d = dep[v];
      p = v;
    }
    dfs(v, u);
  }
}
int ss;
inline void dfs2(int u, int f) {
  if (in[u])
    dep[u] = 1;
  else
    dep[u] = dep[f] + 1;
  for (int i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == f) continue;
    dfs2(v, u);
  }
}
inline int go(int u, int f, int dep) {
  if (dep == ss) return u;
  for (int i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == f || in[v]) continue;
    return go(v, u, dep + 1);
  }
}
inline void work() {
  int l, r;
  dfs(1, 0);
  l = p;
  max_d = 0;
  dep[p] = 0;
  dfs(l, 0);
  r = p;
  for (int i = r; i != f[l]; i = f[i]) in[i] = 1;
  int ans = 0, a = l, b = r, c = 0, len = max_d;
  dfs2(l, 0);
  for (int i = 1; i <= n; i++)
    if (dep[c] < dep[i] && a != i && b != i) c = i;
  int x = c;
  while (!in[x]) {
    in[x] = 1;
    x = f[x];
    ans++;
  }
  printf("%d\n%d %d %d\n", ans + len, a, b, c);
}
int main() {
  read(n);
  for (int i = 1, u, v; i < n; i++) {
    read(u);
    read(v);
    addedge(u, v);
    addedge(v, u);
  }
  work();
  return 0;
}
