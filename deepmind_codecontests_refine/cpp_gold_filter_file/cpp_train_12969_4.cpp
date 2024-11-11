#include <bits/stdc++.h>
using namespace std;
double dp[1003][7303];
bool vs[1003][7303];
double k;
double fun(int rem, int d) {
  if (rem == 0) return 1;
  if (d == 0) return 0;
  if (vs[rem][d] != 0) return dp[rem][d];
  vs[rem][d] = 1;
  double ret =
      (rem / k) * fun(rem - 1, d - 1) + ((k - rem) / k) * fun(rem, d - 1);
  return dp[rem][d] = ret;
}
int main() {
  double q;
  cin >> k >> q;
  while (q--) {
    double p;
    cin >> p;
    int l = 1, r = 7300;
    int ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (fun(k, mid) >= p / 2000.0) {
        r = mid - 1;
        ans = mid;
      } else
        l = mid + 1;
    }
    cout << ans << endl;
  }
}
