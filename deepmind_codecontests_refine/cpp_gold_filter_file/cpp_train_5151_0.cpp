#include <bits/stdc++.h>
using namespace std;
const int maxn = 30005, maxm = 205;
int f[maxn][maxm][2], g[maxn][maxm][2], n, k;
const int inf = 1 << 29;
inline void read(int &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
inline void judge() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
int main() {
  read(n);
  read(k);
  for (int i = (1); i <= (k); i++)
    for (int j = (0); j <= (i); j++) f[0][i][j] = g[0][i][j] = -inf;
  for (int i = (1); i <= (n); i++) {
    int x;
    read(x);
    for (int j = (1); j <= (k); j++) {
      int QAQ = 2 - (j == 1 || j == k);
      f[i][j][0] = max(f[i - 1][j][0] + QAQ * x, g[i - 1][j - 1][1] + QAQ * x);
      f[i][j][1] = max(f[i - 1][j][1] - QAQ * x, g[i - 1][j - 1][0] - QAQ * x);
      g[i][j][0] = max(f[i][j][0], g[i - 1][j][0]);
      g[i][j][1] = max(f[i][j][1], g[i - 1][j][1]);
      if (j > 1 && j < k) {
        g[i][j][0] = max(g[i][j][0], g[i - 1][j - 1][0]);
        g[i][j][1] = max(g[i][j][1], g[i - 1][j - 1][1]);
      }
    }
  }
  cout << max(g[n][k][0], g[n][k][1]);
  return 0;
}
