#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
long long ARR[maxn], dp[maxn];
int main() {
  long long int n, finaly = 1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ARR[i];
  }
  dp[0] = 1;
  dp[n - 1] = 1;
  for (int i = 1; i < n - 1; i++) {
    dp[i] = min(dp[i - 1] + 1, ARR[i]);
  }
  for (int i = n - 1; i > 0; i--) {
    dp[i] = min(dp[i + 1] + 1, dp[i]);
    finaly = max(finaly, dp[i]);
  }
  cout << finaly;
  return 0;
}
