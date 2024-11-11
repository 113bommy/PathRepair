#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long double h, c, k, sum = 0, x, l = 1, g = 1, d, y, s, r, q, o;
    cin >> h >> c >> k;
    if (h == k)
      cout << "1\n";
    else {
      sum = (h + c) / 2;
      s = abs(sum - k);
      if (sum == k)
        cout << "2\n";
      else {
        g = h - k;
        d = 2 * k;
        d = d - h - c;
        x = ceil(g / d);
        y = floor(g / d);
        l = (x * (h + c) + h) / (2 * x + 1);
        r = abs(k - l);
        o = (y * (h + c) + h) / (2 * y + 1);
        q = abs(k - o);
        if (r < s && r < q && r > 0)
          cout << (long long int)(2 * x + 1) << "\n";
        else if (q < s && r >= q && q > 0)
          cout << (long long int)(2 * y + 1) << "\n";
        else
          cout << "2\n";
      }
    }
  }
  return 0;
}
