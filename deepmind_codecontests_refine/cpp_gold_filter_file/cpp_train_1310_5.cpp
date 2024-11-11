#include <bits/stdc++.h>
using namespace std;
const long long M = 1e6 + 11;
long long n, m;
long long flag[M];
long long num, du[M];
long long fa[M];
long long vis[M];
long long ff(long long x) {
  if (fa[x] == x) return x;
  fa[x] = ff(fa[x]);
  return fa[x];
}
int main() {
  long long i, j, a, b, pa, pb, cnt = 0, jg = 0, tp;
  cin >> n >> m;
  num = 0;
  memset(vis, 0, sizeof(vis));
  memset(du, 0, sizeof(du));
  memset(flag, 0, sizeof(flag));
  for (i = 1; i <= n; i++) fa[i] = i;
  for (i = 1; i <= m; i++) {
    scanf("%lld%lld", &a, &b);
    if (a == b) {
      num++;
      flag[a] = 1;
    }
    du[a]++;
    du[b]++;
    pa = ff(a);
    pb = ff(b);
    if (pa != pb) fa[pa] = pb;
    vis[a] = vis[b] = 1;
  }
  tp = -1;
  for (i = 1; i <= n; i++)
    if (vis[i]) {
      if (tp == -1)
        tp = ff(i);
      else if (tp != ff(i)) {
        jg = 1;
        break;
      }
    }
  if (jg) {
    cout << 0 << endl;
    return 0;
  }
  long long tmp, ans = num * (num - 1) / 2;
  for (i = 1; i <= n; i++) {
    tmp = du[i];
    if (flag[i]) tmp -= 2;
    ans += tmp * (tmp - 1) / 2;
  }
  ans += num * (m - num);
  cout << ans << endl;
  return 0;
}
