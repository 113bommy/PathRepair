#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int main() {
  ios_base::sync_with_stdio(false);
  int c, d, n, m, k;
  cin >> c >> d >> n >> m >> k;
  int ans = 2e9;
  for (int x = 0; x <= maxn; x++)
    for (int y = 0; y <= maxn; y++)
      if (x * n + y + k >= m * n) ans = min(ans, x * c + y * d);
  cout << ans << endl;
  return 0;
}
