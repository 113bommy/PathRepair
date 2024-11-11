#include <bits/stdc++.h>
struct seg {
  int l, r, index;
} a[300010];
bool cmp1(seg a, seg b) { return a.l == b.l ? a.r < b.r : a.l < b.l; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].l, &a[i].r);
    a[i].index = i;
  }
  std::sort(a + 1, a + 1 + n, cmp1);
  int maxi = 1;
  for (int i = 2; i <= n; i++) {
    if (a[maxi].r >= a[i].r) {
      printf("%d %d\n", a[maxi].index, a[i].index);
      return 0;
    }
    maxi = i;
  }
  printf("-1 -1\n");
  return 0;
}
