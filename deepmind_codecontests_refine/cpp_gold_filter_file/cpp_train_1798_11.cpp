#include <bits/stdc++.h>
using namespace std;
int n;
int t[200086], h[200086];
int x, y;
vector<int> v[200086];
long long a[200086];
long long f[200086], g[200086];
long long ans;
void dfs(int i, int fa) {
  for (int j = 0; j < v[i].size(); j++) {
    int to = v[i][j];
    if (to == fa) continue;
    dfs(to, i);
  }
  long long sum = 0;
  int cnt = 0;
  for (int j = 0; j < v[i].size(); j++) {
    int to = v[i][j];
    if (to == fa) continue;
    ans += t[i] + t[to];
    sum += f[to], a[++cnt] = g[to] - f[to];
  }
  sort(a + 1, a + 1 + cnt, greater<long long>());
  for (int j = 1; j <= cnt; j++) a[j] += a[j - 1];
  f[i] = g[i] = -1e13;
  for (int j = 0; j <= cnt; j++) {
    if (fa) {
      if (h[i] <= h[fa])
        f[i] = max(f[i], sum + a[j] + 1ll * min(j + 1, cnt - j) * t[i]);
      if (h[i] >= h[fa])
        g[i] = max(g[i], sum + a[j] + 1ll * min(j, cnt - j + 1) * t[i]);
    } else {
      f[i] = max(f[i], sum + a[j] + 1ll * min(j, cnt - j) * t[i]);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y), v[y].push_back(x);
  }
  dfs(1, 0);
  printf("%lld", ans - f[1]);
}
