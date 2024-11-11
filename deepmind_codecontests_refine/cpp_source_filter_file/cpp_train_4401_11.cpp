#include <bits/stdc++.h>
using namespace std;
const long long INF = (1LL << 60) - 1;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; ++i) cin >> arr[i];
    long long ans = 1;
    for (long long i = 0; i < n; ++i) {
      if (arr[i] == arr[i + 1]) {
        ans++;
      } else {
        ans = 1;
        break;
      }
    }
    cout << ans << "\n";
  }
}
