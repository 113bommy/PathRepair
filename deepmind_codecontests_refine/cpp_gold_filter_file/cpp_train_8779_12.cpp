#include <bits/stdc++.h>
using namespace std;
int son[500][26][26];
int memo[500][26][26];
int cambios[500][26][26];
char A[500][500];
int m, n;
void solve(int x, int y, int z) {
  for (int row = 0; row < x; row++)
    for (int a = 0; a < y; a++)
      for (int b = 0; b < z; b++) {
        int &aux = son[row][a][b];
        int &res = memo[row][a][b];
        if (row == 0) {
          res = cambios[0][a][b];
          continue;
        }
        int mn = 1 << 29;
        for (int i = 0; i < 26; i++)
          if (i != a)
            for (int j = 0; j < 26; j++)
              if (j != b && j != i) {
                int tmp = memo[row - 1][i][j] + cambios[row][a][b];
                if (mn > tmp) mn = tmp, aux = 1000 * i + j;
              }
        res = mn;
      }
}
int main() {
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) scanf(" %c", &A[m - 1 - i][j]);
  for (int row = 0; row < m; row++) {
    for (int a = 0 + 'a'; a < 26 + 'a'; a++)
      for (int b = 0 + 'a'; b < 26 + 'a'; b++)
        if (b != a) {
          int s = 0;
          for (int k = 0; k < n; k++) {
            if ((k & 1) == 0 && A[row][k] != a) s++;
            if ((k & 1) == 1 && A[row][k] != b) s++;
          }
          cambios[row][a - 'a'][b - 'a'] = s;
        }
  }
  solve(m, 26, 26);
  int mn = 1 << 29;
  int a, b;
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < 26; j++)
      if (j != i) {
        if (mn > memo[m - 1][i][j]) mn = memo[m - 1][i][j], a = i, b = j;
      }
  printf("%d\n", mn);
  for (int row = m - 1; row >= 0; row--) {
    for (int i = 0; i < n; i++) {
      if ((i & 1) == 0)
        printf("%c", char(a + 'a'));
      else
        printf("%c", char(b + 'a'));
    }
    printf("\n");
    int tmp = son[row][a][b];
    a = tmp / 1000;
    b = tmp % 1000;
  }
}
