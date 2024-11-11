#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[1000010], cnt[1000010];
int edge[1000010];
bool vis[1000010];
int Find(int u) { return f[u] ? f[u] = Find(f[u]) : u; }
void Init() {
  int i, u, v, fu, fv;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= m; ++i) {
    scanf("%d %d", &u, &v);
    if (u == v)
      vis[u] = true;
    else {
      ++edge[u];
      ++edge[v];
    }
    fu = Find(u);
    fv = Find(v);
    ++cnt[fu];
    if (fu == fv) continue;
    f[fv] = fu;
    cnt[fu] += cnt[fv];
  }
}
void Work() {
  int i, res = 0;
  long long ans = 0;
  for (i = 1; i <= n; ++i) {
    if (!f[i] && cnt[i] == m) ++res;
  }
  if (res != 1) {
    printf("0\n");
    return;
  }
  for (i = 1, res = 0; i <= n; ++i) {
    ans += (edge[i] * (edge[i] - 1)) / 2;
    if (vis[i]) ans += m - 1, ++res;
  }
  ans -= 1LL * res * (res - 1) / 2;
  printf("%I64d\n", ans);
}
int main() {
  Init();
  Work();
  return 0;
}
