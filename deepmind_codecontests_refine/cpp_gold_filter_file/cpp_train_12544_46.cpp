#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, id;
} a[1000003];
bool cmp(node x, node y) {
  if ((x.x / 1000) != (y.x / 1000)) return (x.x / 1000) < (y.x / 1000);
  if ((x.x / 1000) % 2) return x.y < y.y;
  return x.y > y.y;
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &a[i].x, &a[i].y);
      a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
      if (i < n)
        printf("%d ", a[i].id);
      else
        printf("%d\n", a[i].id);
  }
  return 0;
}
