#include <bits/stdc++.h>
using namespace std;
int n, color, k;
int a[1100], b[1100], c[1100], tot;
void solve(void) {
  for (int i = (1); i <= (n); i++) scanf("%d", a + i);
  int ans = 0, temp = 0;
  tot = 0;
  for (int i = (1); i <= (n); i++) {
    temp++;
    if (i < n && a[i] == a[i + 1]) continue;
    tot++;
    b[tot] = a[i], c[tot] = temp;
    temp = 0;
  }
  for (int i = (1); i <= (tot); i++) {
    if (b[i] == k && c[i] >= 2) {
      int tt = c[i];
      for (int j = (i - 1); j >= (1); j--) {
        if (2 * i - j > tot) break;
        if (b[j] == b[2 * i - j] && c[j] + c[2 * i - j] >= 3) {
          tt += (c[j] + c[2 * i - j]);
        } else
          break;
      }
      if (tt > ans) ans = tt;
    }
  }
  printf("%d\n", ans);
}
int main(void) {
  while (3 == scanf("%d%d%d", &n, &color, &k)) solve();
  return 0;
}
