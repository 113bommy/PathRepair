#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k, d, l, h, j;
  cin >> n >> k >> d;
  int arr[n + 1], dp[n + 1];
  dp[0] = 1;
  v.push_back(0);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  sort(arr + 1, arr + n + 1);
  for (int i = 1; i <= n; i++) {
    l = lower_bound(arr + 1, arr + i, arr[i] - d) - arr - 1;
    h = i - k;
    dp[i] = 0;
    if (l <= h) {
      j = lower_bound(v.begin(), v.end(), l) - v.begin();
      if (j <= h) {
        dp[i] = 1;
        v.push_back(i);
      }
    }
  }
  if (dp[n])
    cout << "YES";
  else
    cout << "NO";
}
