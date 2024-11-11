#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int dp[505] = {0};
  for (long long int i = 1; i <= 500; i++) dp[i] = dp[i - 1] + (i * (i - 1));
  long long int n;
  cin >> n;
  cout << dp[n];
}
