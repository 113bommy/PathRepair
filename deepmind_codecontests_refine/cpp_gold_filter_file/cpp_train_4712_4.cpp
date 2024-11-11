#include <bits/stdc++.h>
using namespace std;
void func(long long int arr[], int n, long long int x) {
  if (arr[n - 1] * n < x) {
    printf("0\n");
    return;
  }
  int dp[n + 1];
  for (int i = 0; i <= n; i++) dp[i] = 0;
  int ans = INT_MIN;
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] >= x) {
      dp[i] = 1 + dp[i + 1];
    } else {
      float a = x;
      float b = arr[i];
      float c = ceil(a / b);
      if (c + i > n) {
        dp[i] = 0;
      } else {
        dp[i] = 1 + dp[i + (int)c];
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans;
  printf("\n");
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    long long int x;
    cin >> n >> x;
    long long int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    func(arr, n, x);
  }
}
