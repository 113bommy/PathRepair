#include <bits/stdc++.h>
using namespace std;
int n, a[200005], ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  int t = (n - 2) / 2, l = 1, r = n - t;
  ans = 2000000000;
  for (int i = 0; i <= t; i++) {
    ans = min(ans, a[r] - a[l]);
    l++;
    r++;
  }
  printf("%d\n", ans);
  return 0;
}
