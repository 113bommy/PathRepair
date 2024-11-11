#include <bits/stdc++.h>
using namespace std;
const int MAX = 660;
int n, m, k, q;
int g[MAX][MAX];
int h[MAX];
int l[MAX];
int r[MAX];
struct aa {
  int x;
  int y;
  int t;
} a[303000];
bool cmp(aa x, aa y) { return x.t < y.t; }
int cat(int x) {
  int lo, ro;
  memset(h, 0, sizeof(h));
  memset(l, 0, sizeof(l));
  memset(r, 0, sizeof(r));
  int ans = 0;
  for (int j = 1; j <= m; j++) {
    h[j] = 0;
    l[j] = 1;
    r[j] = m;
  }
  for (int i = 1; i <= n; i++) {
    lo = 0, ro = m + 1;
    for (int j = 1; j <= m; j++) {
      if (g[i][j] == x) {
        h[j] = 0;
        l[j] = 1;
        lo = j;
      } else {
        h[j] = h[j] + 1;
        l[j] = max(l[j], lo + 1);
      }
    }
    for (int j = m; j >= 1; j--) {
      if (g[i][j] == x) {
        h[j] = 0;
        r[j] = m;
        ro = j;
      } else {
        r[j] = min(r[j], ro - 1);
        ans = max(ans, min(h[j], (r[j] - l[j] + 1)));
      }
    }
  }
  return ans;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].t);
  }
  sort(a + 1, a + 1 + q, cmp);
  int l = 1, r = 1e9 + 10;
  int mid = 0;
  while (l < r) {
    memset(g, 0, sizeof(g));
    mid = (l + r) / 2;
    for (int i = 1; i <= q; i++) {
      if (a[i].t > mid) break;
      g[a[i].x][a[i].y] = 1;
    }
    int ans = cat(0);
    if (ans >= k)
      r = mid;
    else
      l = mid + 1;
  }
  if (r == 1e9 + 10)
    printf("-1\n");
  else
    printf("%d\n", r);
  return 0;
}
