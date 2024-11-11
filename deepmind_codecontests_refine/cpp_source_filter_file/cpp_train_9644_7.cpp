#include <bits/stdc++.h>
using namespace std;
int k;
string s;
int dp[1234][1234][3];
int get(int idx, int x, int f) {
  if (x == 0) return 1;
  if (idx == s.size()) return 0;
  if (dp[idx][x][f] != -1) return dp[idx][x][f];
  if (f == 1) {
    int res = 0;
    res = get(idx + 1, x - 1, 1);
    res = (res + get(idx + 1, x, 1)) % 1000000007;
    return dp[idx][x][f] = res;
  } else {
    int res = 0;
    if (s[idx] == '1') {
      res = get(idx + 1, x - 1, 0);
      res = (res + get(idx + 1, x, 1)) % 1000000007;
    } else {
      res = get(idx + 1, x, 0);
    }
    return dp[idx][x][f] = res;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> s >> k;
  int a[1010];
  a[1] = 0;
  for (int i = 2; i < 1010; i++) {
    a[i] = a[__builtin_popcount(i)] + 1;
  }
  if (k == 0) {
    cout << 1 << '\n';
    return 0;
  }
  if (k == 1) {
    if (s == "1")
      cout << "0" << '\n';
    else
      cout << get(0, 1, 0) << '\n';
    return 0;
  }
  int ans = 0;
  for (int i = 2; i < 1010; i++) {
    if (a[i] == k - 1) {
      ans = (ans + get(0, i, 0)) % 1000000007;
    }
  }
  cout << ans << '\n';
  return 0;
}
