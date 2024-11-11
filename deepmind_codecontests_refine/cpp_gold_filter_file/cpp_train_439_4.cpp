#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e18 + 10, M = 2e5 + 137;
long long a[M];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long x, y;
    cin >> x >> y;
    long long ma = max(x, y);
    long long mi = min(x, y);
    if (ma - mi >= mi)
      cout << mi << "\n";
    else
      cout << (ma - mi) + (2 * (mi - (ma - mi)) / 3) << "\n";
  }
}
