#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -f;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
inline void chkmin(int &a, int b) {
  if (a > b) a = b;
}
inline void chkmax(int &a, int b) {
  if (a < b) a = b;
}
int n, m;
bool g[105][105];
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    if (u <= 50 && v <= 50) g[u][v] = 1, g[v][u] = 1;
  }
  for (int i = 1; i <= min(50, n); i++)
    for (int j = 1; j <= min(50, n); j++)
      if (i != j) {
        int tmp = 0;
        if (g[i][j] == 1) tmp = 1;
        for (int k = 1; k <= min(50, n); k++)
          if (i != k && j != k) {
            if (g[i][k] != tmp || g[j][k] != tmp) continue;
            for (int l = 1; l <= min(50, n); l++)
              if (i != l && j != l && k != l) {
                if (g[i][l] != tmp || g[j][l] != tmp || g[k][l] != tmp)
                  continue;
                for (int q = 1; q <= min(50, n); q++)
                  if (i != q && j != q && k != q && l != q) {
                    if (g[i][q] != tmp || g[j][q] != tmp || g[k][q] != tmp ||
                        g[l][q] != tmp)
                      continue;
                    return printf("%d %d %d %d %d\n", i, j, k, l, q), 0;
                  }
              }
          }
      }
  return puts("-1"), 0;
}
