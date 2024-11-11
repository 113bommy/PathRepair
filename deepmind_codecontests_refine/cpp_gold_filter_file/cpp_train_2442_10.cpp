#include <bits/stdc++.h>
using namespace std;
const long long mod7 = 1000000007;
const long long inf = 1000000000000000000ll;
int dp[1001];
int arr[5][1001];
int arr2[5][1001];
int main() {
  int n, k;
  cin >> n >> k;
  for (int j = 0; j < k; ++j)
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &arr[j][i]);
      arr2[j][arr[j][i]] = i;
    }
  for (int i = 1; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      int add = 1;
      for (int p = 1; p < k; ++p) {
        if (arr2[p][arr[0][j]] < arr2[p][arr[0][i]]) add = 0;
      }
      if (add) dp[j] = max(dp[j], dp[i] + add);
    }
  }
  int ANS = 0;
  for (int i = 1; i <= n; ++i) {
    ANS = max(ANS, dp[i]);
  }
  cout << ANS + 1;
  return 0;
}
