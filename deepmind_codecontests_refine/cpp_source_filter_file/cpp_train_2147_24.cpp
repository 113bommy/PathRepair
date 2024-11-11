#include <bits/stdc++.h>
using namespace std;
long long k[4], t[4], a[4][100001];
signed main() {
  long long n;
  cin >> k[1] >> k[2] >> k[3] >> t[1] >> t[2] >> t[3] >> n;
  long long ans = 0;
  for (long long x = 1; x <= n; x++) {
    long long y, z;
    cin >> y;
    z = y;
    for (long long o = 1; o <= 3; o++)
      a[o][z % k[o]] = max(a[o][z % k[o]], z) + t[o], z = a[o][z % k[o]];
    ans = max(ans, z - y);
  }
  cout << ans << endl;
}
