#include <bits/stdc++.h>
using namespace std;
int r, n, spaces;
bool u[105][3];
pair<int, int> pt[105];
int dp[105][3][3][3];
int grundy_number(int lo, int hi, int tl, int bl) {
  if (lo > hi) return 0;
  if (dp[lo][hi][tl][bl] == -1) {
    set<int> s;
    for (int i = lo; i <= hi; i++) {
      for (int j = 1; j <= 2; j++) {
        if (!u[i][1] && !u[i][2]) {
          if ((i != lo && !u[i - 1][3 - j]) || (i == lo && tl != 3 - j)) {
            if ((i != hi && !u[i + 1][3 - j]) || (i == hi && bl != 3 - j)) {
              s.insert(grundy_number(lo, i - 1, tl, j) ^
                       grundy_number(i + 1, hi, j, bl));
            }
          }
        }
      }
    }
    int ret = 0;
    while (s.find(ret) != s.end()) ret++;
    dp[lo][hi][tl][bl] = ret;
  }
  return dp[lo][hi][tl][bl];
}
int main() {
  scanf("%d %d", &r, &n);
  spaces = 2 * r;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &pt[i].first, &pt[i].second);
    u[pt[i].first][pt[i].second] = true;
  }
  memset(dp, -1, sizeof dp);
  int ans = grundy_number(1, r, 0, 0);
  if (ans)
    printf("WIN\n");
  else
    printf("LOSE\n");
  return 0;
}
