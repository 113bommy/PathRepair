#include <bits/stdc++.h>
using namespace std;
const int32_t maxn = 1e2 + 10;
int32_t x, y, a[maxn], n, ans = 0;
int32_t main() {
  scanf("%d%d%d", &n, &x, &y);
  for (int32_t i = 1; i <= n; i++) scanf("%d", &a[i]);
  if (x > y)
    return cout << n << endl, 0;
  else
    for (int32_t i = 1; i <= n; i++)
      if (x > a[i]) ans++;
  printf("%d\n", (ans + 1) / 2);
  return 0;
}
