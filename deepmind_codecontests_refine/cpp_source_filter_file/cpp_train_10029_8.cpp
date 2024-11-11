#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000;
const int MAXM = 1000000;
char str[MAXM + 10], B[MAXN + 10];
int L[MAXN + 10], R[MAXN + 10], id[MAXN + 10], nex[MAXM + 10][26];
pair<int, int> dp[MAXN + 10][MAXN + 10], NEX[MAXN + 10][26];
void cmp(pair<int, int>& a, pair<int, int> b) {
  if (a.first <= 0) a = b;
  a = min(a, b);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    L[i] = R[i - 1] + 1;
    scanf("%s", str + L[i]);
    R[i] = strlen(str + L[i]) + L[i] - 1;
    for (int j = R[i] - L[i] + 1; j >= 1; j--) {
      memcpy(nex[L[i] + j - 1], nex[L[i] + j], sizeof nex[L[i] + j - 1]);
      nex[L[i] + j - 1][str[L[i] + j - 1] - 'a'] = j;
    }
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &id[i]);
  for (int i = n; i >= 1; i--) {
    memcpy(NEX[i], NEX[i + 1], sizeof NEX[i]);
    for (int j = 0; j < 26; j++) {
      if (nex[L[id[i]]][j]) NEX[i][j] = make_pair(i, nex[L[id[i]]][j]);
    }
  }
  scanf("%s", B + 1);
  int m = strlen(B + 1);
  memset(dp, -1, sizeof dp);
  dp[0][0] = make_pair(0, 1);
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j && dp[i - 1][j - 1].first != -1) {
        pair<int, int> nexp;
        int cur_id = id[dp[i - 1][j - 1].first];
        int cur_pos = dp[i - 1][j - 1].second;
        if (cur_pos != R[cur_id] - L[cur_id] + 1 &&
            nex[L[cur_id] + cur_pos - 1][B[i] - 'a'])
          nexp = make_pair(dp[i - 1][j - 1].first,
                           nex[L[cur_id] + cur_pos - 1][B[i] - 'a']);
        else
          nexp = NEX[dp[i - 1][j - 1].first + 1][B[i] - 'a'];
        if (nexp.first > 0) cmp(dp[i][j], nexp);
      }
      if (dp[i][j].first > 0) ans = max(ans, j);
    }
  }
  printf("%d\n", ans);
  return 0;
}
