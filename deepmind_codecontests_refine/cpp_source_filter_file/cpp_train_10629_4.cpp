#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
inline int read() {
  char ch = getchar();
  int t = 1;
  int x = 0;
  for (; ch > '9' || ch < '0'; ch = getchar())
    if (ch == '-') t = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    x = (x << 1) + (x << 3) + (ch - 48);
  return x * t;
}
struct edge {
  int to, next;
} a[N << 1];
int head[N];
int cnt = 0;
int K;
int n;
const int INF = 1e9;
inline void add(int x, int y) {
  a[++cnt] = (edge){y, head[x]};
  head[x] = cnt;
}
int near[N], away[N];
int du[N];
int ans = 0;
void dfs(int u, int fa) {
  near[u] = INF;
  away[u] = -1;
  for (register int v, i = head[u]; i; i = a[i].next) {
    v = a[i].to;
    if (v == fa) continue;
    dfs(v, u);
    near[u] = min(near[v] + 1, near[u]);
    if (near[v] + away[v] > K) away[u] = max(away[u], away[v] + 1);
  }
  if (fa) {
    if (away[u] >= K)
      ++ans, away[u] = -1, near[u] = 0;
    else if (du[u] == 1)
      away[u] = 0;
  } else {
    if (du[u] == 1) away[u] = max(away[u], 0);
    if (near[u] + away[u] > K) ++ans;
  }
  return;
}
int main() {
  n = read();
  K = read();
  register int u, v;
  for (register int i = n - 1; i; --i) {
    u = read();
    v = read();
    ++n;
    add(u, n);
    add(n, u);
    add(v, n);
    add(n, v);
    ++du[u];
    ++du[v];
  }
  dfs(1, 0);
  printf("%d\n", ans);
}
