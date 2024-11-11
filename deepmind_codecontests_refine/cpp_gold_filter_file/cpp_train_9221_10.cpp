#include <bits/stdc++.h>
using namespace std;
int main() {
  iostream::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  const int MX = 1001;
  vector<int> us(MX);
  while (k--) {
    int x;
    cin >> x;
    us[x] = 1;
  }
  int cn = 0;
  for (int i : us) cn += i;
  const int MXA = 1001;
  vector<bitset<MX * MXA> > dp(MXA);
  dp[0][0] = 1;
  for (int i = 0; i < MX; i++) {
    if (!us[i]) continue;
    for (int j = 0; j < MXA - 1 && j < MXA / cn * 10; j++) {
      dp[j + 1] |= dp[j] << i;
    }
  }
  for (int j = 1; j < MXA; j++) {
    if (dp[j][j * n]) {
      cout << j;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
