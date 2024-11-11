#include <bits/stdc++.h>
using namespace std;
struct node {
  int l, r, id;
  bool operator<(const node& nd) const {
    return l == nd.l ? r < nd.r : l < nd.l;
  }
} a[300010];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) {
    scanf("%d%d", &a[i].l, &a[i].r);
    a[i].id = i;
  }
  sort(a, a + n);
  int idx = 0;
  for (int i = (1); i < (n); ++i) {
    if (a[i].r <= a[idx].r) {
      printf("%d %d\n", a[i].id + 1, a[idx].id + 1);
      return 0;
    } else {
      idx = i;
    }
  }
  puts("-1 -1");
  return 0;
}
