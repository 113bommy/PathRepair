#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * f;
}
int n, tot, head[100005];
struct data {
  int to, next;
} edge[200005];
long double ans;
void dfs(int x, int f, int Dep) {
  ans += 1.0 / Dep;
  for (int i = head[x]; i; i = edge[i].next) {
    int y = edge[i].to;
    if (y == f) continue;
    dfs(y, x, Dep + 1);
  }
}
inline void make(int u, int v) {
  edge[++tot] = (data){v, head[u]};
  head[u] = tot;
}
int main() {
  n = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    make(x, y);
    make(y, x);
  }
  dfs(1, 0, 1);
  printf("%.6Lf", ans);
  return 0;
}
