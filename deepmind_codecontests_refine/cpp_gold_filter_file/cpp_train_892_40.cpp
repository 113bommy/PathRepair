#include <bits/stdc++.h>
using namespace std;
const int N = 26;
vector<int> kmp;
string txt, pattern;
vector<vector<int> > nxt, dp;
void build() {
  kmp.resize(pattern.size() + 10);
  kmp[0] = 0;
  for (int i = 1, j = 0; i < pattern.size();) {
    if (pattern[i] == pattern[j])
      kmp[i++] = ++j;
    else if (!j)
      kmp[i++] = 0;
    else
      j = kmp[j - 1];
  }
  nxt.resize(pattern.size() + 10);
  for (int i = 0; i < pattern.size(); ++i) nxt[i].resize(N + 10);
  for (int j = 0; j < N; ++j) nxt[0][j] = (pattern[0] - 'a' == j);
  for (int i = 1; i < pattern.size(); ++i)
    for (int j = 0; j < N; ++j)
      nxt[i][j] = (pattern[i] - 'a' == j) ? i + 1 : nxt[kmp[i - 1]][j];
  dp.resize(txt.size() + 10);
  for (int i = 0; i < dp.size(); ++i) dp[i].resize(pattern.size() + 10);
  for (int i = 0; i < dp.size(); ++i)
    for (int j = 0; j < dp[i].size(); ++j) dp[i][j] = -1;
}
int solve(const int &i, const int &j) {
  if (i > txt.size()) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  int ans = 0;
  if (txt[i] == '?') {
    for (int k = 0; k < N; ++k) {
      int new_j = nxt[j][k];
      if (new_j == pattern.size())
        ans = max(ans, 1 + solve(i + 1, kmp[new_j - 1]));
      else
        ans = max(ans, solve(i + 1, new_j));
    }
  } else {
    int k = txt[i] - 'a';
    int new_j = nxt[j][k];
    if (new_j == pattern.size())
      ans = max(ans, 1 + solve(i + 1, kmp[new_j - 1]));
    else
      ans = max(ans, solve(i + 1, new_j));
  }
  return dp[i][j] = ans;
}
int main() {
  cin >> txt >> pattern;
  build();
  printf("%d\n", solve(0, 0));
  return 0;
}
