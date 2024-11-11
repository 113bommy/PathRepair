#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(9);
  long long n, l, r;
  cin >> n >> l >> r;
  long long sum1 = 0, small = 1;
  long long sum2 = 0, big = 1;
  for (long long i = 1; i <= n; i++) {
    if (i <= l) {
      if (i == 1)
        sum1 += small;
      else {
        small = small * 2;
        sum1 += (small);
      }
    } else {
      sum1 += (1);
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (i <= r) {
      if (i == 1)
        sum2 += big;
      else {
        big = big * 2;
        sum2 += (big);
      }
    } else {
      sum2 += (big);
    }
  }
  cout << sum1 << " " << sum2;
}
