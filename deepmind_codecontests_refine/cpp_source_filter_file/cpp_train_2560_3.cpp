#include <bits/stdc++.h>
using namespace std;
struct node {
  int d, pos;
  inline bool operator<(const node &t) const { return d < t.d; }
} a[105];
int w, n, t[105], ans[105];
int main() {
  scanf("%d%d", &n, &w);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].d);
    a[i].pos = i;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    ans[a[i].pos] = max(a[i].d + 1 >> 1, ans[a[i - 1].pos]);
    w -= ans[a[i].pos];
  }
  if (w < 0)
    printf("-1");
  else {
    for (int i = n; i >= 0; i--) {
      if (w > a[i].d - ans[a[i].pos]) {
        w -= a[i].d - ans[a[i].pos];
        ans[a[i].pos] = a[i].d;
      } else {
        ans[a[n].pos] += w;
        break;
      }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  }
  return 0;
}
