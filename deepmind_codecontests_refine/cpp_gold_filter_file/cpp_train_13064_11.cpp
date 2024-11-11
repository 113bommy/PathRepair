#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = 1;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    x = (x << 1) + (x << 3) + ch - 48;
  return f ? -x : x;
}
int n, head[100005], cnt, in[100005];
struct edge {
  int nxt, to;
} e[100005 << 1];
inline void insert(int u, int v) {
  e[++cnt] = (edge){head[u], v};
  head[u] = cnt;
  in[u]++;
  e[++cnt] = (edge){head[v], u};
  head[v] = cnt;
  in[v]++;
}
int vis[100005], sum[100005];
inline void dfs(int x, int fa) {
  if (in[x] < 3) {
    vis[x] = 1;
    for (int i = head[x]; i; i = e[i].nxt)
      if (e[i].to != fa) dfs(e[i].to, x);
  }
}
int main() {
  n = read();
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    insert(u, v);
  }
  for (int i = 1; i <= n; i++)
    if (in[i] == 1) dfs(i, 0);
  for (int x = 1; x <= n; x++)
    for (int i = head[x]; i; i = e[i].nxt)
      if (vis[e[i].to]) sum[x]++;
  int cnt = 0;
  for (int x = 1; x <= n; x++)
    if (!vis[x]) {
      cnt = 0;
      for (int i = head[x]; i; i = e[i].nxt) {
        if (!vis[e[i].to] && in[e[i].to] > min(sum[e[i].to], 2) + 1) cnt++;
      }
      if (cnt > 2) return puts("No") & 0;
    }
  puts("Yes");
  return 0;
}
