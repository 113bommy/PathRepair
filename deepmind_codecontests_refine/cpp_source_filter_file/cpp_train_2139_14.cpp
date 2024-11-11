#include <bits/stdc++.h>
using namespace std;
const int N = 4100;
char a[N], b[N];
int f[N][N];
int last[2][26];
int main() {
  int ti, td, tr, te;
  scanf("%d%d%d%d%s%s", &ti, &td, &tr, &te, a + 1, b + 1);
  int n = strlen(a + 1);
  int m = strlen(b + 1);
  memset(f, 0x3f3f3f, sizeof(f));
  f[0][0] = 0;
  for (int i = int(1); i <= int(n); ++i) f[i][0] = td * i;
  for (int i = int(1); i <= int(m); ++i) f[0][i] = ti * i;
  memset(last, -1, sizeof(last));
  for (int i = int(1); i <= int(n); ++i) {
    memset(last[1], -1, sizeof(last[1]));
    for (int j = int(1); j <= int(m); ++j) {
      f[i][j] = f[i - 1][j - 1] + tr;
      if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
      f[i][j] = min(f[i][j], f[i - 1][j] + td);
      f[i][j] = min(f[i][j], f[i][j - 1] + ti);
      int x = last[0][b[j] - 'a'], y = last[1][a[i] - 'a'];
      if (x != -1 && y != -1)
        f[i][j] = min(f[i][j], f[x - 1][y - 1] + te + (i - x - 1) * td +
                                   (j - y - 1) * te);
      last[1][b[j] - 'a'] = j;
    }
    last[0][a[i] - 'a'] = i;
  }
  cout << f[n][m] << endl;
}
