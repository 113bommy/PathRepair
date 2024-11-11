#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[2001], dp[2001];
bool can(int num) {
  for (int i = 0; i < n; i++) dp[i] = i;
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
      if (abs(arr[i] - arr[j]) <= num * 1LL * (i - j))
        dp[i] = min(dp[i], dp[j] + i - j - 1);
  for (int i = 0; i < n; i++)
    if (dp[i] + (n - i - 1) <= k) return true;
  return false;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];
  long long lo = -1, hi = 2000000002;
  while (lo + 1 < hi) {
    long long mid = lo + (hi - lo) / 2;
    if (can(mid))
      hi = mid;
    else
      lo = mid;
  }
  cout << hi << endl;
}
