#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
queue<int> q[N];
int in[N], out[N], n, m, Q;
int main() {
  scanf("%d%d", &n, &m);
  long long ans = 0;
  for (int i = 1, u, v; i <= m; i++) {
    scanf("%d%d", &u, &v);
    if (u < v) in[u]++, out[v]++, q[u].push(v);
    if (v < u) in[v]++, out[u]++, q[v].push(u);
  }
  for (int i = 1; i <= n; i++) ans += 1ll * in[i] * out[i];
  printf("%lld\n", ans);
  scanf("%d", &Q);
  for (int i = 1, u; i <= Q; i++) {
    scanf("%d", &u);
    ans -= in[u] * out[u];
    while (!q[u].empty()) {
      int v = q[u].front();
      q[u].pop();
      ans -= 1ll * out[v] * in[v];
      out[v]--;
      in[v]++;
      ans += 1ll * out[v] * in[v];
      q[v].push(u);
      in[u]--;
      out[u]++;
    }
    printf("%lld\n", ans);
  }
}
