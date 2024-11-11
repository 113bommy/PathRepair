#include <bits/stdc++.h>
using namespace std;
int a[100010];
int n;
long long dp[100010];
int main() {
  cin.tie(nullptr);
  cin.sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    a[b]++;
  }
  dp[0] = a[0];
  dp[1] = max(a[0], a[1]);
  for (long long i = 2; i < 100010; i++) {
    dp[i] = max(i * a[i] + dp[i - 2], dp[i - 1]);
  }
  cout << dp[100010 - 1] << "\n";
}
