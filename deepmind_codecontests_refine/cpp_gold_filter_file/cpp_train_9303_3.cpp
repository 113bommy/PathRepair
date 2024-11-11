#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  long long arr[n];
  long long maxx = 0;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    maxx += arr[i];
  }
  maxx += k - n;
  if (m > maxx)
    cout << -1 << "\n";
  else {
    if (m <= k)
      cout << 0 << "\n";
    else {
      long long cnt = k, ans = 0;
      sort(arr, arr + n, greater<long long>());
      for (long long i = 0; i < n; i++) {
        cnt--;
        ans++;
        cnt += arr[i];
        if (cnt >= m) break;
      }
      cout << ans;
    }
  }
  return 0;
}
