#include <bits/stdc++.h>
using namespace std;
const int n7 = 23, S7 = 33456;
int n, m, T, a[2][n7], b[3][105], wal;
long long f[n7][S7];
int rd() {
  int shu = 0;
  bool fu = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fu = 1;
    ch = getchar();
  }
  while (isdigit(ch)) shu = (shu << 1) + (shu << 3) + ch - '0', ch = getchar();
  return fu ? -shu : shu;
}
int main() {
  n = rd(), m = rd(), T = rd();
  for (int i = 1; i <= m; ++i) a[0][i] = rd() - 1, a[1][i] = rd() - 1;
  for (int i = 1; i <= T; ++i)
    b[0][i] = rd() - 1, b[1][i] = rd() - 1, b[2][i] = rd() - 1;
  wal = (1 << n) - 1;
  for (int o = 0; o <= n - 1; ++o) f[o][1 << o] = 1;
  for (int K = 0; K <= wal; ++K)
    for (int o = 0; o <= n - 1; ++o) {
      if (!(((K) >> (o)) & 1)) continue;
      int cho = -1;
      for (int i = 0; i <= n - 1; ++i) {
        if (i ^ o && (((K) >> (i)) & 1)) {
          cho = i;
          break;
        }
      }
      if (!~cho) continue;
      int tmp = K ^ (1 << o);
      for (int S = tmp; S; S = (S - 1) & tmp) {
        if (!(((S) >> (cho)) & 1)) continue;
        int v = -1;
        bool flag = 0;
        for (int i = 1; i <= T; ++i) {
          if ((((S) >> (b[2][i])) & 1) &&
              (!((((S) >> (b[0][i])) & 1) && (((S) >> (b[1][i])) & 1)))) {
            flag = 1;
            break;
          }
          if (b[2][i] == o && (((S) >> (b[0][i])) & 1) &&
              (((S) >> (b[1][i])) & 1)) {
            flag = 1;
            break;
          }
        }
        for (int i = 1; i <= m; ++i) {
          if (a[0][i] == o && (((S) >> (a[1][i])) & 1)) {
            if (!~v)
              v = a[1][i];
            else {
              flag = 1;
              break;
            }
          } else if (a[1][i] == o && (((S) >> (a[0][i])) & 1)) {
            if (!~v)
              v = a[0][i];
            else {
              flag = 1;
              break;
            }
          } else if ((((S) >> (a[0][i])) & 1) ^ (((S) >> (a[1][i])) & 1)) {
            flag = 1;
            break;
          }
        }
        if (flag) continue;
        if (!~v) {
          for (int i = 0; i <= n - 1; ++i) {
            if ((((S) >> (i)) & 1)) f[o][K] += f[o][K ^ S] * f[i][S];
          }
        } else
          f[o][K] += f[o][K ^ S] * f[v][S];
      }
    }
  printf("%lld", f[0][wal]);
  return 0;
}
