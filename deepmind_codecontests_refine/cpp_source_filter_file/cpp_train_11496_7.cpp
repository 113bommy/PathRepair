#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int res[N][N][N][N], tmp[N][N], dat[N][N];
int n, m, q, a, b, c, d;
string s[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    for (int j = 1; j <= m; j++) {
      dat[i][j] = (s[i][j - 1] == '1');
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 || j == 0) continue;
      tmp[i][j] = tmp[i - 1][j] + tmp[i][j - 1] - tmp[i - 1][j - 1] + dat[i][j];
    }
  }
  for (int xa = 1; xa <= n; xa++) {
    for (int ya = 1; ya <= m; ya++)
      for (int xb = 1; xb <= n; xb++)
        for (int yb = 1; yb <= m; yb++) {
          int sum = tmp[xb][yb] - tmp[xa - 1][yb] - tmp[xb][ya - 1] +
                    tmp[xa - 1][ya - 1];
          res[xa][ya][xb][yb] = (sum == 0);
        }
  }
  for (int xa = n; xa >= 2; xa--)
    for (int ya = 1; ya <= m; ya++)
      for (int xb = xa; xb <= n; xb++)
        for (int yb = ya; yb <= m; yb++)
          res[xa - 1][ya][xb][yb] += res[xa][ya][xb][yb];
  for (int xa = 1; xa <= n; xa++)
    for (int ya = n; ya >= 2; ya--)
      for (int xb = xa; xb <= n; xb++)
        for (int yb = ya; yb <= m; yb++)
          res[xa][ya - 1][xb][yb] += res[xa][ya][xb][yb];
  for (int xa = 1; xa <= n; xa++)
    for (int ya = 1; ya <= m; ya++)
      for (int xb = xa; xb <= n; xb++)
        for (int yb = ya; yb <= m; yb++)
          res[xa][ya][xb + 1][yb] += res[xa][ya][xb][yb];
  for (int xa = 1; xa <= n; xa++)
    for (int ya = 1; ya <= m; ya++)
      for (int xb = xa; xb <= n; xb++)
        for (int yb = ya; yb <= m; yb++)
          res[xa][ya][xb][yb + 1] += res[xa][ya][xb][yb];
  while (q--) {
    cin >> a >> b >> c >> d;
    cout << res[a][b][c][d] << "\n";
  }
  return 0;
}
