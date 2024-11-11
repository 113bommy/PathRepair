#include <bits/stdc++.h>
using namespace std;
const int N = 200005, BLK = 300;
long long ans, F[N];
int n, w, cntblk, at;
int g[N], t[N], now[N], cnt[N];
struct node {
  int x, y;
} a[N];
bool cmp(node a, node b) { return a.y < b.y; }
bool chk(int x, int y, int z) {
  return 1ll * (z - x) * (F[y] - F[x]) <= 1ll * (y - x) * (F[z] - F[x]);
}
long long f(int x, int y) { return 1ll * x * y + F[x]; }
void upd(int x) {
  for (; now[x] + 1 <= cnt[x] && f(g[now[x]], t[x]) < f(g[now[x] + 1], t[x]);
       now[x]++)
    ;
}
void init(int x) {
  int l = (x - 1) * BLK + 1, r = x * BLK;
  cnt[x] = l - 1;
  for (int i = (int)(l); i <= (int)(r); i++) {
    for (; cnt[x] > l && chk(g[cnt[x] - 1], g[cnt[x]], i); cnt[x]--)
      ;
    g[++cnt[x]] = i;
  }
  now[x] = l;
  upd(x);
}
void change(int pos) {
  int x = 1;
  for (; x < cntblk && x * BLK <= pos; x++) t[x]++, upd(x);
  for (int i = (int)((x - 1) * BLK + 1); i <= (int)(pos); i++) F[i] += i;
  init(x);
}
int main() {
  scanf("%d%d", &n, &w);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d%d", &a[i].x, &a[i].y);
  sort(a + 1, a + n + 1, cmp);
  cntblk = 100000 / BLK + 1;
  for (int i = (int)(1); i <= (int)(cntblk); i++) init(i);
  for (int c = 0, i = 1; i <= n; c++) {
    printf("%lld %d\n", 1ll * (n - i + 1) * c * w + ans, at);
    for (; i <= n && a[i].y == c; i++) change(a[i].x);
    ans = at = 0;
    for (int j = (int)(1); j <= (int)(cntblk); j++) {
      long long res = f(g[now[j]], t[j]);
      if (res > ans) ans = res, at = g[now[j]];
    }
  }
  printf("%lld %d\n", ans, at);
}
