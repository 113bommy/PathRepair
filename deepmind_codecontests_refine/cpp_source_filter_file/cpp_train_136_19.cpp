#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
const long long int N = 1000005;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t, i, j, k;
  t = 1;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int lo = 0;
    long long int hi = 1e10;
    long long int ans;
    while (lo <= hi) {
      long long int mi = (lo + hi) / 2;
      long long int val = mi * b + c * b;
      if (val >= c * a) {
        ans = min(ans, mi);
        hi = mi - 1;
      } else
        lo = mi + 1;
    }
    cout << ans;
  }
  return 0;
}
