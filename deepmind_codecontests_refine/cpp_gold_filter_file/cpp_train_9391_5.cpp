#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, r, d1, d2;
    cin >> a >> b >> c >> r;
    if (a > b) {
      int temp = a;
      a = b;
      b = temp;
    }
    d1 = c - r;
    d2 = c + r;
    if ((d1 <= a && d2 <= a) || (d1 >= b && d2 >= b))
      cout << b - a << endl;
    else if (d1 >= a && d2 <= b)
      cout << d1 - a + b - d2 << endl;
    else if (d1 <= a && d2 >= b)
      cout << "0" << endl;
    else if (d1 < a)
      cout << max(b - d2, 0LL) << endl;
    else if (d1 >= a)
      cout << max(d1 - a, 0LL) << endl;
  }
}
