#include <bits/stdc++.h>
using namespace std;
long long n, a[500005], prt[21][500005], as, ans[500005], h[500005], cnt, rt,
    mx, inf = 1e18;
struct l1 {
  long long to, next;
} p[2000005];
void add(long long x, long long y) {
  cnt++;
  p[cnt].to = y;
  p[cnt].next = h[x];
  h[x] = cnt;
}
void dfs(long long x, long long fa) {
  long long nw = 0;
  prt[0][x] = fa;
  ans[x] = min(ans[x], a[x] + a[fa]);
  for (long long i = 1; i <= log2(n) + 1; i++) {
    prt[i][x] = prt[i - 1][prt[i - 1][x]];
    nw = i;
    if (!prt[i][x]) {
      break;
    }
    ans[x] = min(ans[x], a[x] + (i + 1) * a[prt[i][x]]);
  }
  ans[x] = min(ans[x], a[x] + (nw + 1) * a[rt]);
  if (x == rt) ans[x] = 0;
  for (long long i = h[x]; i; i = p[i].next) {
    long long y = p[i].to;
    if (y == fa) continue;
    dfs(y, x);
  }
}
int main() {
  scanf("%lld", &n);
  mx = inf;
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    ans[i] = inf;
    if (a[i] < mx) mx = a[i], rt = i;
  }
  for (long long i = 1; i < n; i++) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    add(x, y);
    add(y, x);
  }
  dfs(rt, 0);
  for (long long i = 1; i <= n; i++) as += ans[i];
  printf("%lld", as);
}
