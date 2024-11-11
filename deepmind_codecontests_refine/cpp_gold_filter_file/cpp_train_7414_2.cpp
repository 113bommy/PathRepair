#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long N = 1005;
const long long BLK = 666;
long long dr[4] = {0, 0, 1, -1};
long long dc[4] = {1, -1, 0, 0};
long long ddr[8] = {0, 0, 1, -1, 1, -1, 1, -1};
long long ddc[8] = {1, -1, 0, 0, 1, -1, -1, 1};
long long ddr1[8] = {1, 1, -1, -1, 2, 2, -2, -2};
long long ddc1[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int32_t main() {
  fast();
  long long t, z;
  cin >> t;
  for (long long z = 1; z < t + 1; z++) {
    long long n, p, k;
    cin >> n >> p >> k;
    long long a[n + 1];
    a[0] = 0;
    for (long long i = 1; i < n + 1; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    long long ans = 0, pf = 0;
    for (long long i = 0; i < k; i++) {
      pf += a[i];
      long long mysum = pf, cnt = 0;
      if (mysum <= p) cnt = i;
      for (long long j = i + k; j <= n; j += k) {
        mysum += a[j];
        if (mysum <= p) cnt = j;
      }
      ans = max(ans, cnt);
    }
    cout << ans << "\n";
  }
}
