#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int cntl = 0, cntc = 0, cntr = 0;
  int l = m - 1, c = m, r = m + 1;
  int ans = m;
  int maxv = 0;
  if (l > 0) {
    if (maxv < l) {
      maxv = l;
      ans = l;
    }
  }
  if (r <= n) {
    if (maxv < n - r + 1) {
      maxv = n - r + 1;
      ans = r;
    }
  }
  printf("%d\n", ans);
  return 0;
}
