#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int cnt[maxn], d[maxn];
int main() {
  int t, x, y, n, m, ma = 0, f = 0;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d", &x);
    cnt[x]++;
    ma = max(ma, x);
  }
  if (cnt[0] != 1) return puts("-1"), 0;
  for (int i = 1; i <= ma; i++)
    if (cnt[i] != 4 * i) {
      x = i;
      break;
    }
  for (int i = 1; i <= t; i++) {
    if (t % i == 0) {
      n = i, m = t / i;
      y = n + m - ma - x;
      memset(d, 0, sizeof(d));
      for (int j = 1; j <= n; j++)
        for (int k = 1; k <= m; k++) d[abs(x - j) + abs(y - k)]++;
      f = 1;
      for (int j = 1; j <= ma; j++)
        if (cnt[j] != d[j]) {
          f = 0;
          break;
        }
      if (f) return printf("%d %d\n%d %d\n", n, m, x, y), 0;
    }
  }
  puts("-1");
  return 0;
}
