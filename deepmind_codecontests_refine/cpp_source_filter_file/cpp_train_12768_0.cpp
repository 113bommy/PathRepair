#include <bits/stdc++.h>
using namespace std;
char giv[10005];
int fa[10005], now[10005];
int dp[10005][2][105];
list<int> rua[10005];
const int inf = 1000000;
void memset(int* f, int len, int x) {
  for (int i = 0; i < len; i++) f[i] = x;
}
void change() {
  int n = strlen(giv);
  int i, j = 0, a = 0, b;
  for (i = 0; i < n; i++) {
    if (giv[i] == '(') {
      rua[j].push_back(++a);
      fa[a] = j;
      j = a;
      continue;
    }
    if (giv[i] == ')') {
      j = fa[j];
      continue;
    }
    if (giv[i] == '?') {
      continue;
    }
    rua[j].push_back(++a);
    fa[a] = j;
    now[a] = giv[i] - '0';
  }
  for (i = 0; i <= a; i++) {
    memset(dp[i][0], 105, inf * -1);
    memset(dp[i][1], 105, inf);
  }
}
int use[10005][2][105], ouo;
void play(int x, int h) {
  if (now[x]) {
    dp[x][0][0] = now[x];
    dp[x][1][0] = now[x];
    return;
  }
  list<int>::iterator p;
  for (p = rua[x].begin(); p != rua[x].end(); p++) {
    play(*p, h);
  }
  p = rua[x].begin();
  ouo++;
  int i, j, a, b;
  for (i = 0; i <= 100; i++) {
    use[ouo][0][i] = dp[*p][0][i];
    use[ouo][1][i] = dp[*p][1][i];
  }
  for (p++; p != rua[x].end(); p++) {
    memset(use[++ouo][0], 105, inf * -1);
    memset(use[ouo][1], 105, inf);
    a = ouo - 1;
    b = *p;
    for (i = 0; i <= 100; i++) {
      if (use[a][0][i] != inf * -1) {
        for (j = 0; i + j <= 100; j++) {
          if (dp[b][0][j] != inf * -1) {
            if (!h) {
              use[ouo][0][i + j + 1] =
                  max(use[ouo][0][i + j + 1], dp[b][0][j] + use[a][0][i]);
              use[ouo][1][i + j + 1] =
                  min(use[ouo][1][i + j + 1], dp[b][1][j] + use[a][1][i]);
              use[ouo][0][i + j] =
                  max(use[ouo][0][i + j], use[a][0][i] - dp[b][1][j]);
              use[ouo][1][i + j] =
                  min(use[ouo][1][i + j], use[a][1][i] - dp[b][0][j]);
            } else {
              use[ouo][0][i + j] =
                  max(use[ouo][0][i + j], dp[b][0][j] + use[a][0][i]);
              use[ouo][1][i + j] =
                  min(use[ouo][1][i + j], dp[b][1][j] + use[a][1][i]);
              use[ouo][0][i + j + 1] =
                  max(use[ouo][0][i + j + 1], use[a][0][i] - dp[b][1][j]);
              use[ouo][1][i + j + 1] =
                  min(use[ouo][1][i + j + 1], use[a][1][i] - dp[b][0][j]);
            }
          } else
            break;
        }
      } else
        break;
    }
  }
  for (i = 0; i <= 100; i++) {
    dp[x][0][i] = use[ouo][0][i];
    dp[x][1][i] = use[ouo][1][i];
  }
}
int main() {
  int x, y;
  scanf("%s%d%d", giv, &x, &y);
  change();
  if (x > y) {
    play(0, 0);
    printf("%d", dp[0][0][x]);
  } else {
    play(0, 1);
    printf("%d", dp[0][0][y]);
  }
  return 0;
}
