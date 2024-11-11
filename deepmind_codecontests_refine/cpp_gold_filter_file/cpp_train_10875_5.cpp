#include <bits/stdc++.h>
const int MAXN = 51;
const int MAXM = 1;
const int MAXL = 1;
using namespace std;
int n, m, a, b, A[51][51], ans = 2000000000;
int count(int x1, int y1, int x2, int y2) {
  int t = 0;
  for (int i = x1, _b = (x2); i <= _b; i++)
    for (int j = y1, _b = (y2); j <= _b; j++) t += A[i][j];
  return t;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, _n = (n); i < _n; i++)
    for (int j = 0, _n = (m); j < _n; j++) scanf("%d", &A[i][j]);
  scanf("%d%d", &a, &b);
  for (int i = 0, _n = (n - a + 1); i < _n; i++) {
    for (int j = 0, _n = (m - b + 1); j < _n; j++) {
      ans = min(ans, count(i, j, i + a - 1, j + b - 1));
    }
  }
  for (int i = 0, _n = (n - b + 1); i < _n; i++) {
    for (int j = 0, _n = (m - a + 1); j < _n; j++) {
      ans = min(ans, count(i, j, i + b - 1, j + a - 1));
    }
  }
  printf("%d\n", ans);
  return 0;
}
