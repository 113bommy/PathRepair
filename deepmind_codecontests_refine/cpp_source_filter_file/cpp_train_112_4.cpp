#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chmin(T &x, const T &y) {
  if (x > y) x = y;
}
template <typename T>
void chmax(T &x, const T &y) {
  if (x < y) x = y;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
const int N = 1e6 + 10;
int n, k, dep[N], head[N], cnt, low[N], sz[N];
struct node {
  int to, next;
} edge[N << 1];
inline void add(int u, int v) {
  edge[++cnt] = {v, head[u]};
  head[u] = cnt;
}
inline void dfs(int u, int fa) {
  dep[u] = dep[fa] + 1;
  low[u] = 0x3f3f3f3f;
  if (!head[u]) low[u] = dep[u];
  for (int i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    dfs(v, u);
    chmin(low[u], low[v]);
  }
}
inline void work(int u, int fa) {
  if (!head[u]) sz[u] = 1;
  for (int i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    work(v, u);
    if (dep[u] - low[v] <= k) sz[u] += sz[v], sz[v] = 0;
  }
}
inline int solve(int u, int fa) {
  int ret = 0;
  for (int i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    chmax(ret, solve(v, u));
  }
  return ret + sz[u];
}
int main() {
  n = read(), k = read();
  for (int i = 2; i <= n; i++) add(read(), i);
  dfs(1, 0);
  work(1, 0);
  cout << solve(1, 0);
  return 0;
  ;
}
