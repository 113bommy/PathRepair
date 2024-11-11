#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int mapa[1000001] = {0};
  int dp[1000001] = {0};
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    mapa[a] += 1;
    dp[a] = mapa[a];
  }
  for (int i = 2; i < 1000001; i++) {
    if (mapa[i]) {
      for (int j = 2 * i; j < 1000001; j += i) {
        if (mapa[j]) {
          dp[j] = max(dp[j], dp[i] + 1);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i < 1000001; i++) ans = max(ans, dp[i]);
  cout << ans << endl;
  return 0;
}
