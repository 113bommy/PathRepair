#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, b[N], p[N];
long long ans, a[N];
int cnt, head[N];
struct edge {
  int v, nxt;
} e[N * 2];
void add(int u, int v) {
  e[++cnt] = (edge){v, head[u]};
  head[u] = cnt;
}
void dfs1(int u) {
  for (int i = head[u], v; v = e[i].v; i = e[i].nxt)
    dfs1(v), a[u] += max(a[v], 0LL);
  ans += a[u];
}
void dfs2(int u) {
  for (int i = head[u], v; v = e[i].v; i = e[i].nxt)
    if (a[u] > 0) dfs2(v);
  p[++cnt] = u;
  for (int i = head[u], v; v = e[i].v; i = e[i].nxt)
    if (a[u] <= 0) dfs2(v);
}
int main() {
  cin >> n;
  for (int i = (1); i <= (n); i++) scanf("%lld", &a[i]);
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &b[i]);
    if (~b[i]) add(b[i], i);
  }
  cnt = 0;
  for (int i = (1); i <= (n); i++)
    if (!~b[i]) dfs1(i), dfs2(i);
  cout << ans << endl;
  for (int i = (1); i <= (n); i++) printf("%d ", p[i]);
  return 0;
}
