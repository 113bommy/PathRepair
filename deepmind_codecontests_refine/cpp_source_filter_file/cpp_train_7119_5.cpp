#include <bits/stdc++.h>
int month1[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month2[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leap(int y) {
  if (y % 400 == 0)
    return 1;
  else if (y % 4 == 0 && y % 100 != 0)
    return 1;
  else
    return 0;
}
int main() {
  int i, y1, y2, m1, m2, d1, d2, len, days, t1, t2, t3;
  char date1[11], date2[11];
  scanf("%s %s", &date1, &date2);
  len = 10;
  i = 0;
  y1 = y2 = 0;
  while (date1[i] != ':') {
    y1 = y1 * 10 + date1[i] - '0';
    y2 = y2 * 10 + date2[i] - '0';
    i++;
  }
  i++;
  m1 = m2 = 0;
  while (date1[i] != ':') {
    m1 = m1 * 10 + date1[i] - '0';
    m2 = m2 * 10 + date2[i] - '0';
    i++;
  }
  i++;
  d1 = d2 = 0;
  while (date1[i] != '\0') {
    d1 = d1 * 10 + date1[i] - '0';
    d2 = d2 * 10 + date2[i] - '0';
    i++;
  }
  days = 0;
  if (y1 == y2 && m1 == m2) {
    days = abs(d1 - d2);
  } else if (y1 == y2 && d1 == d2) {
    if (leap(y1)) {
      if (m1 >= m2) {
        for (i = m2 - 1; i < m1 - 1; i++) days += month2[i];
      } else {
        for (i = m1 - 1; i < m2 - 1; i++) days += month2[i];
      }
    } else {
      if (m1 >= m2) {
        for (i = m2 - 1; i < m1 - 1; i++) days += month1[i];
      } else {
        for (i = m1 - 1; i < m2 - 1; i++) days += month1[i];
      }
    }
  } else if (y1 == y2 && m1 > m2) {
    t1 = y1;
    t2 = m1;
    t3 = d1;
    y1 = y2;
    m1 = m2;
    d1 = d2;
    y2 = t1;
    m2 = t2;
    d2 = t3;
    if (leap(y1)) {
      days = month2[m1 - 1] - d1;
      for (i = m1; i < m2 - 1; i++) days += month2[i];
      days += d2;
    } else {
      days = month1[m1 - 1] - d1;
      for (i = m1; i < m2; i++) days += month1[i];
      days += d2;
    }
  } else if (y1 > y2) {
    t1 = y1;
    t2 = m1;
    t3 = d1;
    y1 = y2;
    m1 = m2;
    d1 = d2;
    y2 = t1;
    m2 = t2;
    d2 = t3;
    if (leap(y1)) {
      days = month2[m1 - 1] - d1;
      for (i = m1; i < 12; i++) days += month2[i];
    } else {
      days = month1[m1 - 1] - d1;
      for (i = m1; i < 12; i++) days += month1[i];
    }
    i = y1 + 1;
    while (i < y2) {
      if (leap(i)) {
        days += 366;
      } else {
        days += 365;
      }
      i++;
    }
    if (leap(y2)) {
      for (i = 0; i < m2 - 1; i++) days += month2[i];
      days += d2;
    } else {
      for (i = 0; i < m2 - 1; i++) days += month1[i];
      days += d2;
    }
  } else {
    if (leap(y1)) {
      days = month2[m1 - 1] - d1;
      for (i = m1; i < 12; i++) days += month2[i];
    } else {
      days = month1[m1 - 1] - d1;
      for (i = m1; i < 12; i++) days += month1[i];
    }
    i = y1 + 1;
    while (i < y2) {
      if (leap(i)) {
        days += 366;
      } else {
        days += 365;
      }
      i++;
    }
    if (leap(y2)) {
      for (i = 0; i < m2 - 1; i++) days += month2[i];
      days += d2;
    } else {
      for (i = 0; i < m2 - 1; i++) days += month1[i];
      days += d2;
    }
  }
  printf("%d\n", days);
  return 0;
}
