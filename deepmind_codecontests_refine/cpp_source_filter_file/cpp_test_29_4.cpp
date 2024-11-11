#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long sum = 0;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum == 0) {
      cout << 0 << "\n";
      continue;
    } else {
      long long cnt = 0, res = 0, one = 0;
      if (sum == 1) {
        res = 1;
        for (long long i = n - 1; i >= 0; i--) {
          if (a[i] == 0) {
            res += pow(2LL, cnt);
            cnt++;
          }
        }
      } else {
        for (long long i = n - 1; i >= 0; i--) {
          if (a[i] == 0) {
            if (one) {
              res += pow(2LL, cnt);
            }
            cnt++;
          }
          if (a[i] == 1) {
            one++;
            res += pow(2LL, cnt);
          }
        }
      }
      cout << res << "\n";
    }
  }
  return 0;
}
