#include <bits/stdc++.h>
using namespace std;
long long arr[500005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int i, j, n, m, a, b, c, d, k, x, y, t;
  cin >> t;
  for (long long cz = 1; cz <= t; cz++) {
    cin >> a >> b >> c >> d >> k;
    if (a % c == 0)
      m = a / c;
    else
      m = a / c + 1;
    if (a % c == 0)
      j = b / d;
    else
      j = b / d + 1;
    if (m + j > k)
      cout << -1 << endl;
    else
      cout << m << " " << k - m << endl;
  }
}
