#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x, c[105];
  scanf("%d%d%d", &n, &k, &x);
  for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    int l = i - 1, r = i;
    while (l >= 0 && c[l] == x) --l;
    while (r < n && c[r] == x) ++r;
    int cnt = r - l - 1;
    if (cnt >= 2) {
      while (l >= 0 && r < n && c[l] == c[r]) {
        int y = c[l];
        while (l >= 0 && c[l] == y) --l;
        while (r < n && c[r] == y) ++r;
        if (r - l - cnt < 3) break;
        cnt = r - l - 1;
      }
      ans = max(ans, cnt);
    }
  }
  printf("%d", ans);
}
