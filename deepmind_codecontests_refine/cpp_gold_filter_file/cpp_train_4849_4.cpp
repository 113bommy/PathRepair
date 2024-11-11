#include <bits/stdc++.h>
using namespace std;
char name[110][3000], text[110][3000];
int name_len[110], text_len[110];
bool found[110][110], dp[110][110];
int pre[110][110];
int chosen[110];
void variable_init() {
  memset(found, 0, sizeof found);
  memset(dp, 0, sizeof dp);
}
int main() {
  int tcase, n, m;
  scanf("%d", &tcase);
  while (tcase--) {
    variable_init();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%s", name[i]);
      name_len[i] = strlen(name[i]);
    }
    scanf("%d", &m);
    gets(text[0]);
    for (int i = 1; i <= m; i++) {
      gets(text[i]);
      text_len[i] = strlen(text[i]);
      if (text[i][0] != '?') {
        for (int k = 1; k <= n; k++) {
          bool ok = true;
          if (text_len[i] < name_len[k]) ok = false;
          for (int l = 0; l < name_len[k] && ok; l++) {
            if (text[i][l] != name[k][l]) ok = false;
          }
          ok &=
              (name_len[k] == text_len[i] || (!isalpha(text[i][name_len[k]]) &&
                                              !isdigit(text[i][name_len[k]])));
          if (ok) {
            bool found_others = false;
            int pre_choose;
            if (i == 1) {
              found_others = true;
              pre_choose = -1;
            }
            for (int j = 1; j <= n; j++)
              if (j != k && dp[i - 1][j]) {
                found_others = true;
                pre_choose = j;
                break;
              }
            dp[i][k] = found_others;
            pre[i][k] = pre_choose;
            break;
          }
        }
        continue;
      }
      for (int j = 0; j < text_len[i]; j++) {
        if (!isalpha(text[i][j]) && !isdigit(text[i][j])) {
          for (int k = 1; k <= n; k++) {
            bool ok = true;
            if (text_len[i] - 1 - j < name_len[k]) ok = false;
            for (int l = j + 1; l <= j + name_len[k] && ok; l++) {
              if (text[i][l] != name[k][l - (j + 1)]) ok = false;
            }
            ok &= (j + name_len[k] + 1 == text_len[i] ||
                   (!isalpha(text[i][j + name_len[k] + 1]) &&
                    !isdigit(text[i][j + name_len[k] + 1])));
            if (ok) found[i][k] = true;
          }
        }
      }
      for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
          if (i == 1) {
            if (!found[i][k]) {
              dp[i][k] = true;
              pre[i][k] = -1;
            }
          } else {
            if (j != k && dp[i - 1][j] && !found[i][k]) {
              dp[i][k] = true;
              pre[i][k] = j;
            }
          }
        }
      }
    }
    bool least_one = false;
    int last;
    for (int i = 1; i <= n; i++) {
      if (dp[m][i]) {
        least_one = true;
        last = i;
      }
    }
    if (!least_one)
      puts("Impossible");
    else {
      for (int i = m; i >= 1; i--) {
        chosen[i] = last;
        last = pre[i][last];
      }
      for (int i = 1; i <= m; i++) {
        if (text[i][0] == '?') {
          printf("%s", name[chosen[i]]);
          int pos;
          for (int j = 1; j < text_len[i]; j++)
            if (text[i][j] == ':') {
              pos = j;
              break;
            }
          puts(text[i] + pos);
        } else {
          puts(text[i]);
        }
      }
    }
  }
  return 0;
}
