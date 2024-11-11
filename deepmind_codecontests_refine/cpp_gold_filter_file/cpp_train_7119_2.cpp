#include <bits/stdc++.h>
int z[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isLeap(int y) {
  if (y % 400 == 0)
    return 1;
  else if (y % 100 == 0)
    return 0;
  return y % 4 == 0;
}
int getDayOfMonth(int year, int month) {
  if (isLeap(year) && month == 2) {
    return 29;
  } else
    return z[month];
}
bool cmpDate(int y1, int m1, int d1, int y2, int m2, int d2) {
  if (y1 != y2) return y1 < y2;
  if (m1 != m2) return m1 < m2;
  return d1 < d2;
}
int getDayOfYear(int y, int m, int d) {
  int cnt = 0;
  for (int i = 1; i < m; ++i) {
    cnt += getDayOfMonth(y, i);
  }
  return cnt + d;
}
int getYear(int y) {
  if (isLeap(y)) return 366;
  return 365;
}
int diffDate(int y1, int m1, int d1, int y2, int m2, int d2) {
  int cnt = 0;
  for (int i = y1 + 1; i <= y2 - 1; ++i) {
    cnt += getYear(i);
  }
  cnt += getYear(y1) - getDayOfYear(y1, m1, d1);
  cnt += getDayOfYear(y2, m2, d2);
  return cnt;
}
int abs(int x) { return x < 0 ? -x : x; }
int main(void) {
  int y1, m1, d1, y2, m2, d2;
  scanf("%d:%d:%d", &y1, &m1, &d1);
  scanf("%d:%d:%d", &y2, &m2, &d2);
  printf("%d\n", abs(diffDate(1890, 1, 1, y1, m1, d1) -
                     diffDate(1890, 1, 1, y2, m2, d2)));
}
