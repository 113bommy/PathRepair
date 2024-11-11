#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v, int n) {
  for (int i = 0; i < n; i++) cout << v[i] << " ";
}
int main() {
  int n;
  cin >> n;
  vector<vector<int>> dp(2, vector<int>((1 << 20) + 3, 0));
  dp[1][0] = 1;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  int pre = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    pre = pre ^ v[i];
    ans += dp[i % 2][pre];
    dp[i % 2][pre]++;
  }
  cout << ans << endl;
  return 0;
}
