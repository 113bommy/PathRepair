#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
const int N = 505;
int n, m, b, mod, a[N], table[2][N][N];
int main() {
  scanf("%d %d %d %d", &n, &m, &b, &mod);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < 2; ++i) {
    for (int remb = 0; remb < N; ++remb) {
      table[i][remb][0] = 1;
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int remb = 0; remb <= b; ++remb) {
      for (int remc = 1; remc <= m; ++remc) {
        table[i % 2][remb][remc] = (table[(i + 1) % 2][remb][remc] % mod);
        if (remb - a[i % 2] >= 0)
          table[i % 2][remb][remc] =
              ((table[i % 2][remb][remc] % mod) +
               (table[i % 2][remb - a[i]][remc - 1] % mod)) %
              mod;
      }
    }
  }
  printf("%d\n", table[0][b][m]);
  return 0;
}
