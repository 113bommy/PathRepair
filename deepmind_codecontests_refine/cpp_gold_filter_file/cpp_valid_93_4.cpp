#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  int x;
  if (a % 4 == 1)
    x = a - 1;
  else if (a % 4 == 2)
    x = 1;
  else if (a % 4 == 3)
    x = a;
  else
    x = 0;
  if (x == b)
    cout << a << "\n";
  else if ((x ^ b) != a)
    cout << a + 1 << "\n";
  else
    cout << a + 2 << "\n";
  return;
}
signed main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
