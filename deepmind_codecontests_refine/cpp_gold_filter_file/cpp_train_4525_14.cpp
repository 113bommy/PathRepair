#include <bits/stdc++.h>
using namespace std;
struct dian {
  int v, id;
} a[100005];
bool cmp(dian a, dian b) { return a.v < b.v; }
int main() {
  int n, i, x, y, z, w, t;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i].v);
    a[i].id = i;
  }
  sort(a + 1, a + n + 1, cmp);
  x = y = z = w = -1;
  for (i = 2; i <= n; i++)
    if (a[i].v == a[i - 1].v) {
      if (x == -1) {
        x = i - 1;
        y = i;
      } else if (z == -1) {
        z = i - 1;
        w = i;
      }
    }
  if (z == -1) {
    printf("NO\n");
    return 0;
  }
  if (z == y) {
    printf("YES\n");
    for (i = 1; i < n; i++) printf("%d ", a[i].id);
    printf("%d\n", a[n].id);
    t = a[x].id;
    a[x].id = a[y].id;
    a[y].id = t;
    for (i = 1; i < n; i++) printf("%d ", a[i].id);
    printf("%d\n", a[n].id);
    t = a[x].id;
    a[x].id = a[w].id;
    a[w].id = t;
    for (i = 1; i < n; i++) printf("%d ", a[i].id);
    printf("%d\n", a[n].id);
    return 0;
  }
  printf("YES\n");
  for (i = 1; i < n; i++) printf("%d ", a[i].id);
  printf("%d\n", a[n].id);
  t = a[x].id;
  a[x].id = a[y].id;
  a[y].id = t;
  for (i = 1; i < n; i++) printf("%d ", a[i].id);
  printf("%d\n", a[n].id);
  t = a[z].id;
  a[z].id = a[w].id;
  a[w].id = t;
  for (i = 1; i < n; i++) printf("%d ", a[i].id);
  printf("%d\n", a[n].id);
  return 0;
}
