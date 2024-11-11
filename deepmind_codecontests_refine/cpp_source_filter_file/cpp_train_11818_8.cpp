#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000006;
long long dp[maxn];
int a[maxn], b[maxn];
bool marked[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cin >> b[a[i]];
    marked[a[i]] = true;
  }
  if (b[0] > 0) dp[0] = 1;
  for (int i = 1; i < maxn; i++) {
    if (!marked[i]) {
      dp[i] = dp[i - 1];
    } else {
      if ((i - b[i] - 1) < 0)
        dp[i] = 1;
      else
        dp[i] = dp[i - b[i] - 1] + 1;
    }
  }
  long long maxi = -1LL;
  for (int i = 1; i <= n; i++) maxi = max(maxi, dp[i]);
  cout << n - maxi << '\n';
  return 0;
}
