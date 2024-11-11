#include <bits/stdc++.h>
using namespace std;
int x1[110];
int botva[110];
int x2[110];
int y2[110];
int xc[110];
int yc[110];
long long m[110];
const long double eps = 1e-05;
bool inside(int x1, int botva, int x2, int y2, long long a, long long b,
            long long m) {
  if (a < x1 * m || a > x2 * m) return false;
  if (b < botva * m || b > y2 * m) return false;
  return true;
}
bool check(int k) {
  long long x = 0, y = 0;
  long long m = 0;
  for (int i = k; i >= 0; i--) {
    x = x + xc[i] * ::m[i];
    y = y + yc[i] * ::m[i];
    m += ::m[i];
    if (i == 0) {
      if (!inside(x1[i], botva[i], x2[i], y2[i], x, y, m)) return false;
    } else {
      if (!inside(max(x1[i], x1[i - 1]), max(botva[i], botva[i - 1]),
                  min(x2[i], x2[i - 1]), min(y2[i], y2[i - 1]), x, y, m))
        return false;
    }
  }
  return true;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d %d", &x1[i], &botva[i], &x2[i], &y2[i]);
    int a = x2[i] - x1[i];
    m[i] = a * a * a;
    x1[i] *= 2;
    botva[i] *= 2;
    x2[i] *= 2;
    y2[i] *= 2;
    xc[i] = (x1[i] + x2[i]) / 2;
    yc[i] = (botva[i] + y2[i]) / 2;
    if (x1[i] > x2[i]) swap(x1[i], x2[i]);
    if (botva[i] > y2[i]) swap(botva[i], y2[i]);
    if (!check(i)) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("%d\n", n);
  return 0;
}
