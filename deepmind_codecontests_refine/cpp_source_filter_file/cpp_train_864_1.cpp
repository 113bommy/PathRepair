#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5;
const int ALPH = 26;
char s[MAXN + 1];
bool bad[ALPH + 1][ALPH + 1];
int dp[MAXN][27], N;
int main(void) {
  scanf("%s", s);
  N = strlen(s);
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    char c1, c2;
    scanf(" %c %c", &c1, &c2);
    bad[c1 - 'a'][c2 - 'a'] = 1;
    bad[c2 - 'a'][c1 - 'a'] = 1;
  }
  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j <= 26; j++) {
      dp[i][j] = dp[i + 1][j] + 1;
      if (!bad[j][s[i] - 'a']) {
        dp[i][j] =
            ((dp[i][j]) < (dp[i + 1][s[i] - 'a']) ? (dp[i][j])
                                                  : (dp[i + 1][s[i] - 'a']));
      }
    }
  }
  printf("%d\n", dp[0][26]);
  return 0;
}
