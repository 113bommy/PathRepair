#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int num = 0;
  char c = getchar();
  if (c == '-') return -read();
  while (c >= '0' && c <= '9') {
    num = (num << 3) + (num << 1) + c - '0';
    c = getchar();
  }
  return num;
}
inline long long READ() {
  long long num = 0;
  char c = getchar();
  if (c == '-') return -READ();
  while (c >= '0' && c <= '9') {
    num = (num << 3) + (num << 1) + c - '0';
    c = getchar();
  }
  return num;
}
int dpa[57][57], dpb[57][57], dp[57][57];
int trn[27][27];
int k;
string A, B;
string s;
int a[57], b[57];
int main() {
  cin >> A >> B;
  int n = ((int)(A).size()), m = ((int)(B).size());
  for (int i = 1; i <= n; i++) {
    a[i] = A[i - 1] - 'a';
    dpa[i][i] |= (1 << (a[i]));
  }
  for (int j = 1; j <= m; j++) {
    b[j] = B[j - 1] - 'a';
    dpb[j][j] |= (1 << (b[j]));
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> s;
    trn[s[3] - 'a'][s[4] - 'a'] |= (1 << (s[0] - 'a'));
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 26; j++)
      if ((((trn[a[i]][a[i + 1]]) >> (j)) & 1)) dpa[i][i + 1] |= (1 << (j));
  for (int i = 1; i <= m; i++)
    for (int j = 0; j < 26; j++)
      if ((((trn[b[i]][b[i + 1]]) >> (j)) & 1)) dpb[i][i + 1] |= (1 << (j));
  for (int len = 3; len <= n; len++)
    for (int i = 1; i <= n - len + 1; i++) {
      int j = i + len - 1;
      for (int k = i; k < j; k++)
        for (int l1 = 0; l1 < 26; l1++)
          if ((((dpa[i][k]) >> (l1)) & 1))
            for (int l2 = 0; l2 < 26; l2++)
              if ((((dpa[k + 1][j]) >> (l2)) & 1)) dpa[i][j] |= trn[l1][l2];
    }
  for (int len = 3; len <= m; len++)
    for (int i = 1; i <= len - m + 1; i++) {
      int j = i + len - 1;
      for (int k = i; k < j; k++)
        for (int l1 = 0; l1 < 26; l1++)
          if ((((dpb[i][k]) >> (l1)) & 1))
            for (int l2 = 0; l2 < 26; l2++)
              if ((((dpb[k + 1][j]) >> (l2)) & 1)) dpb[i][j] |= trn[l1][l2];
    }
  memset((void*)dp, 0x7f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int a = 0; a < i; a++)
        for (int b = 0; b < j; b++)
          if (dpa[a + 1][i] & dpb[b + 1][j])
            dp[i][j] = min(dp[i][j], dp[a][b] + 1);
  if (dp[n][m] == ((int)0x7f7f7f7f))
    return printf("-1"), 0;
  else
    return printf("%d\n", dp[n][m]), 0;
  return 0;
}
