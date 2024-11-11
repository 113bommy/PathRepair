#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const double PI = acos(-1.0);
int main() {
  ios::sync_with_stdio(false);
  int a1, a2, k1, k2, cnt;
  cin >> a1 >> a2 >> k1 >> k2 >> cnt;
  cout << cnt - a1 * (k1 - 1) - a2 * (k2 - 1) << " ";
  if (k1 <= k2) {
    if (cnt / k1 >= a1)
      cout << a1 + (cnt - k1 * a1) / k2;
    else
      cout << cnt / k1;
  } else {
    if (cnt / k2 >= a2)
      cout << a2 + (cnt - k2 * a2) / k1;
    else
      cout << cnt / k2;
  }
  return 0;
}
