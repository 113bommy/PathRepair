#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
char ma[510][510];
long long row[510][510], col[510][510];
int main() {
  int h, w;
  char ch;
  scanf("%d %d", &h, &w);
  scanf("%c", &ch);
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) scanf("%c", &ma[i][j]);
    scanf("%c", &ch);
  }
  for (int i = 1; i <= h; ++i) {
    row[i][1] = 0;
    for (int j = 2; j <= w; ++j) {
      if (ma[i][j] == '.' && ma[i][j - 1] == '.')
        row[i][j] = row[i][j - 1] + 1;
      else
        row[i][j] = row[i][j - 1];
    }
  }
  for (int i = 1; i <= w; ++i) {
    col[1][i] = 0;
    for (int j = 2; j <= w; ++j) {
      if (ma[j][i] == '.' && ma[j - 1][i] == '.')
        col[j][i] = col[j - 1][i] + 1;
      else
        col[j][i] = col[j - 1][i];
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    long long ans = 0;
    for (int i = a; i <= c; ++i) {
      ans += (row[i][d] - row[i][b]);
    }
    for (int i = b; i <= d; ++i) ans += (col[c][i] - col[a][i]);
    cout << ans << endl;
  }
  return 0;
}
