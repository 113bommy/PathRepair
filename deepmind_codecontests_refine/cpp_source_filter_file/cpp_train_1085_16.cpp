#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, m, y;
  cin >> n >> x >> m >> y;
  if (x > y) swap(n, m), swap(x, y);
  long long ans = n + m + 1;
  for (int i = 1; i <= m; i++) {
    int l = y - i - x;
    int r = y + i - x;
    if (l >= 0) {
      l = (l < n ? l : n);
      r = (r < n + 1 ? r : n + 1);
      ans += (0 > ((r - l - 1) * 2 - 1) ? 0 : ((r - l - 1) * 2 - 1));
    } else {
      l = -l;
      l = (l < n + 1 ? l : n + 1);
      r = (r < n + 1 ? r : n + 1);
      ans += (0 > ((r - l - 1) * 2 - 1) ? 0 : ((r - l - 1) * 2 - 1));
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
