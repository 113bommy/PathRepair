#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long i, j, k, l, n, m;
    cin >> n;
    vector<long long> arr(n);
    for (i = 0; i < n; i++) cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    long long ans = 0;
    long long mx = -1e18;
    long long sz = 0;
    for (i = 0; i < n; i++) {
      sz += 1;
      mx = max(mx, arr[i]);
      if (sz >= mx) {
        sz = 0;
        mx = -1e18;
        ans++;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
