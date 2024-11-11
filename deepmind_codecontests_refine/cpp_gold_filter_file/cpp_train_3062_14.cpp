#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 1000, MAXM = 1300;
int n, m, k, g[MAXM], f[MAXN], Tohka;
short h[MAXN][MAXM];
inline int Read() {
  int first = 0;
  char ch = getchar();
  for (; !(ch >= '0' && ch <= '9'); ch = getchar())
    ;
  for (; (ch >= '0' && ch <= '9');
       first = first * 10 + ch - '0', ch = getchar())
    ;
  return first;
}
inline void init() {
  scanf("%d%d", &n, &k);
  m = min((int)sqrt(k) + 500, n);
  for (int i = 1; i <= k; ++i) {
    int first, second;
    first = Read();
    second = Read();
    first = n - first + 1;
    swap(first, second);
    if (second > m)
      Tohka += 3;
    else
      ++h[first][second];
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) h[i][j] += h[i][j - 1];
}
const int INF = (int)1e+10;
inline void solve() {
  for (int j = 1; j <= m; ++j)
    for (int k = 1; k <= j; ++k) g[j] += (int)h[k][j - k + 1];
  memset(f, 0x3f, sizeof(f));
  f[0] = 0;
  for (int i = 1; i <= n; ++i) {
    f[i] = min(f[i], f[i - 1] + (int)h[i][m] * 3);
    for (int j = 2; j <= m; ++j)
      if (j * (j + 1) / 2 + 2 < g[j] * 3) {
        int Houki = f[i - 1], a = j * (j + 1) / 2;
        for (int k = 1; k <= j; ++k) {
          Houki += (int)(h[i + k - 1][m] - h[i + k - 1][j - k + 1]) * 3;
          f[i + k - 1] = min(f[i + k - 1], Houki + a + 2);
          Houki = min(Houki, f[i + k - 1]);
        }
      }
    for (int j = 1; j < m; ++j) g[j] = g[j + 1] - (int)h[i][j + 1];
    g[m] = 0;
    for (int j = 1; j <= m; ++j) g[m] += (int)h[i + j][m - j + 1];
  }
  cout << f[n] + Tohka << endl;
}
int main() {
  init();
  solve();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
