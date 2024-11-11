#include <bits/stdc++.h>
using namespace std;
static const int MAXN = 100 + 10;
char g[MAXN][MAXN];
int n, m, a, b, c;
int main() {
  scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
  bool flag = true;
  if (n % 2 && m % 2)
    flag = false;
  else if (n % 2) {
    for (int i = 1; i <= m; i += 2)
      if (a)
        a--, g[n][i] = g[n][i + 1] = '1';
      else
        flag = false;
    for (int i = 1; i <= n - 1; i += 2)
      for (int j = 1; j <= m; j += 2)
        if (c)
          c--, g[i][j] = g[i + 1][j] = g[i][j + 1] = g[i + 1][j + 1] = '3';
        else if (a > 1)
          a -= 2, g[i][j] = g[i + 1][j] = g[i][j + 1] = g[i + 1][j + 1] = '1';
        else if (b > 1)
          b -= 2, g[i][j] = g[i + 1][j] = g[i][j + 1] = g[i + 1][j + 1] = '2';
        else
          flag = false;
  } else if (m % 2) {
    for (int i = 1; i <= n; i += 2)
      if (b)
        b--, g[i][m] = g[i + 1][m] = '2';
      else
        flag = false;
    for (int i = 1; i <= n; i += 2)
      for (int j = 1; j <= m - 1; j += 2)
        if (c)
          c--, g[i][j] = g[i + 1][j] = g[i][j + 1] = g[i + 1][j + 1] = '3';
        else if (a > 1)
          a -= 2, g[i][j] = g[i + 1][j] = g[i][j + 1] = g[i + 1][j + 1] = '1';
        else if (b > 1)
          b -= 2, g[i][j] = g[i + 1][j] = g[i][j + 1] = g[i + 1][j + 1] = '2';
        else
          flag = false;
  } else {
    for (int i = 1; i <= n; i += 2)
      for (int j = 1; j <= m; j += 2)
        if (c)
          c--, g[i][j] = g[i + 1][j] = g[i][j + 1] = g[i + 1][j + 1] = '3';
        else if (a > 1)
          a -= 2, g[i][j] = g[i + 1][j] = g[i][j + 1] = g[i + 1][j + 1] = '1';
        else if (b > 1)
          b -= 2, g[i][j] = g[i + 1][j] = g[i][j + 1] = g[i + 1][j + 1] = '2';
        else
          flag = false;
  }
  if (flag) {
    for (int i = 0; i <= m + 1; i++) g[0][i] = g[n + 1][i] = 'i';
    for (int i = 1; i <= n; i++) g[i][0] = g[i][m + 1] = 'i';
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        bool vis[10] = {0};
        if (g[i][j] == '1') {
          if (isalpha(g[i - 1][j])) vis[g[i - 1][j] - 'a'] = true;
          if (isalpha(g[i - 1][j + 1])) vis[g[i - 1][j + 1] - 'a'] = true;
          if (isalpha(g[i][j - 1])) vis[g[i][j - 1] - 'a'] = true;
          if (isalpha(g[i][j + 2])) vis[g[i][j + 2] - 'a'] = true;
          if (isalpha(g[i + 1][j])) vis[g[i + 1][j] - 'a'] = true;
          if (isalpha(g[i + 1][j + 1])) vis[g[i + 1][j + 1] - 'a'] = true;
          for (int k = 0; k < 10; k++)
            if (!vis[k]) {
              g[i][j] = g[i][j + 1] = k + 'a';
              break;
            }
        } else if (g[i][j] == '2') {
          if (isalpha(g[i - 1][j])) vis[g[i - 1][j] - 'a'] = true;
          if (isalpha(g[i][j - 1])) vis[g[i][j - 1] - 'a'] = true;
          if (isalpha(g[i][j + 1])) vis[g[i][j + 1] - 'a'] = true;
          if (isalpha(g[i + 1][j - 1])) vis[g[i + 1][j - 1] - 'a'] = true;
          if (isalpha(g[i + 1][j + 1])) vis[g[i + 1][j + 1] - 'a'] = true;
          if (isalpha(g[i + 2][j])) vis[g[i + 2][j] - 'a'] = true;
          for (int k = 0; k < 10; k++)
            if (!vis[k]) {
              g[i][j] = g[i + 1][j] = k + 'a';
              break;
            }
        } else if (g[i][j] == '3') {
          if (isalpha(g[i - 1][j])) vis[g[i - 1][j] - 'a'] = true;
          if (isalpha(g[i - 1][j + 1])) vis[g[i - 1][j + 1] - 'a'] = true;
          if (isalpha(g[i][j - 1])) vis[g[i][j - 1] - 'a'] = true;
          if (isalpha(g[i][j + 2])) vis[g[i][j + 2] - 'a'] = true;
          if (isalpha(g[i + 1][j - 1])) vis[g[i + 1][j - 1] - 'a'] = true;
          if (isalpha(g[i + 1][j + 2])) vis[g[i + 1][j + 2] - 'a'] = true;
          if (isalpha(g[i + 2][j])) vis[g[i + 2][j] - 'a'] = true;
          if (isalpha(g[i + 2][j + 1])) vis[g[i + 2][j + 1] - 'a'] = true;
          for (int k = 0; k < 10; k++)
            if (!vis[k]) {
              g[i][j] = g[i + 1][j] = g[i][j + 1] = g[i + 1][j + 1] = k + 'a';
              break;
            }
        }
      }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) printf("%c", g[i][j]);
      printf("\n");
    }
  } else
    puts("IMPOSSIBLE");
  return 0;
}
