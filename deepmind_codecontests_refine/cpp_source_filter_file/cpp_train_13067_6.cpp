#include <bits/stdc++.h>
using namespace std;
struct qq {
  int x, p;
  bool operator<(const qq &b) const { return x < b.x; }
} a[200005];
int r[200005];
int st[200005];
int main() {
  int n, d, m;
  scanf("%d%d%d", &d, &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d %d", &a[i].x, &a[i].p);
  a[0].x = 0, a[0].p = 0;
  a[++m].x = d, a[m].p = 0;
  sort(a, a + m + 1);
  int l = 0;
  int p = 0;
  int now = n;
  long long ans = 0;
  int t = 0;
  for (int i = m; i >= 0; i--) {
    while (t > 0 && a[st[t - 1]].p > a[i].p) t--;
    r[i] = t == 0 ? m : st[t - 1];
    st[t++] = i;
  }
  while (l < d) {
    if (a[p + 1].x - l > n) return 0 * puts("-1");
    if (a[r[p]].x - l > n) {
      ans += (long long)(n - now) * a[p].p;
      now = n;
      now -= a[p + 1].x - l;
      p++;
      l = a[p].x;
    } else {
      if (now < a[r[p]].x - l)
        ans += (long long)(a[r[p]].x - l - now) * a[p].p, now = 0;
      else
        now -= a[r[p]].x - l;
      p = r[p];
      l = a[p].x;
    }
  }
  printf("%d\n", ans);
  return 0;
}
