#include <bits/stdc++.h>
using namespace std;
const int MAX_LETTERS = 26;
const int MAX_LENGTH = 100001;
int dp[MAX_LENGTH][MAX_LETTERS];
int main(int argc, char* argv[]) {
  memset(dp, 0, sizeof(dp));
  string s;
  cin >> s;
  for (int i = s.size() - 2; i >= 0; --i) {
    int x = s[i + 1] - 'a';
    for (int j = 0; j < MAX_LETTERS; ++j) {
      dp[i][j] = dp[i + 1][j];
      if (j < x) {
        dp[i][j] += 1;
      }
    }
  }
  string res;
  for (int i = 0; i < s.size(); ++i) {
    if (dp[i][s[i] - 'a'] == 0) {
      res += s[i];
    }
  }
  cout << res;
}
