#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, x, y, a[maxn];
int main() {
  scanf("%d%d%d", &n, &x, &y);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    bool fl = 1;
    for (int d = i - 1; d >= max(i - y, 1); d--) fl &= (a[d] > a[i]);
    for (int d = i + 1; d <= min(i + x, n); d++) fl &= (a[d] > a[i]);
    if (fl) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
