#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
long long a[] = {3, 5, 7, 15, 35, 21, 105};
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, i, j, n, m, s, l, r;
  cin >> n;
  s = n / 2;
  for (i = 0; i < 7; i++) {
    l = n / a[i];
    l = (l / 2) + (l % 2);
    if (i < 3)
      s += l;
    else if (i < 6)
      s -= l;
    else
      s -= (2 * l);
  }
  cout << (n - s) << "\n";
  return 0;
}
