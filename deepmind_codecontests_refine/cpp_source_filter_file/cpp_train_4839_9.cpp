#include <bits/stdc++.h>
using namespace std;
ifstream fin("in.in");
ofstream fout("out.out");
const int N = 2000 + 10;
int n, m, tmp[N][N], mat[N][N], sr[N][N], sc[N][N];
long long res[3];
inline void rotate() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) tmp[m - j + 1][i] = mat[i][j];
  swap(n, m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) mat[i][j] = tmp[i][j];
}
inline void init() {
  memset(sr, 0, sizeof sr);
  memset(sc, 0, sizeof sc);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) sr[i][j] = sr[i][j - 1] + mat[i][j];
  for (int j = 1; j <= m; j++)
    for (int i = 1; i <= n; i++) sc[i][j] = sc[i - 1][j] + mat[i][j];
}
inline void calc(int i, int l, int r) {
  if (r - l <= 1) return;
  int s = 0;
  for (int j = l; j < r - 1; j++) s += !sc[i][j] + !(sc[n][j] - sc[i][j]);
  for (int j = r; j > l; j--) {
    if (j > l + 1) {
      res[2] += (!sc[i][j] + !(sc[n][j] - sc[i][j])) * s;
      s -= !sc[i][j - 2] + !(sc[n][j - 2] - sc[i][j - 2]);
    }
    res[2] += !sc[i][j - 0] * !(sc[n][j - 1] - sc[i][j - 1]);
    res[2] += !sc[i][j - 1] * !(sc[n][j - 0] - sc[i][j - 0]);
  }
}
inline void solve() {
  for (int i = 2; i < n; i++) res[0] += !sr[i][m];
  for (int i = 2; i < n; i++)
    for (int j = 2; j < m; j++) res[1] += (!sr[i][j] && !sc[i][j]);
  for (int i = 2; i < n; i++) {
    int l = 1, r = 1;
    while (r < m - 1) {
      if (sr[i][m - 1] - sr[i][r] == m - r - 1) break;
      for (int j = r + 1; j < m; j++)
        if (!mat[i][j]) {
          l = j;
          break;
        }
      for (int j = l + 1; j < m; j++)
        if (mat[i][j]) {
          r = j - 1;
          break;
        }
      if (r < l) r = m - 1;
      calc(i, l, r);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      char in;
      cin >> in;
      mat[i][j] = (in == '#');
    }
  for (int i = 0; i < 4; i++) {
    init();
    solve();
    rotate();
  }
  cout << (res[0] + res[2]) / 2 + res[1] << endl;
  return 0;
}
