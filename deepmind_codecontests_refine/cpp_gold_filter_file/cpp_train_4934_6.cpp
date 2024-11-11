#include <bits/stdc++.h>
int check_year_age(int y1, int y2) {
  if (y1 - y2 > 18) return 2;
  if (y1 - y2 == 18) return 1;
  return 0;
}
bool check_month_day_age(int d1, int d2, int m1, int m2, int y1, int y2) {
  if (check_year_age(y1, y2) == 1) {
    if (m1 == m2) {
      if (d1 >= d2) return 1;
      return 0;
    }
    if (m1 > m2) return 1;
    return 0;
  }
  if (check_year_age(y1, y2) == 2) return 1;
  return 0;
}
bool check_day_month_year_valid(int d2, int m2, int y2) {
  if (m2 > 12) return 0;
  if (y2 % 4 != 0 || m2 != 2) {
    if (m2 == 2) {
      if (d2 > 28) return 0;
    } else {
      if (m2 == 1 || m2 == 3 || m2 == 5 || m2 == 7 || m2 == 8 || m2 == 10 ||
          m2 == 12) {
        if (d2 > 31) return 0;
      } else if (d2 > 30)
        return 0;
    }
  } else if (d2 > 29)
    return 0;
  return 1;
}
int chartoint(char x1, char x2) { return (x1 - '0') * 10 + (x2 - '0'); }
char s[8];
int main() {
  int d1, m1, y1, d2, m2, y2;
  bool OK = 0;
  scanf("%s", s);
  d1 = chartoint(s[0], s[1]);
  m1 = chartoint(s[3], s[4]);
  y1 = chartoint(s[6], s[7]);
  scanf("%s", s);
  d2 = chartoint(s[0], s[1]);
  m2 = chartoint(s[3], s[4]);
  y2 = chartoint(s[6], s[7]);
  if (check_month_day_age(d1, d2, m1, m2, y1, y2) &&
      check_day_month_year_valid(d2, m2, y2)) {
    OK = 1;
  }
  if (check_month_day_age(d1, m2, m1, d2, y1, y2) &&
      check_day_month_year_valid(m2, d2, y2)) {
    OK = 1;
  }
  if (check_month_day_age(d1, y2, m1, m2, y1, d2) &&
      check_day_month_year_valid(y2, m2, d2)) {
    OK = 1;
  }
  if (check_month_day_age(d1, y2, m1, d2, y1, m2) &&
      check_day_month_year_valid(y2, d2, m2)) {
    OK = 1;
  }
  if (check_month_day_age(d1, d2, m1, y2, y1, m2) &&
      check_day_month_year_valid(d2, y2, m2)) {
    OK = 1;
  }
  if (check_month_day_age(d1, m2, m1, y2, y1, d2) &&
      check_day_month_year_valid(m2, y2, d2)) {
    OK = 1;
  }
  if (OK)
    printf("YES\n");
  else
    printf("NO\n");
}
