#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000")
using namespace std;
const bool db = false;
double L[3010][3010];
int n, x[3010], y[3010];
pair<int, int> p[3010];
unsigned bit[3010][3010 / 32], cur[3010 / 32];
clock_t start;
int it;
bool EXIT;
int bits[1 << 16];
inline int intr(int i, int j, double r) { return L[i][j] < 2 * r; }
inline int cnt(unsigned r) { return bits[r >> 16] + bits[r & 65535]; }
inline int Get(int id, int to) { return ((bit[id][to >> 5]) >> (to & 31)) & 1; }
inline void Set(int id, int to, int val) {
  if (val == 1) {
    bit[id][to >> 5] |= (1U << (to & 31));
  } else if (Get(id, to)) {
    bit[id][to >> 5] ^= 1U << (to & 31);
  }
}
bool check(double rad) {
  for (int x = 1; x <= n; ++x) {
    for (int i = 1; i <= n; ++i) {
      Set(x, i, !intr(x, i, rad));
    }
    for (int y = max(y - 500, 1); y < x; ++y) {
      if (Get(x, y)) {
        Set(x, y, 0);
        Set(y, x, 0);
        for (int i = 0; 32 * i <= n; ++i) {
          cur[i] = bit[x][i] & bit[y][i];
          if (cnt(cur[i]) > 0) return true;
        }
        Set(x, y, 1);
        Set(y, x, 1);
      }
    }
  }
  return false;
}
int main() {
  scanf("%d", &n);
  start = clock();
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    p[i] = make_pair(x[i], y[i]);
  }
  sort(p + 1, p + 1 + n);
  for (int i = 1; i <= n; ++i) {
    x[i] = p[i].first;
    y[i] = p[i].second;
  }
  reverse(p + 1, p + 1 + n);
  for (int i = 1; i < 1 << 16; ++i) {
    bits[i] = bits[i >> 1] + (i & 1);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      L[j][i] = L[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + .0 +
                               (y[i] - y[j]) * (y[i] - y[j]));
    }
  }
  double l = 1e-5, r = 18e3;
  while (l < r - 1e-6 && !EXIT) {
    if (abs(l - r) / r < 1e-6) {
      break;
    }
    double m = (l + r) / 2.0;
    if (check(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  printf("%.6lf\n", (l + r) / 2.0);
  getchar();
  getchar();
  return 0;
}
