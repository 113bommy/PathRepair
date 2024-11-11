#include <bits/stdc++.h>
using namespace std;
long long min(long long x, long long y) {
  if (x > y) return y;
  return x;
}
long long max(long long x, long long y) {
  if (x > y) return x;
  return y;
}
long long js(long long x1, long long y1, long long x2, long long y2, int k) {
  long long cnt = 0;
  if (x2 < x1 || y2 < y1) return 0;
  if (k == 0) {
    if ((x1 + y1) % 2 == 0) {
      cnt = (x2 - x1 + 1) * (y2 - y1 + 1) / 2;
      if ((x2 - x1 + 1) * (y2 - y1 + 1) % 2 != 0) ++cnt;
      return cnt;
    } else
      return (x2 - x1 + 1) * (y2 - y1 + 1) / 2;
  } else {
    if ((x1 + y1) % 2 == 0) {
      return (x2 - x1 + 1) * (y2 - y1 + 1) / 2;
    } else {
      cnt = (x2 - x1 + 1) * (y2 - y1 + 1) / 2;
      if ((x2 - x1 + 1) * (y2 - y1 + 1) % 2 != 0) ++cnt;
      return cnt;
    }
  }
}
int main() {
  int i, j, T;
  long long x1, x2, y1, y2, x3, y3, x4, y4, ansb, n, m, ansh, x5, y5, x6, y6;
  scanf("%d", &T);
  while (T--) {
    scanf("%I64d%I64d", &n, &m);
    scanf("%I64d%I64d%I64d%I64d", &x1, &y1, &x2, &y2);
    scanf("%I64d%I64d%I64d%I64d", &x3, &y3, &x4, &y4);
    if (x3 >= x1 && y3 >= y1) {
      x5 = x3;
      y5 = y3;
      if (x2 <= x4 && y2 <= y4) {
        x6 = x2;
        y6 = y2;
      } else if (x2 >= x4 && y2 >= y4) {
        x6 = x4;
        y6 = y4;
      } else {
        x6 = min(x4, x2);
        y6 = min(y4, y2);
      }
    } else if (x3 <= x1 && y3 <= y1) {
      x5 = x1;
      y5 = y1;
      if (x2 <= x4 && y2 <= y4) {
        x6 = x2;
        y6 = y2;
      } else if (x2 >= x4 && y2 >= y4) {
        x6 = x4;
        y6 = y4;
      } else {
        x6 = min(x4, x2);
        y6 = min(y4, y2);
      }
    } else {
      x5 = max(x1, x3);
      y5 = max(y1, y3);
      if (x2 <= x4 && y2 <= y4) {
        x6 = x2;
        y6 = y2;
      } else if (x2 >= x4 && y2 >= y4) {
        x6 = x4;
        y6 = y4;
      } else {
        x6 = min(x4, x2);
        y6 = min(y4, y2);
      }
    }
    ansb = n * m / 2;
    ansh = n * m / 2;
    if (n * m % 2 != 0) ansb++;
    ansb += js(x1, y1, x2, y2, 1);
    ansh -= js(x1, y1, x2, y2, 1);
    ansb -= js(x3, y3, x4, y4, 0);
    ansh += js(x3, y3, x4, y4, 0);
    ansh += js(x5, y5, x6, y6, 1);
    ansb -= js(x5, y5, x6, y6, 1);
    printf("%I64d %I64d\n", ansb, ansh);
  }
  return 0;
}
