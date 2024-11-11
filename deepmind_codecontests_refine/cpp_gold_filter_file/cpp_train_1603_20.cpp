#include <bits/stdc++.h>
using namespace std;
struct ww {
  int a, b, id;
} a[200010];
int i, j, k, n, m, ff[200010], cnt, l;
inline bool cc1(const ww &a, const ww &b) {
  return a.a < b.a || a.a == b.a && a.b > b.b;
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++)
    scanf("%d%d", &a[i].a, &a[i].b), a[i].id = i, a[i].b += a[i].a - 1;
  sort(a + 1, a + m + 1, cc1);
  l = k = 1;
  ff[a[1].id] = 1;
  for (i = 2; i <= m; i++)
    if (a[i].a - 1 <= a[k].b) {
      if (a[i].b > a[l].b) l = i;
    } else {
      ff[a[l].id] = 1;
      k = l;
      if (a[i].b > a[l].b) l = i;
    }
  ff[a[l].id] = 1;
  k = 0;
  for (i = 1; i <= m; i++)
    if (!ff[i]) k++;
  printf("%d\n", k);
  for (i = 1; i <= m; i++)
    if (!ff[i]) printf("%d ", i);
  return 0;
}
