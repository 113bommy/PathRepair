#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const double eps = 1e-10;
const int inf = 0x3f3f3f3f;
const int N = 1e6 + 5;
char s[N];
int ans, len;
vector<int> dp[N];
void dfs(int &i, int dep) {
  if (i >= len) return;
  ans = max(ans, dep);
  dp[dep].push_back(i);
  while (s[i++] != ',')
    ;
  s[i - 1] = '\0';
  int cnt = 0;
  while (s[i] != ',' && s[i] != '\0') cnt = cnt * 10 + s[i++] - '0';
  s[i] = '\0';
  while (cnt--) {
    dfs(++i, dep + 1);
  }
}
int main() {
  while (~scanf("%s", s)) {
    ans = 0;
    len = strlen(s);
    for (int i = 1; i <= len; i++) dp[i].clear();
    for (int i = 0; i < len; i++) dfs(i, 1);
    printf("%d\n", ans);
    for (int i = 1; i <= ans; i++) {
      for (int j = 0; j < dp[i].size(); j++) {
        printf("%s ", s + dp[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
