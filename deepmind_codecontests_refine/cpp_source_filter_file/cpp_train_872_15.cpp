#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e3 + 10;
const int INF = 1e9;
const int MOD = 1e9 + 7;
int n, m;
long long fen[4][MaxN][MaxN];
void upd(int r, int x, int y, long long val) {
  for (int i = x; i < MaxN; i |= i + 1) {
    for (int j = y; j < MaxN; j |= j + 1) {
      fen[r][i][j] ^= val;
    }
  }
}
long long get(int r, int x, int y) {
  long long res = 0;
  for (int i = x; i >= 0; i &= i + 1, --i) {
    for (int j = y; j >= 0; j &= j + 1, --j) {
      res ^= fen[r][i][j];
    }
  }
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int it = 1; it <= m; ++it) {
    int type, lx, ly, rx, ry;
    scanf("%d%d%d%d%d", &type, &lx, &ly, &rx, &ry);
    if (type == 2) {
      long long val;
      scanf("%lld", &val);
      upd((lx & 1) << 1 | (lx & 1), lx, ly, val);
      upd(((rx + 1) & 1) << 1 | (ly & 1), rx + 1, ly, val);
      upd((lx & 1) << 1 | ((ry + 1) & 1), lx, ry + 1, val);
      upd(((rx + 1) & 1) << 1 | ((ry + 1) & 1), rx + 1, ry + 1, val);
    } else {
      long long ans = get((rx & 1) << 1 | (ry & 1), rx, ry) ^
                      get(((lx - 1) & 1) << 1 | (ry & 1), lx - 1, ry) ^
                      get((rx & 1) << 1 | ((ly - 1) & 1), rx, ly - 1) ^
                      get(((lx - 1) & 1) << 1 | ((ly - 1) & 1), lx - 1, ly - 1);
      printf("%lld\n", ans);
    }
  }
  return 0;
}
