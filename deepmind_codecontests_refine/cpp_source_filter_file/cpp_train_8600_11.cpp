#include <bits/stdc++.h>
using namespace std;
int q;
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(NULL);
  int dp[12] = {0, -1, -1, -1, 1, -1, 1, -1, 2, 1, 2, -1};
  int val[4] = {0, -1, 0, -2};
  cin >> q;
  for (int i = 0; i < q; i++) {
    int n = 0;
    cin >> n;
    if (n <= 11) {
      cout << dp[n] << endl;
      continue;
    }
    int ret = (n / 4) + val[n % 4];
    cout << ret << endl;
  }
}
