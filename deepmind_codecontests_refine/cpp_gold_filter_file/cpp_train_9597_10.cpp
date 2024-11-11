#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int mxN = 2001;
const ll MOD = 1e9 + 7;
ll dpr[mxN][mxN];
ll dpc[mxN][mxN];
bool board[mxN][mxN];
int psumrow[mxN][mxN];
int psumcol[mxN][mxN];
ll sumc[mxN], sumr;
int ptrr, ptrc[mxN];
int n, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    psumrow[i][0] = 0;
  }
  for (int i = 0; i < m; ++i) {
    psumcol[i][0] = 0;
  }
  for (int i = 0; i < n; ++i) {
    string k;
    cin >> k;
    for (int j = 0; j < m; ++j) {
      dpr[i][j] = 0;
      dpc[i][j] = 0;
      board[i][j] = (k[j] == 'R');
      psumrow[i][j + 1] = psumrow[i][j] + board[i][j];
    }
  }
  if (n == 1 && m == 1) {
    cout << (!board[0][0]) << "\n";
    return 0;
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      psumcol[i][j + 1] = psumcol[i][j] + board[j][i];
    }
  }
  for (int i = 0; i < m; ++i) {
    dpr[0][i] = psumrow[0][m] + i < m;
    sumc[i] = dpr[0][i];
  }
  for (int i = 0; i < n; ++i) {
    dpc[i][0] = psumcol[0][n] + i < n;
  }
  for (int i = 1; i < n; ++i) {
    ptrr = 0;
    sumr = dpc[i][0];
    for (int j = 1; j < m; ++j) {
      while (psumrow[i][m] - psumrow[i][ptrr + 1] > m - j - 1) {
        sumr = ((sumr - dpc[i][ptrr]) % MOD + MOD) % MOD;
        ptrr++;
      }
      dpr[i][j] = sumr;
      while (psumcol[j][n] - psumcol[j][ptrc[j] + 1] > n - i - 1) {
        sumc[j] = ((sumc[j] - dpr[ptrc[j]][j]) % MOD + MOD) % MOD;
        ptrc[j]++;
      }
      dpc[i][j] = sumc[j];
      sumc[j] = (sumc[j] + dpr[i][j]) % MOD;
      sumr = (sumr + dpc[i][j]) % MOD;
    }
  }
  cout << ((dpr[n - 1][m - 1] + dpc[n - 1][m - 1]) % MOD) << "\n";
  return 0;
}
