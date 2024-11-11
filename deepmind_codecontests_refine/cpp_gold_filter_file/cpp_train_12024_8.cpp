#include <bits/stdc++.h>
const int SIZE = 1e6 + 5;
using namespace std;
int n, lim;
int arr[SIZE];
int dp[SIZE];
bool cnt[SIZE];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    cnt[arr[i]] = 1;
  }
  int res = 0;
  for (int i = 1; i < SIZE; i++) {
    dp[i] += cnt[i];
    res = max(res, dp[i]);
    for (int j = 2 * i; j < SIZE; j += i)
      if (dp[j] < dp[i]) dp[j] = dp[i];
  }
  cout << res;
}
