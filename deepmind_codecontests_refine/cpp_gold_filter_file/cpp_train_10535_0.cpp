#include <bits/stdc++.h>
using namespace std;
int n, m;
int q;
int in[100005], out[100005];
vector<int> g[100005];
long long ans;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u < v) swap(u, v);
    out[u]++;
    in[v]++;
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) ans += 1LL * in[i] * out[i];
  printf("%lld\n", ans);
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int x;
    scanf("%d", &x);
    ans -= 1LL * in[x] * out[x];
    out[x] += in[x];
    in[x] = 0;
    for (int i = 0; i < g[x].size(); i++) {
      int v = g[x][i];
      ans += out[v] - in[v] - 1;
      in[v]++;
      out[v]--;
      g[v].push_back(x);
    }
    g[x].clear();
    printf("%lld\n", ans);
  }
  return 0;
}
