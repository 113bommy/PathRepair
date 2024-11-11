#include <bits/stdc++.h>
using namespace std;
string st;
int dp[4][105];
int main() {
  int i, j, s;
  cin >> st;
  for (i = 0; i < st.size(); ++i)
    if (st[i] == 'Q') dp[1][i] = 1;
  for (i = 1; i < st.size(); ++i) {
    if (st[i] == 'A') {
      for (j = 0; j < i; ++j) {
        if (st[j] == 'Q') dp[2][i] += dp[1][j];
      }
    }
  }
  for (i = 2; i < st.size(); ++i) {
    if (st[i] == 'Q') {
      for (j = 0; j < i; ++j) {
        if (st[j] == 'A') dp[3][i] += dp[2][j];
      }
    }
  }
  s = 0;
  for (i = 0; i < st.size(); ++i) s += dp[3][i];
  cout << s;
  return 0;
}
