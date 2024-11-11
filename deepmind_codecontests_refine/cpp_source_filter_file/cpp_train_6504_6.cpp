#include <bits/stdc++.h>
using namespace std;
const int maxn = 12;
int a[1 << maxn];
int main() {
  int n;
  scanf("%d", &n);
  int cnt = (1 << (n + 1)) - 1;
  for (int i = 2; i <= cnt; i++) {
    scanf("%d", a + i);
  }
  long long ans = 0;
  for (int t = (1 << n) - 1; t >= 1; t--) {
    int x = a[t * 2];
    int y = a[t * 2 + 1];
    a[t] += max(x, y);
    ans += 2 * max(x, y) - x - y;
  }
  printf("%I64-d\n", ans);
  return 0;
}
