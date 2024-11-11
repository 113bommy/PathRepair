#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  t = 1;
  cin >> t;
  for (long long tc = 0; tc < t; tc++) {
    long long k;
    cin >> k;
    long long n = 7;
    vector<long long> arr(n + 1, 0), pre(n + 1);
    for (long long i1 = 1; i1 <= n; i1++) cin >> arr[i1];
    pre[1] = arr[1];
    for (long long i = 2; i <= n; i++) pre[i] = pre[i - 1] + arr[i];
    map<long long, long long> mp_indx;
    for (long long i = n; i >= 0; i--) mp_indx[pre[i]] = i;
    long long ans = LLONG_MAX;
    long long sum = pre[n];
    for (long long i = 1; i <= n; i++) {
      long long temp = pre[i - 1] + k;
      if (temp <= pre[n]) {
        long long indx = -1;
        for (long long j = i; j <= n; j++) {
          if (pre[j] == temp) {
            indx = j;
            break;
          }
        }
        if (indx != -1) ans = min(ans, indx - i + 1);
      } else {
        long long div = ceil((long double)(temp - sum) / (long double)sum);
        long long x = temp - div * sum, indx = -1;
        for (long long j = i; j <= n; j++) {
          if (pre[j] == x) {
            indx = j;
            break;
          }
        }
        if (indx != -1) {
          indx = indx + 7 * div;
          ans = min(ans, indx - i + 1);
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
