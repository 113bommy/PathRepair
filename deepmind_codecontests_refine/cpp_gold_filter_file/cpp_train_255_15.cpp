#include <bits/stdc++.h>
using namespace std;
const int N = 22;
int n, m, a[N][N], b[N][N], qwq[N][N], f[1 << N];
char s[N][1000010];
void chkmx(int &x, int y) { (x < y) ? x = y : x = x; }
void chkmn(int &x, int y) { (x > y) ? x = y : x = x; }
int main() {
  scanf("%d", &n);
  ;
  scanf("%d", &m);
  ;
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  ;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int sum = 0, val = -1;
      for (int k = 1; k <= n; k++) {
        if (s[i][j] == s[k][j])
          sum += a[k][j], chkmx(val, a[i][j]), qwq[i][j] |= (1 << (k - 1));
      }
      b[i][j] = sum - val;
    }
  memset(f, 0x3f, sizeof(f));
  f[0] = 0;
  for (int i = 0; i <= (1 << n) - 1; i++)
    for (int j = 1; j <= n; j++)
      if (!(i & (1 << (j - 1))))
        for (int k = 1; k <= m; k++) {
          chkmn(f[i | (1 << (j - 1))], f[i] + a[j][k]),
              chkmn(f[i | qwq[j][k]], f[i] + b[j][k]);
        }
  printf("%d\n", f[(1 << n) - 1]);
  return 0;
}
