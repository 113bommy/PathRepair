#include <bits/stdc++.h>
using namespace std;
;
const long long INF64 = 0X3F3F3F3F3F3F3F3F;
const int INF32 = 0x3F3F3F3F;
const int mod = 1e6 + 3;
const int mod2 = 1e9 + 9;
const int N = 1e5 + 4;
int ti = 0;
int n, q;
int dp[255][255][255], id[26][255], len[3];
char reli[3][300];
char s[N];
void upd(int t, char op) {
  ++len[t];
  reli[t][len[t]] = op;
  for (int i = t == 0 ? len[0] : 0; i <= len[0]; ++i) {
    for (int j = t == 1 ? len[1] : 0; j <= len[1]; ++j) {
      for (int k = t == 2 ? len[2] : 0; k <= len[2]; ++k) {
        if (i || j || k) dp[i][j][k] = n + 1;
        if (i)
          dp[i][j][k] = min(dp[i][j][k], id[reli[0][i] - 'a'][dp[i - 1][j][k]]);
        if (j)
          dp[i][j][k] = min(dp[i][j][k], id[reli[1][j] - 'a'][dp[i][j - 1][k]]);
        if (k)
          dp[i][j][k] = min(dp[i][j][k], id[reli[2][k] - 'a'][dp[i][j][k - 1]]);
        ++ti;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  scanf("%d%d", &n, &q);
  scanf("%s", s + 1);
  for (int i = 0; i < 26; ++i) {
    id[i][n + 1] = id[i][n] = n + 1;
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) id[j][i] = id[j][i + 1];
    id[s[i + 1] - 'a'][i] = i + 1;
  }
  int t;
  char op[2];
  while (q--) {
    scanf("%s", op);
    scanf("%d", &t);
    --t;
    if (op[0] == '+') {
      scanf("%s", op);
      upd(t, op[0]);
    } else {
      --len[t];
    }
    if (dp[len[0]][len[1]][len[2]] != n + 1)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
