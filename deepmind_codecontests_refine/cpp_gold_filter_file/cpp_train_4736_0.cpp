#include <bits/stdc++.h>
using namespace std;
int n, k, c, cnt, a[444], ans, x, to;
int main() {
  scanf("%d%d", &n, &k);
  scanf("%d", &c);
  for (int i = 1; i <= c; i++) {
    scanf("%d", &x);
    a[x] = 1;
  }
  to = k;
  for (int i = 1; i <= n;) {
    int cnt = 0, pos = 0;
    for (int j = i; j <= min(n, to); j++)
      if (a[j]) cnt++, pos = j;
    if (to > n) {
      ans += cnt;
      break;
    }
    if (cnt)
      ans += cnt, i = pos + 1, to = pos + k;
    else
      ans++, to = to + k, i = to - k + 1;
  }
  printf("%d", ans);
}
