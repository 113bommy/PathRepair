#include <bits/stdc++.h>
using namespace std;
int const N = 1e6 + 10, oo = 1e9;
int mod = oo + 7;
long long const OO = 1e18;
char aa[402][402];
int cumR[402][402], cumC[402][402], cumD[402][402];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> aa[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cumR[i][j] = cumR[i][j - 1] + (aa[i][j] == '1');
  for (int j = 1; j <= m; j++)
    for (int i = 1; i <= n; i++)
      cumC[i][j] = cumC[i - 1][j] + (aa[i][j] == '1');
  for (int j = 1; j <= m; j++) {
    int i = 1, c = j;
    while (i <= n && c > 0) {
      cumD[i][c] = cumD[i - 1][c + 1] + (aa[i][c] == '1');
      i++;
      c--;
    }
  }
  for (int i = 1; i <= n; i++) {
    int r = 1, j = m;
    while (r <= n && j > 0) {
      cumD[r][j] = cumD[r - 1][j + 1] + (aa[r][j] == '1');
      r++;
      j--;
    }
  }
  int an = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (aa[i][j] == '1') continue;
      int r = i + 1, c = j + 1;
      while (r <= n && c <= m && aa[r][c] == '0') {
        if (cumR[r][c] == cumR[r][j - 1] && cumC[i][j] == cumC[r][j]) an++;
        int tc = c + c - j;
        if (tc <= m && cumR[i][j] == cumR[i][tc] &&
            cumD[i - 1][tc + 1] == cumD[r][c])
          an++;
        int tr = r + r - i;
        if (tr <= n && cumC[i][j] == cumC[tr][j] && cumD[r][c] == cumD[tr][j])
          an++;
        if (cumR[i][j] == cumR[i][c] && cumC[i - 1][c] == cumC[r][c]) an++;
        r++;
        c++;
      }
      r = i + 1, c = j + 1;
      while (r <= n && c <= m && aa[r][j] == '0' && aa[i][c] == '0') {
        if (cumD[i][c] == cumD[r][j]) an++;
        r++;
        c++;
      }
      r = i + 1, c = j - 1;
      while (r <= n && c > 0 && aa[r][c] == '0') {
        if (cumR[r][c] == cumR[r][j] && cumC[i][j] == cumC[r][j]) an++;
        r++;
        c--;
      }
      r = i + 1;
      c = j + 1;
      int l = j - 1;
      while (l > 0 && r <= n && c <= m && aa[r][c] == '0' && aa[r][l] == '0') {
        if (cumR[r][c] == cumR[r][l]) an++;
        r++;
        c++;
        l--;
      }
      r = i + 1, c = j + 1;
      int u = i - 1;
      while (u > 0 && r <= n && c <= m && aa[r][c] == '0' && aa[u][c] == '0') {
        if (cumC[r][c] == cumC[u][c]) an++;
        r++;
        c++;
        u--;
      }
    }
  }
  cout << an << endl;
  return 0;
}
