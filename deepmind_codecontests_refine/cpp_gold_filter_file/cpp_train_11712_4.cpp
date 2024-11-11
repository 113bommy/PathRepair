#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int m, n, ecc, c;
string st;
long long ttans;
int f[maxn][maxn], g[maxn][maxn], wc[maxn], tq[maxn];
long long ts(int m, int n) {
  return (long long)m * n * (n - 1) / 2 + (long long)n * m * (m - 1) / 2;
}
void doit() {
  int j, e1, e2;
  memset(wc, 0, sizeof(wc));
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      if (f[i][j] == 1) wc[j] = i;
  for (int i = 1; i <= n; i++) {
    if (wc[i] == 0) continue;
    e1 = wc[i] - 1;
    j = i;
    while ((j > 1) && (wc[j - 1] < wc[j]) && (wc[j - 1] != 0)) {
      e1 += wc[j - 1] - 1;
      j--;
    }
    j = i;
    while ((j < n) && (wc[j + 1] < wc[j]) && (wc[j + 1] != 0)) {
      e1 += wc[j + 1] - 1;
      j++;
    }
    ttans += (long long)e1 * (m - wc[i]) * 2;
    e2 = m - wc[i];
    j = i;
    while ((j > 1) && (wc[j - 1] > wc[j])) {
      e2 += m - wc[j - 1];
      j--;
    }
    j = i;
    while ((j < n) && (wc[j + 1] > wc[j])) {
      e2 += m - wc[j + 1];
      j++;
    }
    ttans += (long long)e2 * (wc[i] - 1) * 2;
  }
}
int main() {
  memset(f, 0, sizeof(f));
  memset(tq, 0, sizeof(tq));
  ecc = 0;
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    cin >> st;
    for (int j = 0; j < n; j++)
      if (st[j] == '.')
        f[i][j + 1] = 0;
      else
        f[i][j + 1] = 1, ++ecc, tq[i] = j + 1;
  }
  ttans = 0;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
      c = (long long)ts(i, j) + ts(m - i + 1, j) + ts(i, n - j + 1) +
          ts(m - i + 1, n - j + 1);
      c -= (long long)ts(1, i) + ts(1, m - i + 1) + ts(1, j) + ts(1, n - j + 1);
      if (f[i][j] == 1)
        ttans -= c;
      else
        ttans += c;
    }
  for (int i = 1; i <= m; i++)
    for (int j = i + 1; j <= m; j++)
      if ((tq[i] != 0) && (tq[j] != 0))
        ttans += (abs(i - j) + abs(tq[i] - tq[j])) * 2;
  doit();
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) g[j][i] = f[i][j];
  swap(m, n);
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) f[i][j] = g[i][j];
  doit();
  printf("%.15lf\n", (double)ttans / ((double)(n * m - ecc) * (n * m - ecc)));
  return 0;
}
