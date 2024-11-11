#include <bits/stdc++.h>
using namespace std;
bool vis[300010];
long long n, m, tot, len = 63;
long long Dis[300010], head[300010], p[300010];
struct edge {
  long long fr, to, dis, nxt;
} e[300010];
long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 1) + (s << 3) + ch - '0', ch = getchar();
  return s * w;
}
void add(long long fr, long long to, long long dis) {
  e[++tot] = (edge){fr, to, dis, head[fr]};
  head[fr] = tot;
}
void insert(long long k) {
  for (long long i = len; i >= 0; i--) {
    if (k & (1ll << i)) continue;
    if (!p[i]) {
      p[i] = k;
      return;
    }
    k ^= p[i];
  }
}
void dfs(long long x, long long res) {
  Dis[x] = res;
  vis[x] = true;
  for (long long i = head[x]; i; i = e[i].nxt) {
    long long to = e[i].to;
    if (!vis[to])
      dfs(to, Dis[x] ^ e[i].dis);
    else
      insert(Dis[x] ^ Dis[to] ^ e[i].dis);
  }
}
long long query(long long res) {
  long long ans = res;
  for (long long i = len; i >= 0; i--)
    if (p[i]) ans = min(ans, ans ^ p[i]);
  return ans;
}
signed main() {
  n = read();
  m = read();
  for (long long i = 1, fr, to, dis; i <= m; i++) {
    fr = read();
    to = read();
    dis = read();
    add(fr, to, dis);
    add(to, fr, dis);
  }
  dfs(1, 0);
  printf("%lld\n", query(Dis[n]));
  return 0;
}
