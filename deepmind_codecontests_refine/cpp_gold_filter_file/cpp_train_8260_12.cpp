#include <bits/stdc++.h>
using namespace std;
int n, m, lst[20], ans[2000010], cn, fl;
struct node {
  int x, p;
} b[22];
bool cmp(node a, node b) { return a.x > b.x; }
int main() {
  scanf("%d", &n);
  for (int i = 1, a; i <= n; i++) {
    scanf("%d", &a);
    fl |= !a;
    m = 0;
    for (int j = 0; j <= 19; j++)
      if ((1 << j) & a) lst[j] = i;
    for (int j = 0; j <= 19; j++)
      if (lst[j]) b[++m] = (node){lst[j], j};
    sort(b + 1, b + m + 1, cmp);
    int now = 0;
    for (int j = 1; j <= m; j++) {
      now |= (1 << b[j].p);
      if (j == m || b[j].x != b[j + 1].x) ans[++cn] = now;
    }
  }
  sort(ans + 1, ans + cn + 1);
  cn = unique(ans + 1, ans + cn + 1) - ans - 1;
  return printf("%d", cn + fl), 0;
}
