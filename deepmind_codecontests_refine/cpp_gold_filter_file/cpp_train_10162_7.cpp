#include <bits/stdc++.h>
using namespace std;
const int maxd = 1000000007, N = 100000;
const double pi = acos(-1.0);
struct node {
  int to, nxt;
  long long cost;
} sq[200200];
int n, m, all = 0, head[100050];
long long bas[65], dis[100050];
bool vis[100050];
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while ((ch < '0') || (ch > '9')) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ((ch >= '0') && (ch <= '9')) {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * f;
}
void add(int u, int v, long long w) {
  all++;
  sq[all].to = v;
  sq[all].nxt = head[u];
  sq[all].cost = w;
  head[u] = all;
}
void init() {
  n = read();
  m = read();
  int i;
  for (i = 1; i <= m; i++) {
    int u = read(), v = read();
    long long w = read();
    add(u, v, w);
    add(v, u, w);
  }
}
void ins(long long x) {
  int i;
  for (i = 60; i >= 0; i--) {
    if (!(x & (1ll << i))) continue;
    if (!bas[i]) {
      bas[i] = x;
      return;
    } else
      x ^= bas[i];
  }
}
void dfs(int u) {
  vis[u] = 1;
  int i;
  for (i = head[u]; i; i = sq[i].nxt) {
    int v = sq[i].to;
    if (vis[v])
      ins(dis[u] ^ dis[v] ^ sq[i].cost);
    else {
      dis[v] = dis[u] ^ sq[i].cost;
      dfs(v);
    }
  }
}
void work() {
  dfs(1);
  int i;
  long long ans = dis[n];
  for (i = 60; i >= 0; i--)
    if ((ans ^ bas[i]) < ans) ans = (ans ^ bas[i]);
  printf("%lld", ans);
}
int main() {
  init();
  work();
  return 0;
}
