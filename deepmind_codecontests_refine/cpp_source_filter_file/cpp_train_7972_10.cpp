#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, num;
} a[100010];
int n, cnt, ans[100010];
int cmp(node x, node y) { return x.x == y.x ? x.y > y.y : x.x > y.x; }
int main() {
  scanf("%d", &n), cnt = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].x);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].y);
  for (int i = 1; i <= n; i++) a[i].num = i;
  sort(a + 1, a + 1 + n, cmp), ans[++cnt] = 1;
  for (int i = 2; i <= n; i += 2) {
    if (a[i].y > a[i + 1].y)
      ans[++cnt] = a[i].num;
    else
      ans[++cnt] = a[i + 1].num;
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
  return 0;
}
