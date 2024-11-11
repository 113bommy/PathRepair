#include <bits/stdc++.h>
using namespace std;
long long n, a[100001], dp[100001];
int main() {
  cin >> n;
  for (long long i = 0, x; i < n; i++) {
    cin >> x;
    a[x]++;
  }
  dp[0] = a[0];
  for (long long i = 1; i < 100001; i++)
    dp[i] = max(dp[i - 1], dp[i - 2] + a[i] * i);
  cout << dp[100000];
}
