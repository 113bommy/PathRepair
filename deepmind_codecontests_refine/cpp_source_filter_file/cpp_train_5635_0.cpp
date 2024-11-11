#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n, k, lo = 1, hi, k1 = 1;
    cin >> n >> k;
    bool got = false;
    while (k1 <= n && k >= lo) {
      hi = lo;
      if (n > 31)
        hi = 1e18 + 1;
      else
        for (long long int kk = 1; kk <= k1; kk++)
          hi += (2 * (1LL << kk) - 3) *
                ((1LL << (n - kk)) * (1LL << (n - kk)) - 1);
      if (k >= lo && k <= hi) {
        cout << "YES " << n - k1 << '\n';
        got = true;
        break;
      }
      k1++;
      lo += (1LL << k1) - 1;
    }
    if (!got) cout << "NO\n";
  }
}
