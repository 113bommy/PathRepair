#include <bits/stdc++.h>
using namespace std;
int M[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
  int y1, y2, m1, m2, d1, d2, i, yt, mt, dt;
  long f1, f2;
  scanf("%d:%d:%d", &y1, &m1, &d1);
  scanf("%d:%d:%d", &y2, &m2, &d2);
  if (y2 < y1 || (y2 == y1 && m2 < y1) || (y2 == y1 && m2 == m1 && d2 < d1)) {
    yt = y1;
    y1 = y2;
    y2 = yt;
    mt = m1;
    m1 = m2;
    m2 = mt;
    dt = d1;
    d1 = d2;
    d2 = dt;
  }
  f1 = 0;
  for (int i = 1; i < m1; i++) {
    if (i == 2 && y1 % 4 == 0 && y1 != 1900)
      f1 += 29;
    else
      f1 += M[i];
  }
  f1 += d1;
  f2 = 0;
  for (int i = y1; i < y2; i++) {
    if (i % 4 == 0 && i != 1900)
      f2 += 366;
    else
      f2 += 365;
  }
  for (int i = 1; i < m2; i++) {
    if (i == 2 && y2 % 4 == 0 && y2 != 1900)
      f2 += 29;
    else
      f2 += M[i];
  }
  f2 += d2;
  printf("%ld", f2 - f1);
  return 0;
}
