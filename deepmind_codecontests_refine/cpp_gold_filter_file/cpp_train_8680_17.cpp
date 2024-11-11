#include <bits/stdc++.h>
using namespace std;
const int N = 104;
const long long INF = 1e4, P = 1e9 + 7;
long long snum, n, m, C[N][N], f[2][N][N][N], ans;
void upd(long long &x, long long k) { (x += k) %= P; }
int main(int argc, char *argv[]) {
  cin >> n >> m >> snum;
  C[0][0] = 1;
  for (int i = 1; i <= (n); ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= (i); ++j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);
      if (C[i][j] > INF) C[i][j] = INF;
    }
  }
  for (int i = 1; i <= (n); ++i) f[1][i][i][1] = 1ll;
  for (int i = 1; i <= (m); ++i) {
    int now = i % 2, nxt = !now;
    memset(f[nxt], 0, sizeof(f[nxt]));
    for (int j = 1; j < (n); ++j)
      for (int k = 1; k <= (n); ++k)
        for (int l = 1; l <= (snum); ++l) {
          if (f[now][j][k][l]) {
            for (int t = k; t <= (n - j); ++t) {
              long long nl = l * C[t - 1][k - 1];
              if (nl <= snum) {
                upd(f[nxt][j + t][t - k][nl], f[now][j][k][l]);
              }
            }
          }
        }
    long long sum = 0;
    if (i > 1) {
      for (int j = 1; j <= (n); ++j)
        for (int l = 1; l <= (snum); ++l) {
          upd(sum, f[now][j][0][l]);
          if (f[now][j][0][l])
            ;
        }
    }
    ans = (ans + sum * (m - i + 1) % P) % P;
  }
  cout << ans << endl;
  return 0;
}
