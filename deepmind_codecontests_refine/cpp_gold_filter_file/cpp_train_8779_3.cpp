#include <bits/stdc++.h>
using namespace std;
int memo[500][26][26];
int son[500][26][26];
int cambios[500][26][26];
vector<string> A;
int m, n;
void solve(int x, int y, int z) {
  for (int row = 0; row < x; row++)
    for (int a = 0; a < y; a++)
      for (int b = 0; b < z; b++) {
        int &res = memo[row][a][b];
        if (row == 0) {
          res = cambios[0][a][b];
          continue;
        }
        int mn = 1 << 29;
        for (int i = 0; i < 26; i++)
          if (i != a)
            for (int j = 0; j < 26; j++)
              if (j != b) {
                int tmp = memo[row - 1][i][j] + cambios[row][a][b];
                if (mn > tmp) mn = tmp, son[row][a][b] = 1000 * i + j;
              }
        res = mn;
      }
}
int main() {
  while (cin >> m >> n) {
    memset(memo, -1, sizeof(memo));
    A.clear();
    string cad;
    for (int i = 0; i < m; i++) cin >> cad, A.push_back(cad);
    reverse((A).begin(), (A).end());
    for (int row = 0; row < m; row++) {
      for (int a = 0; a < 26; a++)
        for (int b = 0; b < 26; b++)
          if (b != a) {
            int s = 0;
            for (int k = 0; k < n; k++) {
              if ((k & 1) == 0 && A[row][k] - 'a' != a) s++;
              if ((k & 1) == 1 && A[row][k] - 'a' != b) s++;
            }
            cambios[row][a][b] = s;
          } else
            cambios[row][a][b] = 1 << 29;
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
          cout << char(a + 'a');
        else
          cout << char(b + 'a');
      }
      cout << endl;
      int tmp = son[row][a][b];
      a = tmp / 1000;
      b = tmp % 1000;
    }
  }
}
