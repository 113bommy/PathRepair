#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long inf = 2e18 + 5;
long long pow2[64];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long s, t;
  s = n;
  t = 1;
  double ans = 0;
  while (s > 0) {
    ans += ((double)t) / s;
    s -= t;
  }
  cout << ans << endl;
  return 0;
}
