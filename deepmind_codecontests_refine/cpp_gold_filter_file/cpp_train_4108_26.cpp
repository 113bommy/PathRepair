#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 10;
const int MOD = 1000000007;
const double PI = 4 * atan(1);
const double eps = 1e-4;
int n;
int arr[MAXN];
int nums[MAXN];
long long dp[MAXN][2];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    nums[arr[i]]++;
  }
  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[1][0] = 0;
  dp[1][1] = nums[1];
  for (int i = 2; i <= 1e5; i++) {
    dp[i][0] = dp[i - 1][1];
    dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + 1LL * i * nums[i];
  }
  cout << max(dp[100000][0], dp[100000][1]);
}
