#include <bits/stdc++.h>
const int N = 1e3 + 5;
int n, m, c;
int ans[N];
int main() {
  scanf("%d%d%d", &n, &m, &c);
  int l = 1, r = n + 1, x, pos;
  while (m--) {
    scanf("%d", &x);
    if (x <= c >> 1) {
      pos = std::upper_bound(ans + 1, ans + l, x) - ans;
      if (pos == l) l++;
    } else {
      pos = std::lower_bound(ans + r, ans + 1 + n, x) - ans - 1;
      if (pos < r) r--;
    }
    ans[pos] = x;
    printf("%d\n", pos);
    fflush(stdout);
    if (l >= r) break;
  }
  return 0;
}
