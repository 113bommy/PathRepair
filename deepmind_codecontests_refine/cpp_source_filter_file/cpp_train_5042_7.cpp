#include <bits/stdc++.h>
using namespace std;
void megumi() {
  int n;
  cin >> n;
  int p[n], dp[n + 1];
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  for (int i = 1; i <= n; i++)
    dp[i] =
        (dp[i - 1] + dp[i - 1] - dp[p[i - 1]] + 2 + 1000000007) % 1000000007;
  cout << dp[n];
}
int main() {
  ios_base::sync_with_stdio(false);
  megumi();
}
