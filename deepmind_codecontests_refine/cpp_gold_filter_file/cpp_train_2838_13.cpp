#include <bits/stdc++.h>
using namespace std;
const int MAX = 200002;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int m = max({a, b, c});
  if (a == b and m == a)
    cout << "YES\n", cout << a << ' ' << c << ' ' << c << ' ' << '\n';
  else if (a == c and m == a)
    cout << "YES\n", cout << a << ' ' << b << ' ' << b << ' ' << '\n';
  else if (c == b and m == b)
    cout << "YES\n", cout << b << ' ' << a << ' ' << a << ' ' << '\n';
  else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
