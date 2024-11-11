#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<int> type(n);
  vector<int> dp(n, 0);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    int b;
    cin >> b;
    type[i] = a;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (type[j] <= type[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
      }
    }
  }
  cout << n - ans << endl;
  return 0;
}
