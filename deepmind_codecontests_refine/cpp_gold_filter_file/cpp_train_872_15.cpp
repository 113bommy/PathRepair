#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
const int maxn = 1010;
struct fen {
  long long t[maxn][maxn];
  fen() { memset(t, 0, sizeof(t)); }
  void modify(int x, int y, long long val) {
    for (int i = x; i < maxn; i |= (i + 1))
      for (int j = y; j < maxn; j |= (j + 1)) t[i][j] ^= val;
  }
  long long sum(int x, int y) {
    long long res = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
      for (int j = y; j >= 0; j = (j & (j + 1)) - 1) res ^= t[i][j];
    return res;
  }
};
fen S, R, L, T;
int mult(int xx) { return xx & 1; }
long long getrect(int i, int j) {
  if (i < 0 || j < 0) return 0;
  return S.sum(i, j) * mult((i + 1) * (j + 1)) ^ R.sum(i, j) * mult(i + 1) ^
         L.sum(i, j) * mult(j + 1) ^ T.sum(i, j);
}
long long getrect(int i1, int i2, int j1, int j2) {
  return getrect(i2, j2) ^ getrect(i1 - 1, j2) ^ getrect(i2, j1 - 1) ^
         getrect(i1 - 1, j1 - 1);
}
void xorrect(int i, int j, long long val) {
  S.modify(0, 0, val);
  S.modify(0, j + 1, val);
  S.modify(i + 1, 0, val);
  S.modify(i + 1, j + 1, val);
  R.modify(0, j + 1, val * mult(j + 1));
  R.modify(i + 1, j + 1, val * mult(j + 1));
  L.modify(i + 1, 0, val * mult(i + 1));
  L.modify(i + 1, j + 1, val * mult(i + 1));
  T.modify(i + 1, j + 1, val * mult((i + 1) * (j + 1)));
}
void xorrect(int i1, int i2, int j1, int j2, long long val) {
  xorrect(i2, j2, val);
  xorrect(i2, j1 - 1, val);
  xorrect(i1 - 1, j2, val);
  xorrect(i1 - 1, j1 - 1, val);
}
int n, m;
void out() {
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      int curans = getrect(i, i, j, j);
      printf("%d ", curans);
    }
    printf("\n");
  }
  printf("\n");
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int qt;
    scanf("%d", &qt);
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (qt == 1) {
      long long ans = getrect(x1, x2, y1, y2);
      printf("%I64d\n", ans);
    } else {
      long long val;
      scanf("%I64d", &val);
      xorrect(x1, x2, y1, y2, val);
    }
  }
  return 0;
}
