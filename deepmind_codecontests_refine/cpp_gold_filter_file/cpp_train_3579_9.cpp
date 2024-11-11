#include <bits/stdc++.h>
using namespace std;
int dp[301][301];
bool solve(int n1, int n2) {
  if (!n1 && !n2) return 0;
  int &ret = dp[n1][n2];
  if (ret != -1) return ret;
  ret = 0;
  for (int i = 1; i <= n1; i++) ret |= (!solve(n1 - i, n2));
  for (int i = 1; i <= n2; i++) ret |= (!solve(n1, n2 - i));
  for (int i = 1; i <= min(n1, n2); i++) ret |= (!solve(n1 - i, n2 - i));
  return ret;
}
int main() {
  int N, x, y, z;
  string ret[] = {"BitLGM", "BitAryo"};
  cin >> N;
  if (N == 1) {
    cin >> x;
    if (x) {
      cout << ret[0] << "\n";
    } else
      cout << ret[1] << "\n";
  } else if (N == 2) {
    cin >> x >> y;
    memset(dp, -1, sizeof(dp));
    if (solve(x, y)) {
      cout << ret[0] << "\n";
    } else
      cout << ret[1] << "\n";
  } else {
    cin >> x >> y >> z;
    if (x ^ y ^ z) {
      cout << ret[0] << "\n";
    } else
      cout << ret[1] << "\n";
  }
  return 0;
}
