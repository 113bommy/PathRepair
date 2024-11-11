#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 10;
const int maxk = 1e5 + 10;
int opr[3][maxk];
bool mark[3][maxn];
int table[maxn][maxn];
bool tab[maxn][maxn];
int n, m, k, a, b, c;
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) cin >> opr[0][i] >> opr[1][i] >> opr[2][i];
  for (int i = k; i != 0; i--) {
    if (!mark[opr[0][i]][opr[1][i]]) {
      mark[opr[0][i]][opr[1][i]] = true;
      a = opr[2][i];
      b = opr[1][i];
      if (opr[0][i] == 1) {
        for (int i = 1; i <= m; i++) {
          if (!tab[i][b]) {
            tab[i][b] = true;
            table[i][b] = a;
            c++;
          }
        }
      } else {
        for (int i = 1; i <= n; i++) {
          if (!tab[b][i]) {
            tab[b][i] = true;
            table[b][i] = a;
            c++;
          }
        }
      }
      if (c == m * n) break;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cout << table[j][i] << ' ';
    cout << '\n';
  }
  return 0;
}
