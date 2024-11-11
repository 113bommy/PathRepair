#include <bits/stdc++.h>
using namespace std;
struct node {
  int val;
  int id;
  bool operator<(const node& temp) const { return val < temp.val; }
} a[10010];
int h;
int n, k;
int pos[10010];
int main() {
  int i, j;
  scanf("%d %d", &n, &h);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i].val);
    a[i].id = i;
    pos[i] = 1;
  }
  sort(a, a + n);
  int ans = a[n - 1].val + a[n - 2].val - (a[0].val + a[1].val);
  if (max(a[n - 1].val + a[n - 2].val, a[0].val + a[n - 1].val + h) -
          min(a[0].val + a[1].val + h, a[1].val + a[2].val) <
      ans) {
    ans = max(a[n - 1].val + a[n - 2].val, a[0].val + a[n - 1].val + h) -
          min(a[0].val + a[1].val + h, a[1].val + a[2].val);
    pos[a[0].id] = 2;
  }
  printf("%d\n", ans);
  for (i = 0; i < n; i++) {
    printf("%d", pos[i]);
    if (i == n - 1) {
      printf("\n");
    } else {
      printf(" ");
    }
  }
  return 0;
}
