#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, maxi = INT_MIN, mini = INT_MAX, ans = 0;
  cin >> n >> m;
  long long arr[n], brr[m];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    maxi = max(maxi, arr[i]);
  }
  for (long long i = 0; i < m; i++) {
    cin >> brr[i];
    mini = min(mini, brr[i]);
  }
  if (mini < maxi) {
    cout << "-1";
    return 0;
  }
  sort(arr, arr + n);
  sort(brr, brr + n);
  for (long long i = 0; i < n - 1; i++) ans += (m * arr[i]);
  for (long long i = 0; i < m; i++) ans += (brr[i]);
  if (mini == maxi) {
    cout << ans;
  } else {
    ans += maxi;
    ans -= arr[n - 2];
    cout << ans;
  }
}
