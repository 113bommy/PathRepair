#include <bits/stdc++.h>
using namespace std;
char _;
int main() {
  int c, d, n, m, k, tot;
  cin >> c >> d >> n >> m >> k;
  tot = max(0, n * m - k);
  if (!tot) {
    cout << 0 << endl;
  } else {
    cout << min(min(c * (tot / n + (bool)(tot % n)), tot * d),
                c * tot / n + d * (tot % n))
         << endl;
  }
}
