#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  int k;
  if ((a - 1) % 4 == 0)
    k = a - 1;
  else if ((a - 1) % 4 == 1)
    k = 1;
  else if ((a - 1) % 4 == 2)
    k = a;
  else
    k = 0;
  if (k == b)
    cout << a << '\n';
  else {
    if (a == b)
      cout << a + 2 << '\n';
    else
      cout << a + 1 << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
