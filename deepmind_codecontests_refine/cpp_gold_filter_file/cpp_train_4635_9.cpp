#include <bits/stdc++.h>
using namespace std;
const int MAX = 505;
string ma[MAX];
int row[MAX][MAX], col[MAX][MAX], sumR[MAX][MAX], sumC[MAX][MAX];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> ma[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ma[i][j] == '#') continue;
      row[i][j] = 1;
      row[i][j] += (j > 0 && ma[i][j - 1] == '.' ? row[i][j - 1] : 0);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (row[i][j] >= 2) {
        sumR[i][j] = 1;
      }
      sumR[i][j] += (j > 0 ? sumR[i][j - 1] : 0);
    }
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (ma[i][j] == '#') continue;
      col[i][j] = 1;
      col[i][j] += (i > 0 && ma[i - 1][j] == '.' ? col[i - 1][j] : 0);
    }
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (col[i][j] >= 2) {
        sumC[i][j] = 1;
      }
      sumC[i][j] += (i > 0 ? sumC[i - 1][j] : 0);
    }
  }
  int q, a, b, c, d;
  cin >> q;
  while (q--) {
    int ans = 0;
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;
    for (int i = a; i <= c; i++) {
      if (b - 1 >= 0)
        ans += sumR[i][d] - sumR[i][b - 1];
      else
        ans += sumR[i][d];
      if (row[i][b] >= 2 && b - 1 >= 0)
        if (row[i][b] - row[i][b - 1] < 2) ans--;
    }
    for (int i = b; i <= d; i++) {
      if (a - 1 >= 0)
        ans += sumC[c][i] - sumC[a - 1][i];
      else
        ans += sumC[c][i];
      if (col[a][i] >= 2 && a - 1 >= 0)
        if (col[a][i] - col[a - 1][i] < 2) ans--;
    }
    cout << ans << '\n';
  }
  return 0;
}
