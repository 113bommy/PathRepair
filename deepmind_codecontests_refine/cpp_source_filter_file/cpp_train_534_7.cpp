#include <bits/stdc++.h>
using namespace std;
const int sz = 300300;
const int lgsz = 18;
int dp[sz][lgsz];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  memset(dp, 0x3f, sizeof dp);
  vector<int> last(lgsz, n);
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < lgsz; j++) {
      dp[i][j] = n;
    }
    for (int j = 0; j < lgsz; j++) {
      if ((v[i] >> j) & 1) {
        for (int k = 0; k < lgsz; k++) {
          dp[i][k] = min(dp[i][k], dp[last[j]][k]);
        }
        last[j] = i;
        dp[i][j] = i;
      }
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    bool answer = false;
    for (int j = 0; j < lgsz; j++) {
      if ((v[r] >> j) & 1) {
        if (dp[l][j] <= r) {
          answer = true;
          break;
        }
      }
    }
    cout << (answer ? "Shi\n" : "Fou\n");
  }
  return 0;
}
