#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
long long ans;
int x[N], y[N], pre[N], nxt[N];
struct node {
  int x, y;
  bool operator<(const node &z) const { return y == z.y ? x < z.x : y < z.y; }
} a[N];
int dfs(int x, int y) {
  if (y == 1 || !x) return x;
  return dfs(pre[x], y - 1);
}
int now, r, c, n, k, tot, f[N];
void del(int x) {
  nxt[pre[x]] = nxt[x];
  pre[nxt[x]] = pre[x];
  now -= a[f[pre[x]]].y * (a[x].y - a[pre[x]].y);
  now += a[f[pre[x]]].y * (a[nxt[x]].y - a[pre[x]].y);
  now -= a[f[x]].y * (a[nxt[x]].y - a[x].y);
  for (int i = 1, p = nxt[x]; i <= k && p <= tot; i++, p = nxt[p]) {
    now -= a[f[p]].y * (a[nxt[p]].y - a[p].y);
    f[p] = pre[f[p]];
    now += a[f[p]].y * (a[nxt[p]].y - a[p].y);
  }
}
vector<int> v[N];
int main() {
  scanf("%d%d%d%d", &r, &c, &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
  for (int i = 1; i <= r; i++) {
    now = tot = 0;
    for (int j = 1; j <= n; j++)
      if (x[j] >= i) a[++tot] = (node){x[j], y[j]};
    sort(a + 1, a + 1 + tot);
    a[tot + 1].y = c + 1;
    for (int j = i; j <= r; j++) v[j].clear();
    for (int j = 1; j <= tot; j++) {
      pre[j] = j - 1, nxt[j] = j + 1, f[j] = dfs(j, k);
      now += a[f[j]].y * (a[j + 1].y - a[j].y);
    }
    for (int j = 1; j <= tot; j++) v[a[j].x].push_back(j);
    ans += now;
    for (int j = r; j >= i; j--) {
      for (int k = 0; k < v[j].size(); k++) del(v[j][k]);
      ans += now;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
