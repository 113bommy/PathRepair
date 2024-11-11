#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10], b[10][1005];
void Solve();
int main() {
  int tests = 1;
  scanf("%d", &tests);
  while (tests--) {
    Solve();
  }
  return 0;
}
void Solve() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (n); ++i) scanf("%d", a + i);
  for (int i = 0; i < (n); ++i)
    for (int j = 1; j <= (m); ++j) scanf("%1d", &b[i][j]);
  static int ans[1005];
  int maxdif = -1;
  for (int s = 0; s < (1 << n); ++s) {
    static int c[1005];
    for (int j = 1; j <= (m); ++j) c[j] = 0;
    for (int i = 0; i < (n); ++i)
      for (int j = 1; j <= (m); ++j) c[j] += b[i][j] ? s >> i & 1 ? -1 : 1 : 0;
    static int per[1005], val[1005];
    for (int j = 1; j <= (m); ++j) per[j] = j;
    sort(per + 1, per + m + 1, [&](int i, int j) { return c[i] < c[j]; });
    for (int j = 1; j <= (m); ++j) val[per[j]] = j;
    int dif = 0;
    for (int i = 0; i < (n); ++i) {
      int sc = 0;
      for (int j = 1; j <= (m); ++j)
        if (b[i][j]) sc += val[j];
      dif += abs(a[i] - sc);
    }
    if (dif > maxdif) {
      maxdif = dif;
      for (int j = 1; j <= (m); ++j) ans[j] = val[j];
    }
  }
  for (int j = 1; j <= (m); ++j) printf("%d%c", ans[j], " \n"[j == m]);
}
