#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int Maxn = 55;
const int Maxc = 27;
char s1[Maxn], s2[Maxn];
bool dp2[Maxn][Maxn][Maxc];
bool dp3[Maxn][Maxn][Maxc];
int dp[Maxn][Maxn];
vector<pair<int, int> > trans[Maxc];
int main() {
  scanf("%s", s1);
  scanf("%s", s2);
  int push;
  scanf("%d", &push);
  getchar();
  for (int i = 0; i < push; i++) {
    char a, b, c;
    scanf("%c->%c%c", &a, &b, &c);
    getchar();
    trans[a - 'a'].push_back(make_pair(b - 'a', c - 'a'));
  }
  int n = strlen(s1), m = strlen(s2);
  for (int i = 0; i < n; i++) {
    dp2[i][i][s1[i] - 'a'] = true;
  }
  for (int l = 2; l <= n; l++) {
    for (int i = 0; i < n; i++) {
      int j = i + l - 1;
      if (j >= n) continue;
      for (int ch = 0; ch < 26; ch++) {
        for (int k = i; k < j; k++) {
          for (int q = 0; q < trans[ch].size(); q++) {
            int fr = trans[ch][q].first, ed = trans[ch][q].second;
            dp2[i][j][ch] |= (dp2[i][k][fr] & dp2[k + 1][j][ed]);
          }
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    dp3[i][i][s2[i] - 'a'] = true;
  }
  for (int l = 2; l <= m; l++) {
    for (int i = 0; i < m; i++) {
      int j = i + l - 1;
      if (j >= n) continue;
      for (int ch = 0; ch < 26; ch++) {
        for (int k = i; k < j; k++) {
          for (int q = 0; q < trans[ch].size(); q++) {
            int fr = trans[ch][q].first, ed = trans[ch][q].second;
            dp3[i][j][ch] |= (dp3[i][k][fr] & dp3[k + 1][j][ed]);
          }
        }
      }
    }
  }
  for (int i = 0; i < Maxn; i++) {
    for (int j = 0; j < Maxn; j++) {
      dp[i][j] = 1e9;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 1; k <= i; k++) {
        for (int l = 1; l <= j; l++) {
          bool c = false;
          for (int ch = 0; ch < 26; ch++) {
            if (dp2[k - 1][i - 1][ch] && dp3[l - 1][j - 1][ch]) {
              c = true;
            }
          }
          if (c) {
            dp[i][j] = min(dp[i][j], dp[k - 1][l - 1] + 1);
          }
        }
      }
    }
  }
  if (dp[n][m] == 1e9) {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", dp[n][m]);
  return 0;
}
