#include <bits/stdc++.h>
using namespace std;
int a[55], total = 0;
bool sum[50 * 1000 + 5];
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= n; ++i) total += a[i];
  sum[0] = true;
  for (int i = 1; i <= n; ++i)
    for (int j = total; j >= a[i]; --j)
      if (sum[j - a[i]]) sum[j] = true;
  int ma = 0, day = 0;
  while (true) {
    int t = ma;
    for (int i = ma + 1; i <= ma + d && i <= total; ++i)
      if (sum[i]) t = i;
    if (t == ma) break;
    ma = t;
    ++day;
  }
  printf("%d %d\n", ma, day);
  return 0;
}
