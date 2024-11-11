#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int len, n;
string str;
int dp[105][55][2][2];
int f(int idx, int n, int dir, bool mode) {
  if (n < 0) return -1000;
  if (idx == len) {
    if (n % 2 == 0) return 0;
    return -1000;
  }
  int &ret = dp[idx][n][dir][mode];
  if (~ret) return ret;
  ret = -1000;
  if (str[idx] == 'T')
    ret = max(f(idx + 1, n, !dir, mode),
              f(idx + 1, n - 1, dir, mode) + (dir == mode ? 1 : -1));
  if (str[idx] == 'F')
    ret = max(ret, max(f(idx + 1, n, dir, mode) + (dir == mode ? 1 : -1),
                       f(idx + 1, n - 1, !dir, mode)));
  return ret;
}
int main() {
  cin >> str >> n;
  len = (int)str.size();
  memset(dp, -1, sizeof dp);
  cout << max(f(0, n, 1, 1), f(0, n, 1, 0)) << endl;
}
