#include <bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;
int n, h, f[1010][31][31][31][2];
void inc(int &x, int y) { x = x + y < mode ? x + y : x + y - mode; }
int main() {
  cin >> n >> h;
  h--;
  f[1][1][1][1][0] = 4;
  for (int i = 1; i < n; i++)
    for (int j = 1; j <= h + 1; j++)
      for (int k = 1; k <= h + 1; k++)
        for (int l = 1; l <= h + 1; l++)
          for (int s = 0; s <= 1; s++)
            if (f[i][j][k][l][s]) {
              int v = f[i][j][k][l][s];
              if (s && j == h + 1 && k == h + 1 && l == h + 1) continue;
              inc(f[i + 1][min(j + 1, h + 1)][min(k + 1, h + 1)]
                   [min(l + 1, h + 1)][s],
                  v);
              if (j != h + 1 || i >= n - h)
                inc(f[i + 1][s ? h + 1 : 1][min(k + 1, h + 1)]
                     [min(l + 1, h + 1)][j == h + 1],
                    v);
              else
                inc(f[i + 1][s ? h + 1 : 1][min(k + 1, h + 1)]
                     [min(l + 1, h + 1)][1],
                    v);
              if (k != h + 1 || i >= n - h)
                inc(f[i + 1][min(j + 1, h + 1)][s ? h + 1 : 1]
                     [min(l + 1, h + 1)][k == h + 1],
                    v);
              else
                inc(f[i + 1][min(j + 1, h + 1)][s ? h + 1 : 1]
                     [min(l + 1, h + 1)][1],
                    v);
              if (l != h + 1 || i >= n - h)
                inc(f[i + 1][min(j + 1, h + 1)][min(k + 1, h + 1)]
                     [s ? h + 1 : 1][l == h + 1],
                    v);
              else
                inc(f[i + 1][min(j + 1, h + 1)][min(k + 1, h + 1)]
                     [s ? h + 1 : 1][1],
                    v);
            }
  int ans = 0;
  for (int j = 1; j <= h + 1; j++)
    for (int k = 1; k <= h + 1; k++)
      for (int l = 1; l <= h + 1; l++)
        for (int s = 0; s <= 1; s++)
          if (!s || !(j == h + 1 && k == h + 1 && l == h + 1))
            inc(ans, f[n][j][k][l][s]);
  cout << ans;
}
