#include <bits/stdc++.h>
struct node {
  int val, id;
  bool operator<(node b) const { return val > b.val; }
} a[2010], ans[2001000];
int anssum, n;
void solve() {
  int k = a[2].val / a[3].val;
  while (k) {
    if (k & 1) {
      a[2].val -= a[3].val;
      a[3].val <<= 1;
      ans[++anssum].val = a[3].id;
      ans[anssum].id = a[2].id;
    } else {
      a[1].val -= a[3].val;
      a[3].val <<= 1;
      ans[++anssum].val = a[3].id;
      ans[anssum].id = a[1].id;
    }
    k >>= 1;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].val), a[i].id = i;
  std::sort(a + 1, a + n + 1);
  if (!a[2].val) return puts("0");
  while (a[3].val) {
    solve();
    std::sort(a + 1, a + n + 1);
  }
  printf("%d\n", anssum);
  for (int i = 1; i <= anssum; i++) printf("%d %d\n", ans[i].val, ans[i].id);
}
