#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
bool a[N];
int dp[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  dp[0] = (a[0]);
  for (int i = 1; i < n; i++) dp[i] = dp[i - 1] + a[i];
  int ans = 0;
  for (int i = 0; i < n; i++) ans += (!a[i] ? dp[i] : 0);
  cout << ans << endl;
  return 0;
}
