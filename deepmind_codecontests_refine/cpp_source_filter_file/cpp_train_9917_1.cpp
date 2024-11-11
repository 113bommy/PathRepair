#include <bits/stdc++.h>
using namespace std;
const int N = 250 + 10, M = 7e4;
int n, m, a[N][N], sig[M], pos1 = 1, pos2 = 1;
int m1[M], m2[M], id1[N], id2[N], tot;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
inline void work() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      a[i][j] = read();
      if (m1[i] < a[i][j]) {
        id1[i] = j;
        m1[i] = a[i][j];
      }
      if (m2[j] < a[i][j]) {
        id2[j] = i;
        m2[j] = a[i][j];
      }
    }
  }
  for (int i = 1; i <= n; ++i) sig[m1[i]] += 1, m1[i] = id1[i] = 0;
  for (int i = 1; i <= m; ++i) sig[m2[i]] += 2, m2[i] = id2[i] = 0;
  id1[n * m] = pos1, id2[n * m] = pos2;
  for (int i = n * m - 1; i > 0; --i) {
    if (!sig[i]) continue;
    if (sig[i] == 3) {
      ++pos1, ++pos2;
      int x = pos1, y = pos2 - 1;
      while (1) {
        if (y < 1) break;
        m1[++tot] = x, m2[tot] = y, --y;
      }
      x = pos1 - 1, y = pos2;
      while (1) {
        if (x < 1) break;
        m1[++tot] = x, m2[tot] = y, --x;
      }
    } else if (sig[i] == 1) {
      ++pos1;
      int x = pos1, y = pos2 - 1;
      while (1) {
        if (y < 1) break;
        m1[++tot] = x, m2[tot] = y, --y;
      }
    } else if (sig[i] == 2) {
      ++pos2;
      int x = pos1 - 1, y = pos2;
      while (1) {
        if (x < 1) break;
        m1[++tot] = x, m2[tot] = y, --x;
      }
    }
    id1[i] = pos1, id2[i] = pos2;
  }
  tot = 0;
  for (int i = n * m - 1; i > 0; --i) {
    if (!sig[i]) {
      ++tot;
      id1[i] = m1[tot];
      id2[i] = m2[tot];
    }
  }
  for (int i = n * m; i > 0; --i) sig[(id1[i] - 1) * m + id2[i]] = i;
  for (int i = 1; i <= n * m; ++i) {
    if (i % m)
      printf("%d ", sig[i]);
    else
      printf("%d\n", sig[i]);
  }
}
int main() {
  work();
  return 0;
}
