#include <bits/stdc++.h>
using namespace std;
int f[1100];
string s1, s2, pattern;
int n, m, sz;
int dp[110][110][110];
void build_failure_function() {
  f[0] = f[1] = 0;
  for (int i = 2; i <= sz; i++) {
    int j = f[i - 1];
    while (1) {
      if (pattern[j] = pattern[i - 1]) {
        f[i] = j + 1;
        break;
      }
      if (j == 0) {
        f[i] = 0;
        break;
      }
      j = f[j];
    }
  }
}
int find_next(int indx, char curr) {
  while (1) {
    if (curr == pattern[indx]) return indx + 1;
    if (indx == 0) return 0;
    indx = f[indx];
  }
  return indx;
}
int solve(int s1indx, int s2indx, int pttrnindx) {
  if (pttrnindx == sz) return -1e5;
  if (s1indx == n || s2indx == m) return 0;
  if (dp[s1indx][s2indx][pttrnindx] != -1) return dp[s1indx][s2indx][pttrnindx];
  int ans = max(solve(s1indx + 1, s2indx, pttrnindx),
                solve(s1indx, s2indx + 1, pttrnindx));
  if (s1[s1indx] == s2[s2indx])
    ans = max(
        ans,
        solve(s1indx + 1, s2indx + 1, find_next(pttrnindx, s1[s1indx])) + 1);
  dp[s1indx][s2indx][pttrnindx] = ans;
  return ans;
}
int main() {
  cin >> s1 >> s2 >> pattern;
  n = s1.size();
  m = s2.size();
  sz = pattern.size();
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++)
      for (int k = 0; k <= sz; k++) dp[i][j][k] = -1;
  build_failure_function();
  int ans = solve(0, 0, 0);
  if (ans == 0) {
    cout << "0";
    return 0;
  }
  int s1indx = 0, s2indx = 0, pttrnindx = 0;
  while (ans) {
    if (solve(s1indx + 1, s2indx, pttrnindx) == ans)
      s1indx++;
    else if (solve(s1indx, s2indx + 1, pttrnindx) == ans)
      s2indx++;
    else {
      pttrnindx = find_next(pttrnindx, s1[s1indx]);
      cout << s1[s1indx];
      ans--;
      s1indx++;
      s2indx++;
    }
  }
  return 0;
}
