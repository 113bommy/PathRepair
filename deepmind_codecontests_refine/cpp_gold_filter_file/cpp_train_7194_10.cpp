#include <bits/stdc++.h>
using namespace std;
long long int n, A[106], dp[1006], pos[1006];
int main() {
  cin >> n;
  for (long long int i = 1; i <= n; i++) cin >> A[i];
  memset((pos), -1, sizeof((pos)));
  ;
  for (long long int i = 1; i <= n; i++) pos[A[i]] = i;
  pos[0] = 1e18;
  dp[1] = 1;
  for (long long int i = 1; i <= 1000; i++) {
    if (pos[i] == pos[i - 1] + 1) dp[i] = dp[i - 1] + 1;
  }
  dp[1000]++;
  cout << max(0LL, *max_element(dp, dp + 1000 + 1) - 1) << "\n";
}
