#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
int main() {
  int n, x, m, y;
  cin >> n >> x >> m >> y;
  long long ans = 0, k = 1;
  int d = abs(x - y);
  for (int i = 1; i <= m; i++) {
    int x1 = abs(d - i), y1 = d + i;
    if (x1 > n) {
      ans++;
      continue;
    }
    ans += 2 * n - 2 * x1 + (x1 != 0);
    if (y1 <= n) ans -= 1 + 2 * n - 2 * y1;
  }
  for (int i = 0; i < n; i++)
    if (abs(d - i - 1) > m) k++;
  if (ans > 0)
    cout << ans + k + 1;
  else
    cout << k;
  return 0;
}
