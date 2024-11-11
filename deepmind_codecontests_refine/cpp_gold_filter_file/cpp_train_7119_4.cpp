#include <bits/stdc++.h>
using namespace std;
int dd1[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dd2[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
  int y1, m1, d1;
  int y2, m2, d2;
  scanf("%d:%d:%d\n%d:%d:%d", &y1, &m1, &d1, &y2, &m2, &d2);
  if (y1 > y2) {
    swap(y1, y2);
    swap(m1, m2);
    swap(d1, d2);
  } else if (y1 == y2) {
    if (m1 > m2) {
      swap(y1, y2);
      swap(m1, m2);
      swap(d1, d2);
    } else if (m1 == m2) {
      if (d1 > d2) {
        swap(y1, y2);
        swap(m1, m2);
        swap(d1, d2);
      }
    }
  }
  int ans = 0, i;
  int *d;
  if (y1 == y2) {
    i = y1;
    if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
      d = dd2;
    else
      d = dd1;
    if (m1 == m2)
      for (int i = d1; i < d2; i++) ans++;
    else {
      for (int i = d1; i <= d[m1 - 1]; i++) ans++;
      for (int i = m1 + 1; i < m2; i++) ans += d[i - 1];
      for (int i = 1; i < d2; i++) ans++;
    }
    printf("%d\n", ans);
    return 0;
  }
  for (i = y1 + 1; i < y2; i++) {
    if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
      ans += 366;
    } else {
      ans += 365;
    }
  }
  i = y1;
  if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
    d = dd2;
  else
    d = dd1;
  for (int i = d1; i <= d[m1 - 1]; i++) {
    ans++;
  }
  for (int i = m1 + 1; i <= 12; i++) ans += d[i - 1];
  i = y2;
  if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
    d = dd2;
  else
    d = dd1;
  for (i = 1; i <= m2 - 1; i++) {
    for (int j = 1; j <= d[i - 1]; j++) ans++;
  }
  for (i = 1; i <= d2; i++) ans++;
  printf("%d\n", ans - 1);
  return 0;
}
