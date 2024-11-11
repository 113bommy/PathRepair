#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, sum = 0;
  cin >> n;
  vector<long long int> vec(n);
  map<long long int, long long int> cnt;
  vector<long long int> dp(100005);
  for (long long int i = 0; i < n; i++) {
    cin >> vec[i];
    cnt[vec[i]]++;
  }
  dp[1] = cnt[1];
  dp[0] = 0;
  for (long long int i = 2; i <= 100005; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
  }
  cout << dp[n];
  return 0;
}
