#include <bits/stdc++.h>
using namespace std;
int n, m;
struct arr {
  int x, y, i;
  bool operator<(const arr &t) const { return y < t.y || y == t.y && x > t.x; }
} a[200008];
int tot, b[200008], fa[200008];
int find(int i) {
  if (fa[i] != i) return fa[i] = find(fa[i]);
  return fa[i];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    a[i].y = n - a[i].y + 1;
    swap(a[i].x, a[i].y);
    a[i].i = i;
  }
  sort(a + 1, a + m + 1);
  int r = 0;
  for (int i = 1; i <= n + 1; i++) fa[i] = i;
  for (int i = 1; i <= m; i++) {
    int j = find(a[i].x);
    if (j <= a[i].y) b[++tot] = a[i].i;
    fa[j] = find(j + 1);
  }
  sort(b + 1, b + tot + 1);
  printf("%d\n", tot);
  for (int i = 1; i <= tot - 1; i++) printf("%d ", b[i]);
  printf("%d\n", b[tot]);
  return 0;
}
