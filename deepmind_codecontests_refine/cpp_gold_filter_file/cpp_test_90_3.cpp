#include <bits/stdc++.h>
using namespace std;
int main() {
  ;
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long x, y;
    cin >> x >> y;
    if (x == y)
      cout << x << "\n";
    else if (x > y)
      cout << x + y << "\n";
    else {
      long long mod = (y / x) * x;
      cout << (mod + y) / 2 << "\n";
    }
  }
  return 0;
}
