#include <bits/stdc++.h>
using namespace std;
int n, m;
char str[1111];
int a[1111][1111], mark[1111][1111], s[1111][1111];
int X[22], Y[22], R, C, Fate;
int mxr[1111], mxc[1111];
inline int fill(int x, int y, int a, int b) {
  int ans = 0;
  for (int i = (a); i <= (x); ++i)
    ans += ((mark[i][y] != Fate) + (mark[i][b] != Fate)),
        mark[i][y] = mark[i][b] = Fate;
  for (int i = (b); i <= (y); ++i)
    ans += ((mark[x][i] != Fate) + (mark[a][i] != Fate)),
        mark[x][i] = mark[a][i] = Fate;
  return ans;
}
inline int gsum(int x, int y, int a, int b) {
  return s[x][y] - s[x][b - 1] - s[a - 1][y] + s[a - 1][b - 1];
}
inline int glen(int x, int y, int a, int b) { return (x - a + y - b) * 2; }
inline int cmax(int x, int y) { return x > y ? x : y; }
inline bool cks(int i, int j, int i1, int j1) {
  return gsum(i, j, i1, j1) - gsum(i - 1, j - 1, i1 + 1, j1 + 1) ==
         glen(i, j, i1, j1);
}
inline int cross(int l, int r, int ll, int rr) {
  if (l > ll) swap(l, ll), swap(r, rr);
  if (rr <= r)
    return (rr - ll + 1);
  else if (ll <= r)
    return rr - r + 1;
}
void relax(int n, int mx[], int X[], int &R) {
  for (int i = (1); i <= (n); ++i)
    if (mx[i] > 2) X[++R] = i;
  if (R > 4) {
    X[3] = X[R - 1];
    X[4] = X[R];
    R = 4;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); ++i) {
    scanf("%s", &str);
    for (int j = (1); j <= (m); ++j) {
      a[i][j] = str[j - 1] == '#';
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    }
  }
  for (int i = (1); i <= (n); ++i) {
    int cnt = 0;
    for (int j = (1); j <= (m); ++j)
      mxr[i] = cmax(mxr[i], a[i][j] ? (++cnt) : (cnt = 0));
  }
  relax(n, mxr, X, R);
  for (int i = (1); i <= (m); ++i) {
    int cnt = 0;
    for (int j = (1); j <= (n); ++j)
      mxc[i] = cmax(mxc[i], a[j][i] ? (++cnt) : (cnt = 0));
  }
  relax(m, mxc, Y, C);
  for (int i = (1); i <= (R); ++i)
    for (int j = (1); j <= (C); ++j)
      for (int i1 = (1); i1 <= (i - 1); ++i1)
        for (int j1 = (1); j1 <= (j - 1); ++j1)
          for (int p = (1); p <= (R); ++p)
            for (int q = (1); q <= (C); ++q)
              for (int p1 = (1); p1 <= (p - 1); ++p1)
                for (int q1 = (1); q1 <= (q - 1); ++q1) {
                  if (X[i] - X[i1] < 2 || Y[j] - Y[j1] < 2 ||
                      X[p] - X[p1] < 2 || Y[q] - Y[q1] < 2)
                    continue;
                  if (!cks(X[i], Y[j], X[i1], Y[j1]) ||
                      !cks(X[p], Y[q], X[p1], Y[q1]))
                    continue;
                  ++Fate;
                  if (fill(X[i], Y[j], X[i1], Y[j1]) +
                          fill(X[p], Y[q], X[p1], Y[q1]) ==
                      s[n][m]) {
                    printf("YES\n%d %d %d %d\n%d %d %d %d\n", X[i1], Y[j1],
                           X[i], Y[j], X[p1], Y[q1], X[p], Y[q]);
                    return 0;
                  }
                }
  puts("NO");
}
