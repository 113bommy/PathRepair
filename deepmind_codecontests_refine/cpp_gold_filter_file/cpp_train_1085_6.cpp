#include <bits/stdc++.h>
using namespace std;
long long n, x, m, y, d, ans;
int main() {
  cin >> n >> x >> m >> y;
  ans = m + n + 1;
  if (x > y) swap(x, y), swap(n, m);
  for (int i = 1; i <= n; i++)
    if (x + i > y - m && x + i < y + m)
      if (x + i > y)
        ans += 2 * (min(m, y - x + i - 1) + (y - x - i));
      else
        ans += 2 * (min(m, y - x + i - 1) - (y - x - i)) - 1;
  cout << ans;
}
