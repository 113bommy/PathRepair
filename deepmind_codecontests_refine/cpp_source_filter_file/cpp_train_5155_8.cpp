#include <bits/stdc++.h>
using namespace std;
long long int tc = 1;
void solve() {
  long long int n, mini = INT_MAX, b, e, cnt = 0, flag = 1, prev = 0;
  cin >> n;
  long long int arr[n];
  for (long long int i = 0, j = 0, k = 0; i < n, j < n, k < n; i++, j++, k++) {
    cin >> arr[i];
    mini = min(mini, arr[i]);
  }
  long long int sum = mini * n;
  long long int maxi = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (arr[i] == mini) {
      if (flag) b = i, flag = 0;
      e = i + 1;
      cnt = i - prev;
      prev = i;
      maxi = max(maxi, cnt) - 1;
    }
  }
  maxi = max(maxi, ((n - e) + (b)));
  sum += maxi;
  cout << sum << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
