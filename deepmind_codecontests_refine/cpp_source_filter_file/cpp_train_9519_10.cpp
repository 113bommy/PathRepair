#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, d;
  int n, m, k;
  int ans = 0;
  cin >> c >> d >> n >> m >> k;
  if (k >= n * m)
    ans = 0;
  else {
    int tot = n * m - k;
    double f, l;
    f = c * 1.0 / n;
    l = d * 1.0 / m;
    if (f < l) {
      ans += (tot / n) * c;
      if (d * (tot % n) > c)
        ans += c;
      else
        ans += d * (tot % n);
    } else {
      ans += tot * d;
    }
  }
  cout << ans << endl;
  return 0;
}
