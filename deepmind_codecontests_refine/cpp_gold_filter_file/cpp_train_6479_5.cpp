#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int inf = 1000000;
int dp[N][N][4], vi[N][N][4];
string s;
int solve(int p, int k, int flag) {
  if (p == s.size()) {
    if (!k)
      return 0;
    else
      return -inf;
  }
  int &ans = dp[p][k][flag];
  int &vis = vi[p][k][flag];
  if (vis) return ans;
  vis = 1;
  ans = -inf;
  int x;
  if (s[p] == 'T')
    x = 0;
  else
    x = 1;
  for (int i = 0; i <= k; ++i) {
    if (i % 2 == x) {
      ans = max(ans, solve(p + 1, k - i, (flag == 0 ? 2 : 0)));
    } else {
      ans = max(ans, flag - 1 + solve(p + 1, k - i, flag));
    }
  }
  return ans;
}
int solve1(int p, int k, int flag) {
  if (p == s.size()) {
    if (k == 0)
      return 0;
    else
      return inf;
  }
  int &ans = dp[p][k][flag];
  int &vis = vi[p][k][flag];
  if (vis) return ans;
  vis = 1;
  ans = inf;
  int x;
  if (s[p] == 'T')
    x = 0;
  else
    x = 1;
  for (int i = 0; i <= k; ++i) {
    if (i % 2 == x) {
      ans = min(ans, solve1(p + 1, k - i, (flag == 0 ? 2 : 0)));
    } else {
      ans = min(ans, flag - 1 + solve1(p + 1, k - i, flag));
    }
  }
  return ans;
}
int main() {
  int n;
  cin >> s >> n;
  int at = solve(0, n, 2);
  memset(vi, 0, sizeof(vi));
  at = max(at, -solve1(0, n, 2));
  cout << at << "\n";
  return 0;
}
