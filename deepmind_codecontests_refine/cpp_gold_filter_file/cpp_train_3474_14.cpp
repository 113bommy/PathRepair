#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool getmin(T *a, const T &b) {
  if (b < *a) {
    *a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool getmax(T *a, const T &b) {
  if (b > *a) {
    *a = b;
    return true;
  }
  return false;
}
template <class T>
inline void read(T *a) {
  char c;
  while (isspace(c = getchar())) {
  }
  bool flag = 0;
  if (c == '-')
    flag = 1, *a = 0;
  else
    *a = c - 48;
  while (isdigit(c = getchar())) *a = *a * 10 + c - 48;
  if (flag) *a = -*a;
}
const int N = 1010;
int a[N][N], id[N][N], v[N][N], r[N][N], d[N][N];
int n, m, l;
long long ans[N * N], rw[N][N], vw[N][N], t[N][N], tw[N][N];
void rotate() {
  static int b[N][N], ip[N][N];
  swap(n, m);
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) b[i][j] = a[j][n - i + 1];
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) ip[i][j] = id[j][n - i + 1];
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) a[i][j] = b[i][j], id[i][j] = ip[i][j];
}
void solve() {
  for (int i = (l); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) {
      v[i][j] = 0;
      if (i == l)
        for (int k = (0); k <= (l - 1); ++k) v[i][j] += a[i - k][j];
      else
        v[i][j] = v[i - 1][j] - a[i - l][j] + a[i][j];
    }
  for (int i = (1); i <= (n); ++i)
    for (int j = (l); j <= (m); ++j) {
      r[i][j] = 0;
      if (j == l)
        for (int k = (0); k <= (l - 1); ++k) r[i][j] += a[i][j - k];
      else
        r[i][j] = r[i][j - 1] - a[i][j - l] + a[i][j];
    }
  for (int i = (l); i <= (n); ++i)
    for (int j = (1); j <= (m - l + 1); ++j) {
      d[i][j] = 0;
      if (i == l || j == m - l + 1)
        for (int k = (0); k <= (l - 1); ++k) d[i][j] += a[i - k][j + k];
      else
        d[i][j] = d[i - 1][j + 1] - a[i - l][j + l] + a[i][j];
    }
  for (int i = (l); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) {
      vw[i][j] = 0;
      if (i == l)
        for (int k = (0); k <= (l - 1); ++k)
          vw[i][j] += 1LL * a[i - k][j] * (l - k);
      else
        vw[i][j] = vw[i - 1][j] - v[i - 1][j] + 1LL * a[i][j] * l;
    }
  for (int i = (1); i <= (n); ++i)
    for (int j = (l); j <= (m); ++j) {
      rw[i][j] = 0;
      if (j == l)
        for (int k = (0); k <= (l - 1); ++k)
          rw[i][j] += 1LL * a[i][j - k] * (l - k);
      else
        rw[i][j] = rw[i][j - 1] - r[i][j - 1] + 1LL * a[i][j] * l;
    }
  for (int i = (l); i <= (n); ++i)
    for (int j = (l); j <= (m); ++j) {
      t[i][j] = 0;
      if (i == l && j == l)
        for (int k = (0); k <= (l - 1); ++k)
          for (int p = (0); p <= (l - 1); ++p) {
            if (k + p >= l) continue;
            t[i][j] += a[i - k][j - p];
          }
      else if (j == l)
        t[i][j] = t[i - 1][j] - d[i - 1][j - l + 1] + r[i][j];
      else
        t[i][j] = t[i][j - 1] - d[i][j - l] + v[i][j];
    }
  for (int i = (l); i <= (n); ++i)
    for (int j = (l); j <= (m); ++j) {
      tw[i][j] = 0;
      if (i == l && j == l)
        for (int k = (0); k <= (l - 1); ++k)
          for (int p = (0); p <= (l - 1); ++p) {
            if (k + p >= l) continue;
            tw[i][j] += 1LL * a[i - k][j - p] * (l - k - p);
          }
      else if (j == l)
        tw[i][j] = tw[i - 1][j] - t[i - 1][j] + rw[i][j];
      else
        tw[i][j] = tw[i][j - 1] - t[i][j - 1] + vw[i][j];
      ans[id[i][j]] += tw[i][j] - vw[i][j];
    }
}
int main() {
  read(&n);
  read(&m);
  read(&l);
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) read(&a[i][j]);
  int tot = 0;
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) id[i][j] = ++tot;
  for (int T = (0); T <= (3); ++T) {
    solve();
    rotate();
  }
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) ans[id[i][j]] += 1LL * a[i][j] * l;
  int x = 0, y = 0;
  for (int i = (l); i <= (n - l + 1); ++i)
    for (int j = (l); j <= (m - l + 1); ++j)
      if (ans[id[i][j]] >= ans[id[x][y]]) x = i, y = j;
  cout << x << ' ' << y << endl;
  return 0;
}
