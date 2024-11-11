#include <bits/stdc++.h>
using namespace std;
const int LIM = 100;
const int MOD = 1000000007;
int main() {
  long long a1, a2, a3, a4, a5, a6;
  cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
  long long ans = 0;
  long long x, y;
  x = a1;
  y = min(a2, a6);
  ans += (2 * x + y) * y;
  x = a4;
  y = min(a5, a3);
  ans += (2 * x + y) * y;
  x = 2 * a1 + 2 * min(a2, a6) - 1;
  y = max(a2, a6) - min(a2, a6);
  ans += x * y;
  cout << ans;
  return 0;
}
