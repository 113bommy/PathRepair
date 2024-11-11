#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y);
long long gcd(long long a, long long b);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  pair<long long, int> arr[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  long long dp[n + 1][4];
  long long maxm[n + 1][4];
  long long minm[n + 1][4];
  long long num[n + 1];
  sort(arr + 1, arr + n + 1);
  for (int i = 0; i <= n; i++) {
    num[i] = 1;
    for (int j = 0; j < 4; j++) {
      dp[i][j] = 0;
      maxm[i][j] = -1;
      minm[i][j] = INT64_MAX / 10;
    }
  }
  int total = 1;
  maxm[3][3] = max(arr[1].first, max(arr[2].first, arr[3].first));
  minm[3][3] = min(arr[1].first, min(arr[2].first, arr[3].first));
  dp[3][3] = maxm[3][3] - minm[3][3];
  for (int i = 4; i <= n; i++) {
    dp[i][1] = dp[i - 1][3];
    maxm[i][1] = arr[i].first;
    minm[i][1] = arr[i].first;
    if (dp[i - 1][1] != 0) {
      dp[i][2] = dp[i - 1][1];
      maxm[i][2] = max(arr[i].first, arr[i - 1].first);
      minm[i][2] = min(arr[i].first, arr[i - 1].first);
    }
    dp[i][3] = dp[i - 1][3] + arr[i].first - maxm[i - 1][3];
    maxm[i][3] = arr[i].first;
    minm[i][3] = minm[i - 1][3];
    if (dp[i - 1][2] != 0) {
      long long val =
          dp[i - 3][3] +
          max(arr[i].first, max(arr[i - 1].first, arr[i - 2].first)) -
          min(arr[i].first, min(arr[i - 1].first, arr[i - 2].first));
      if (val < dp[i][3]) {
        dp[i][3] = val;
        maxm[i][3] = max(arr[i].first, max(arr[i - 1].first, arr[i - 2].first));
        minm[i][3] = min(arr[i].first, min(arr[i - 1].first, arr[i - 2].first));
      }
    }
  }
  total = 1;
  memset(num, 0, sizeof(num));
  for (int i = n; i > 0;) {
    long long start = maxm[i][3];
    long long end = minm[i][3];
    for (; i > 0 && arr[i].first >= end; i--) {
      num[arr[i].second] = total;
    }
    total++;
  }
  cout << dp[n][3] << " " << total - 1 << "\n";
  for (int i = 1; i <= n; i++) cout << num[i] << " ";
  return 0;
}
long long power(long long x, long long y) {
  long long res = 1;
  x = x % 1000000007;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
