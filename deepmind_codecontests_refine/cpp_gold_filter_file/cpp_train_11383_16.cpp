#include <bits/stdc++.h>
using namespace std;
long n, m, a[100001], d[1000001];
int main() {
  cin >> n;
  for (int k = 1; k <= n; ++k) cin >> a[k];
  long long ans = 0;
  for (int k = 1; k <= n - 1; ++k) {
    long t = 1;
    for (int k1 = 1; k1 <= 64; ++k1) {
      if (k + t > n) {
        break;
      }
      t *= 2;
    }
    t /= 2;
    ans += a[k];
    a[k + t] += a[k];
    cout << ans << endl;
  }
  return 0;
}
