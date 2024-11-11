#include <bits/stdc++.h>
using namespace std;
int n;
inline void update(long long *t, int y, long long v) {
  while (y <= n) t[y] ^= v, y += y & -y;
}
inline long long query(long long *t, int y) {
  long long ans = 0;
  while (y) ans ^= t[y], y -= y & -y;
  return ans;
}
long long t[2][2][1010][1010];
inline void update(int x, int y, long long v) {
  int i = x % 2;
  int j = y % 2;
  x = (x + 1) / 2;
  y = (y + 1) / 2;
  while (x <= n) update(t[i][j][x], y, v), x += x & -x;
}
inline long long query(int id1, int id2, int x, int y) {
  if (x % 2 != id1) x--;
  if (y % 2 != id2) y--;
  x = (x + 1) / 2;
  y = (y + 1) / 2;
  long long ans = 0;
  while (x) ans ^= query(t[id1][id2][x], y), x -= x & -x;
  return ans;
}
inline long long query(int id1, int id2, int x1, int y1, int x2, int y2) {
  return query(id1, id2, x2, y2) ^ query(id1, id2, x2, y1 - 1) ^
         query(id1, id2, x1 - 1, y2) ^ query(id1, id2, x1 - 1, y1 - 1);
}
int main() {
  int m;
  while (~scanf("%d %d", &n, &m)) {
    n = (n + 1) / 2;
    memset(t, 0, sizeof(t));
    while (m--) {
      int x1, y1, x2, y2;
      int type;
      long long v;
      scanf("%d %d %d %d %d", &type, &x1, &y1, &x2, &y2);
      if (type == 2) {
        scanf("%I64d", &v);
        update(x1, y1, v);
        update(x1, y2 + 1, v);
        update(x2 + 1, y1, v);
        update(x2 + 1, y2 + 1, v);
      } else {
        long long ans = 0;
        int dx = x2 - x1 + 1;
        int dy = y2 - y1 + 1;
        if (dx % 2 == 1 && dy % 2 == 1 && x1 > 1 && y1 > 1) {
          for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) ans ^= query(i, j, x1 - 1, y1 - 1);
        }
        if (dy % 2 == 1 && y1 > 1) {
          ans ^= query(x2 & 1, 0, x1, 1, x2, y1 - 1) ^
                 query(x2 & 1, 1, x1, 1, x2, y1 - 1);
        }
        if (dx % 2 == 1 && x1 > 1) {
          ans ^= query(0, y2 & 1, 1, y1, x1 - 1, y2) ^
                 query(1, y2 & 1, 1, y1, x1 - 1, y2);
        }
        ans += query(x2 & 1, y2 & 1, x1, y1, x2, y2);
        printf("%I64d\n", ans);
      }
    }
  }
}
