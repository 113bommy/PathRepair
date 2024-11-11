#include <bits/stdc++.h>
using namespace std;
char str[11][11];
int f[8][20][20];
int dx[] = {0, 1, -1, -1, 1, 1, 0, -1}, dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
bool check() {
  memset(f, 0, sizeof f);
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++) {
      if (str[i][j] != 'X') continue;
      for (int k = 0; k < 4; k++) f[k][i][j] = f[k][i + dy[k]][j + dx[k]] + 1;
    }
  for (int i = 10; i >= 1; i--)
    for (int j = 10; j >= 1; j--) {
      if (str[i][j] != 'X') continue;
      for (int k = 4; k < 8; k++) f[k][i][j] = f[k][i + dy[k]][j + dx[k]] + 1;
    }
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++)
      for (int k = 0; k < 8; k++)
        if (f[k][i][j] >= 5) return 1;
  return 0;
}
int main() {
  for (int i = 1; i <= 10; i++) scanf("%s", str[i] + 1);
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++) {
      if (str[i][j] != '.') continue;
      str[i][j] = 'X';
      if (check()) {
        puts("YES");
        return 0;
      }
      str[i][j] = '.';
    }
  puts("NO");
  return 0;
}
