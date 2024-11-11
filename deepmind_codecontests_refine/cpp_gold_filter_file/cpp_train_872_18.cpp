#include <bits/stdc++.h>
using namespace std;
long long c[4][1010][1010];
inline int lb(int x) { return x & (-x); }
inline int gw(int x, int y) {
  int ans = 0;
  if (x & 1) ans += 1;
  if (y & 1) ans += 2;
  return ans;
}
inline void update(int x, int y, long long v) {
  int w = gw(x, y);
  for (int i = x; i < 1010; i += lb(i)) {
    for (int j = y; j < 1010; j += lb(j)) {
      c[w][i][j] ^= v;
    }
  }
}
long long query(int x, int y) {
  int w = gw(x, y);
  long long ans = 0;
  for (int i = x; i > 0; i -= lb(i)) {
    for (int j = y; j > 0; j -= lb(j)) {
      ans ^= c[w][i][j];
    }
  }
  return ans;
}
int main() {
  int n, m;
  memset(c, 0, sizeof(c));
  scanf("%d%d", &n, &m);
  int x1, y1, x2, y2, p;
  long long v;
  while (m--) {
    scanf("%d%d%d%d%d", &p, &x1, &y1, &x2, &y2);
    if (p == 1) {
      long long ans = query(x2, y2);
      ans ^= query(x2, y1 - 1);
      ans ^= query(x1 - 1, y2);
      ans ^= query(x1 - 1, y1 - 1);
      printf("%I64d\n", ans);
    } else {
      scanf("%I64d", &v);
      update(x1, y1, v);
      update(x1, y2 + 1, v);
      update(x2 + 1, y1, v);
      update(x2 + 1, y2 + 1, v);
    }
  }
  return 0;
}
