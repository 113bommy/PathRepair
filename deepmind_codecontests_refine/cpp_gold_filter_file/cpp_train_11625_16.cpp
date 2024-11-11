#include <bits/stdc++.h>
using namespace std;
int mx[300005], f[300005][20], n;
long long ans;
vector<int> e[300005];
int main() {
  scanf("%d", &n);
  for (int i = 1, u, v; i < n; i++)
    scanf("%d%d", &u, &v), e[u].emplace_back(v), e[v].emplace_back(u);
  function<void(int, int)> dfs1 = [&](int u, int fa) {
    mx[u] = 1;
    for (int v : e[u])
      if (v ^ fa) dfs1(v, u), mx[u] = max(mx[u], mx[v] + 1);
    ans += mx[u];
    static int tmp[300005];
    f[u][0] = n;
    for (int i = 1; i < 20; i++) {
      int top = 0;
      for (int v : e[u])
        if (v ^ fa) tmp[++top] = f[v][i - 1];
      sort(tmp + 1, tmp + 1 + top, [](int _, int $) { return _ > $; });
      for (f[u][i] = 1; f[u][i] < top && f[u][i] < tmp[f[u][i] + 1]; f[u][i]++)
        ;
    }
  };
  dfs1(1, 0);
  function<void(int, int)> dfs2 = [&](int u, int fa) {
    for (int v : e[u])
      if (v ^ fa) dfs2(v, u);
    for (int i = 1; i < 20; i++)
      for (int v : e[u])
        if (v ^ fa) f[u][i] = max(f[u][i], f[v][i]);
    for (int i = 1; i < 20; i++) ans += 1ll * i * (f[u][i - 1] - f[u][i]);
  };
  dfs2(1, 0);
  printf("%lld\n", ans);
}
