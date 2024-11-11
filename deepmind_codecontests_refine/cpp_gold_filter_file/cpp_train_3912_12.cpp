#include <bits/stdc++.h>
using namespace std;
int n;
char color[22];
int r[22], b[22];
int f[(1 << 16) + 5][111];
int nb[(1 << 16) + 5], nr[(1 << 16) + 5];
void update(int &f, int val) { f = max(f, val); }
int main() {
  scanf("%d", &n);
  int nblue = 0, nred = 0;
  for (int i = 0; i < n; ++i) {
    scanf("\n%c%d%d", &color[i], &r[i], &b[i]);
    if (color[i] == 'R')
      nred++;
    else
      nblue++;
  }
  if (nblue > 8) {
    swap(nblue, nred);
    for (int i = 0; i < n; ++i) {
      color[i] = (char)('R' + 'B' - color[i]);
      swap(r[i], b[i]);
    }
  }
  int sr = 0, sb = 0;
  for (int i = 0; i < n; ++i) sr += r[i], sb += b[i];
  for (int mask = 0; mask < (1 << n); ++mask) {
    for (int i = 0; i < n; ++i)
      if (mask & (1 << i)) {
        if (color[i] == 'R')
          ++nr[mask];
        else
          ++nb[mask];
      }
  }
  memset(f, -1, sizeof(f));
  f[0][0] = 0;
  for (int mask = 0; mask < (1 << n); ++mask)
    for (int db = 0; db <= 100; db++) {
      int cur = f[mask][db];
      if (cur < 0) continue;
      for (int i = 0; i < n; ++i)
        if (!(mask & (1 << i))) {
          int db2 = min(b[i], nb[mask]);
          int dr2 = min(r[i], nr[mask]);
          assert(db2 <= 100);
          update(f[mask | (1 << i)][db + db2], cur + dr2);
        }
    }
  int res = 1e9;
  for (int db = 0; db <= 100; db++) {
    int dr = f[(1 << n) - 1][db];
    if (dr >= 0) {
      int T = max(sb - db, sr - dr);
      assert(T < 1e9);
      res = min(res, T);
    }
  }
  printf("%d", res + n);
  return 0;
}
