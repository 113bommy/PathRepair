#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 15;
long long x, y, dim_small, dim_large;
char c;
int32_t main() {
  ios::sync_with_stdio(0);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> c;
    if (c == '+') {
      cin >> x >> y;
      if (x > y) swap(x, y);
      dim_small = max(dim_small, x);
      dim_large = max(dim_large, x);
    } else {
      cin >> x >> y;
      if (x > y) swap(x, y);
      if (dim_small <= x and dim_large <= y)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}
