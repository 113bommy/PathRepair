#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, x1, x2, y1, y2;
  cin >> n >> m >> x1 >> y1 >> x2 >> y2;
  long long ma = max(abs(x2 - x1), abs(y2 - y1)),
            mi = min(abs(x2 - x1), abs(y2 - y1));
  if (ma >= 5 or (ma == 4 and mi >= 1))
    cout << "Second";
  else
    cout << "First";
  return 0;
}
