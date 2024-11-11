#include <bits/stdc++.h>
using namespace std;
long long dp[2005][2005][4], vis[2005][2005][4];
long long x, y, z;
string str;
long long DP(int i, int j, int k) {
  if (j == y) return 0;
  if (i == x) {
    return 1e7;
  }
  if (vis[i][j][k] == z) return dp[i][j][k];
  vis[i][j][k] = z;
  long long value = 1e7;
  if (k == 0) {
    if (str[i] == 'R') {
      value = min(value, DP(i + 1, j + 1, 1));
      value = min(value, 1 + DP(i + 1, j + 1, 2));
      value = min(value, 1 + DP(i + 1, j + 1, 3));
    } else if (str[i] == 'G') {
      value = min(value, 1 + DP(i + 1, j + 1, 1));
      value = min(value, DP(i + 1, j + 1, 2));
      value = min(value, 1 + DP(i + 1, j + 1, 3));
    } else if (str[i] == 'B') {
      value = min(value, 1 + DP(i + 1, j + 1, 1));
      value = min(value, 1 + DP(i + 1, j + 1, 2));
      value = min(value, DP(i + 1, j + 1, 3));
    }
  } else {
    if (k == 1) {
      if (str[i] == 'G') {
        value = min(value, DP(i + 1, j + 1, 2));
        value = min(value, 1 + DP(i + 1, 1, 1));
        value = min(value, 1 + DP(i + 1, 1, 3));
      } else {
        value = min(value, 1 + DP(i + 1, j + 1, 2));
        value = min(value, 1 + DP(i + 1, 1, 1));
        value = min(value, 1 + DP(i + 1, 1, 3));
      }
    } else if (k == 2) {
      if (str[i] == 'B') {
        value = min(value, 1 + DP(i + 1, 1, 2));
        value = min(value, 1 + DP(i + 1, 1, 1));
        value = min(value, DP(i + 1, j + 1, 3));
      } else {
        value = min(value, 1 + DP(i + 1, 1, 2));
        value = min(value, 1 + DP(i + 1, 1, 1));
        value = min(value, 1 + DP(i + 1, j + 1, 3));
      }
    } else {
      if (str[i] == 'R') {
        value = min(value, 1 + DP(i + 1, 1, 2));
        value = min(value, DP(i + 1, j + 1, 1));
        value = min(value, 1 + DP(i + 1, 1, 3));
      } else {
        value = min(value, 1 + DP(i + 1, 1, 2));
        value = min(value, 1 + DP(i + 1, j + 1, 1));
        value = min(value, 1 + DP(i + 1, 1, 3));
      }
    }
  }
  value = min(value, DP(i + 1, j, k));
  return dp[i][j][k] = value;
}
int main() {
  long long T;
  cin >> T;
  T = T * (-1);
  map<char, int> mp;
  mp['R'] = 1;
  mp['G'] = 2;
  mp['B'] = 3;
  for (int i = T; i <= -1; i++) {
    z = i;
    cin >> x >> y;
    cin >> str;
    cout << DP(0, 0, 0) << endl;
  }
}
