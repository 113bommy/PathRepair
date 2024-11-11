#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
inline int FIX(long long a) { return (a % Mod + Mod) % Mod; }
vector<pair<int, int>> E;
string s;
int n;
int find_left(int p) {
  if (p < 0) p = n - 1;
  if (s[p] != 'A') return 0;
  return find_left(p - 1) + 1;
}
int find_right(int p) {
  if (p == n) p = 0;
  if (s[p] != 'B') return 0;
  return find_right(p + 1) + 1;
}
long long dp[100 + 5][2];
int main() {
  cin >> s;
  n = (int)s.length();
  for (int i = 0; i < s.length(); i++) {
    int L = i, R = (i + 1) % s.length();
    if (s[L] == 'A' && s[R] == 'B') {
      E.push_back(make_pair(find_left(L - 1), find_right(R + 1)));
    }
  }
  if (E.size() == 0) {
    cout << 1 << endl;
    return 0;
  }
  long long ret = 0;
  n = ((int)E.size());
  memset(dp, 0, sizeof(dp));
  if (E[0].first == 0) {
    dp[0][0] = dp[0][1] = 1;
  } else {
    if (E[0].second == 0) dp[0][1] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    if (dp[i][0] != 0) {
      if (E[i + 1].second == 0) {
        dp[i + 1][1] += dp[i][0];
      }
    }
    if (dp[i][1] != 0) {
      if (E[i + 1].first == 0) {
        dp[i + 1][0] += dp[i][1];
        dp[i + 1][1] += dp[i][1];
      } else {
        if (E[i + 1].second == 0) {
          dp[i + 1][1] += dp[i][1];
        }
      }
    }
  }
  ret += dp[n - 1][1];
  memset(dp, 0, sizeof(dp));
  if (E[0].second == 0) {
    dp[0][1] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    if (i == 2) {
    }
    if (dp[i][0] != 0) {
      if (E[i + 1].second == 0) {
        dp[i + 1][1] += dp[i][0];
      }
    }
    if (dp[i][1] != 0) {
      if (E[i + 1].first == 0) {
        dp[i + 1][0] += dp[i][1];
        dp[i + 1][1] += dp[i][1];
      } else {
        if (E[i + 1].second == 0) {
          dp[i + 1][1] += dp[i][1];
        }
      }
    }
  }
  ret += dp[n - 1][0];
  cout << ret << endl;
  return 0;
}
