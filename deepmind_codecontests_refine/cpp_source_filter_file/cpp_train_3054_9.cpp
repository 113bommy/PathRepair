#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
const int MAXM = 101010;
struct Edge {
  int to, next;
};
long long int ans = 1, dysnpv[MAXN][MAXN], mod;
int p[MAXN], z = -1;
int s[MAXN], t[MAXN], top_s, top_t;
int n, m, cnt, d_in[MAXN], d_out[MAXN], dis[MAXN];
Edge e[MAXM];
void add(int u, int v) {
  e[++z].to = v;
  e[z].next = p[u];
  p[u] = z;
  d_in[v]++;
  d_out[u]++;
}
void init() {
  memset(p, -1, sizeof(p));
  scanf("%d%d", &n, &m);
  cin >> mod;
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
  }
  for (int i = 1; i <= n; i++) {
    if (!d_out[i]) t[++top_t] = i;
    if (!d_in[i]) s[++top_s] = i;
  }
}
void bfs(int u) {
  memset(dis, 0, sizeof(dis));
  dis[u] = 1;
  cnt++;
  for (int i = 1; i <= top_s; i++)
    if (dis[s[i]])
      for (int temp = p[s[i]]; temp != -1; temp = e[temp].next)
        (dis[e[temp].to] += dis[s[i]]) %= mod;
  for (int i = 1; i <= top_t; i++) dysnpv[cnt][i] = dis[t[i]];
}
long long int quick_power(long long int a, int b) {
  long long int ret = 1;
  while (b) {
    if (b & 1) (ret *= a) %= mod;
    (a *= a) %= mod;
    b >>= 1;
  }
  return ret;
}
void process() {
  int ins[MAXN];
  memcpy(ins, d_in, sizeof(d_in));
  for (int i = 1; i <= top_s; i++)
    for (int temp = p[i]; temp != -1; temp = e[temp].next)
      if (!(--ins[e[temp].to])) s[++top_s] = e[temp].to;
  for (int i = 1; i <= n; i++)
    if (!d_in[i]) bfs(i);
  for (int i = 1; i <= top_t; i++) {
    int now = -1;
    for (int j = i; j <= top_t; j++)
      if (dysnpv[j][i]) {
        now = j;
        break;
      }
    if (now == -1) break;
    if (i != now) ans *= -1;
    for (int j = 1; j <= top_t; j++) swap(dysnpv[now][j], dysnpv[i][j]);
    long long int div = quick_power(dysnpv[i][i], mod - 2);
    for (int j = i + 1; j <= top_t; j++)
      if (dysnpv[j][i]) {
        long long int div_ = (dysnpv[j][i] * div) % mod;
        for (int k = 1; k <= top_t; k++)
          (dysnpv[j][k] -= dysnpv[i][k] * div_) %= mod;
      }
  }
  for (int i = 1; i <= top_t; i++) (ans *= dysnpv[i][i]) %= mod;
  (ans += mod) %= mod;
}
int main() {
  init();
  process();
  cout << ans << endl;
  return 0;
}
