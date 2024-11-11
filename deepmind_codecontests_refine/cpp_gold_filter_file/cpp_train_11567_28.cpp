#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
int get_inter(const vector<long long>& cur) {
  printf("%d", cur.size() - 2);
  for (int i = 1; i <= (int)(cur.size() - 2); i++) printf(" %I64d", cur[i]);
  printf("\n");
  fflush(stdout);
  int x;
  scanf("%d", &x);
  return x;
}
long long dp[6][10005];
int main() {
  for (int i = 1; i <= (int)(10000); i++) dp[0][i] = 0;
  for (int i = 1; i <= (int)(5); i++)
    for (int j = 1; j <= (int)(10000); j++) {
      if (i == 5 && j > 1) continue;
      dp[i][j] = dp[i - 1][j];
      for (int k = 0; k < (int)(j); k++)
        dp[i][j] += dp[i - 1][min(j + dp[i][j] + 1, 10000LL)] + 1;
    }
  long long l = 1, r = 10004205361450474;
  int cr = 5;
  while (l <= r) {
    cr--;
    vector<long long> cur;
    cur.push_back(l - 1);
    while (cur.back() <= r) {
      long long ct = cur.back() + 1;
      ct += dp[cr][min(ct, 10000LL)];
      cur.push_back(ct);
    }
    if (cur.size() <= 2) continue;
    int k = get_inter(cur);
    if (k == -1) break;
    l = cur[k] + 1;
    r = cur[k + 1] - 1;
  }
  return 0;
}
