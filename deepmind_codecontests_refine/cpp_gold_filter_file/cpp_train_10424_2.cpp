#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, next;
} e[400010];
int n, cnt, head[200010], ans;
vector<int> f[200010], prime[200010];
inline void add(int u, int v) {
  cnt++;
  e[cnt].to = v;
  e[cnt].next = head[u];
  head[u] = cnt;
}
inline void dfs(int u, int from) {
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == from) continue;
    dfs(v, u);
    for (int j = 0; j < prime[u].size(); j++)
      for (int k = 0; k < prime[v].size(); k++)
        if (prime[u][j] == prime[v][k]) {
          ans = max(ans, f[u][j] + f[v][k]);
          f[u][j] = max(f[u][j], f[v][k] + 1);
        }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    if (x > 1) ans = 1;
    for (int j = 2; j * j <= x; j++)
      if (x % j == 0) {
        prime[i].push_back(j);
        f[i].push_back(1);
        while (x % j == 0) x /= j;
      }
    if (x > 1) {
      prime[i].push_back(x);
      f[i].push_back(1);
    }
  }
  for (int i = 1, x, y; i < n; i++) {
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  dfs(1, 0);
  printf("%d", ans);
  return 0;
}
