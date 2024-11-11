#include <bits/stdc++.h>
using namespace std;
const int MX = 1500 + 7;
int n, m;
int a[MX];
struct node {
  int l, r;
} b[MX];
int main() {
  scanf("%d", &n);
  int t = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    t += a[i];
  }
  int ans = 1e9;
  scanf("%d", &m);
  int ok = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &b[i].l, &b[i].r);
    if (b[i].r >= t) {
      ans = min(ans, b[i].l);
      ok = 1;
    }
  }
  if (!ok)
    puts("-1");
  else
    printf("%d\n", ans);
  return 0;
}
