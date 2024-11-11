#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int p[N];
int dp[N];
int firstLeft = 1, secondLeft = 1;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + 20;
    while (firstLeft < i && p[firstLeft] + 90 <= p[i]) firstLeft++;
    while (secondLeft < i && p[secondLeft] + 1440 <= p[i]) secondLeft++;
    dp[i] = min(dp[i], dp[firstLeft - 1] + 50);
    dp[i] = min(dp[i], dp[secondLeft - 1] + 120);
    cout << dp[i] - dp[i - 1] << endl;
  }
}
