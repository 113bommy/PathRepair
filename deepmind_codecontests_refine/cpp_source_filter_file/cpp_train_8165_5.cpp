#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[100007];
  long long int dp[100007];
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) {
    int j;
    cin >> j;
    a[j]++;
  }
  dp[0] = 0;
  dp[1] = a[1];
  for (int i = 2; i <= 100000; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + i * a[i]);
  }
  cout << dp[n];
}
