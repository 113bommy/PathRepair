#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("popcnt")
const long long N = 9e6 + 1;
const long long alp = 30;
const long long inf = 1e9 + 10;
const long long mod = 1e9;
const double EPS = -1e9;
const int bsz = 430;
const int R = 1 << 19;
const int MN = 450002;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  long long n, a;
  cin >> n;
  long double sum = 0;
  for (long long q = 0; q < n; q++) {
    cin >> a;
    sum += a;
  }
  cout << sum / n;
}
