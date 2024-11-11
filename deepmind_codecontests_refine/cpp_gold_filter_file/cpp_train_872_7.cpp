#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int get(int x, int y) { return (x % 2) * 2 + (y % 2); }
int f[4][maxn][maxn];
void update_Fen(int k, int x, int y, int val) {
  x++;
  y++;
  if (x <= 0 || y <= 0) return;
  while (x < maxn) {
    int y1 = y;
    while (y1 < maxn) {
      f[k][x][y1] ^= val;
      y1 += y1 & -y1;
    }
    x += x & -x;
  }
}
int get_Fen(int k, int x, int y) {
  x++;
  y++;
  if (x <= 0 || y <= 0) return 0;
  int ans = 0;
  while (x) {
    int y1 = y;
    while (y1) {
      ans ^= f[k][x][y1];
      y1 -= y1 & -y1;
    }
    x -= x & -x;
  }
  return ans;
}
void update(int x, int l, int r, int val) {
  int k = get(x, l);
  int k1 = k ^ 1;
  update_Fen(k, x, l, val);
  r++;
  if (get(x, r) == k) {
    update_Fen(k, x, r, val);
  } else {
    update_Fen(k1, x, r, val);
  }
}
void updateBoard(int x0, int y0, int x1, int y1, int val) {
  update(x0, y0, y1, val);
  int k = get(x0, y0);
  int k1 = k ^ 2;
  x1++;
  int k2 = get(x1, y0);
  update(x1, y0, y1, val);
}
int Get(int x0, int y0, int x1, int y1) {
  return get_Fen(get(x1, y1), x1, y1) ^ get_Fen(get(x0 - 1, y1), x0 - 1, y1) ^
         get_Fen(get(x1, y0 - 1), x1, y0 - 1) ^
         get_Fen(get(x0 - 1, y0 - 1), x0 - 1, y0 - 1);
}
int n, m;
int main() {
  int q;
  scanf("%d %d", &n, &q);
  int x;
  int k, u, v, x0, y0, x1, y1;
  while (q--) {
    scanf("%d %d %d %d %d", &k, &x0, &y0, &x1, &y1);
    x0--;
    y0--;
    x1--;
    y1--;
    if (k == 2) {
      scanf("%d", &x);
      updateBoard(x0, y0, x1, y1, x);
    } else {
      printf("%d\n", Get(x0, y0, x1, y1));
    }
  }
  return 0;
}
