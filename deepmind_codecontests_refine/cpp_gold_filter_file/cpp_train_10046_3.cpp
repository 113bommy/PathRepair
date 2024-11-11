#include <bits/stdc++.h>
using namespace std;
long long n;
void solve(long long x1, long long y1, long long x2, long long y2) {
  if (x1 == 0 && y2 == 0)
    cout << y1 + x2;
  else if (x1 == 0 && y2 == n)
    cout << n - y1 + x2;
  else if (x1 == 0 && x2 == n)
    cout << min(y1 + y2, 2 * n - y1 - y2) + n;
  else if (x1 == n && y2 == 0)
    cout << n + y1 - x2;
  else if (x1 == n && y2 == n)
    cout << 2 * n - y1 - x2;
  else if (x1 == n && x2 == 0)
    cout << min(y1 + y2, 2 * n - y1 - y2) + n;
}
int32_t main() {
  long long x1, y1, x2, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;
  if ((x1 == 0 && x2 == 0) || (x1 == n && x2 == n))
    cout << abs(y2 - y1);
  else if ((y1 == 0 && y2 == 0) || (y1 == n && y2 == n))
    cout << abs(x2 - x1);
  else if (x1 == 0 || x1 == n)
    solve(x1, y1, x2, y2);
  else
    solve(y1, x1, y2, x2);
}
