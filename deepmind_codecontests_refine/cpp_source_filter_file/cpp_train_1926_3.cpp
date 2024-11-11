#include <bits/stdc++.h>
using namespace std;
const int N = 50;
int n, k;
char sign[2];
map<string, set<pair<int, int> > > req;
int dp[N][N << 1];
bool check(int x, int y, int L, int R) {
  if (x < 1 || y > (n << 1)) return false;
  if (req["<"].count(pair<int, int>(x, y)) ||
      req["<"].count(pair<int, int>(y, x)))
    return false;
  for (int i = L; i <= R; ++i) {
    if (req["<"].count(pair<int, int>(i, x)) ||
        req["<="].count(pair<int, int>(i, x)) ||
        req["="].count(pair<int, int>(i, x)) ||
        req["="].count(pair<int, int>(x, i)))
      return false;
    if (req["<"].count(pair<int, int>(i, y)) ||
        req["<="].count(pair<int, int>(i, y)) ||
        req["="].count(pair<int, int>(i, y)) ||
        req["="].count(pair<int, int>(y, i)))
      return false;
  }
  return true;
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0, x, y; i < k; ++i) {
    scanf("%d %s %d", &x, sign, &y);
    if (*sign == '>') swap(x, y), sign[0] = '<';
    req[sign].insert(pair<int, int>(x, y));
  }
  for (int i = 1; i + 1 <= n << 1; ++i)
    if (req["<"].count(pair<int, int>(i, i + 1)) == 0 &&
        req["<"].count(pair<int, int>(i + 1, i)) == 0)
      dp[1][i] = 1;
  for (int num = 1; num <= n; ++num) {
    for (int i = 1; i + (num << 1) - 1 <= n << 1; ++i)
      if (dp[num][i]) {
        if (check(i - 2, i - 1, i, i + (num << 1) - 1))
          dp[num + 1][i - 2] += dp[num][i];
        if (check(i - 1, i + (num << 1), i, i + (num << 1) - 1))
          dp[num + 1][i - 1] += dp[num][i];
        if (check(i + (num << 1), i + (num << 1) + 1, i, i + (num << 1) - 1))
          dp[num + 1][i] += dp[num][i];
      }
  }
  cout << dp[n][1] << endl;
  return 0;
}
