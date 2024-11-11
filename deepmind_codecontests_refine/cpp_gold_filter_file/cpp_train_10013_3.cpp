#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long b, g, n;
  cin >> b >> g >> n;
  long long mn;
  if (n > b && n > g)
    cout << b + g - n + 1 << endl;
  else {
    mn = min(b, g);
    mn = min(mn, n);
    cout << mn + 1 << endl;
  }
}
