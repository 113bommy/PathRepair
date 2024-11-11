#include <bits/stdc++.h>
using namespace std;
long long c, d, n, m, k, ans, q, t, ost;
int main() {
  cin >> c >> d;
  cin >> n >> m;
  cin >> k;
  ans = k;
  if (n * d <= c) {
    q = n * m - ans;
    if (q <= 0)
      cout << 0 << endl;
    else
      cout << q * d << endl;
  } else {
    q = n * m - ans;
    if (q <= 0)
      cout << 0 << endl;
    else {
      if (q % n == 0)
        cout << (q / n) * c << endl;
      else {
        t = q / n;
        ost = q % n;
        if (ost * d <= c)
          cout << (q / n) * c + ost * d << endl;
        else
          cout << (q / n + 1) * c << endl;
      }
    }
  }
}
