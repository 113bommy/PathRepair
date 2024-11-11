#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b, c, d, x, y;
  cin >> a >> b >> c >> d >> x >> y;
  if (abs(c - a) % x == 0 && abs(d - b) % x == 0) {
    if ((abs(c - a) / x) % 2 == 0 && (abs(d - b) / y) % 2 == 0)
      cout << "YES\n";
    else if ((abs(c - a) / x) % 2 == 1 && (abs(d - b) / y) % 2 == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else
    cout << "NO\n";
  return 0;
}
