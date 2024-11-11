#include <bits/stdc++.h>
using namespace std;
int month_day[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                       {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
vector<long long> ok1, ok2;
int main() {
  int s, m, h, day, date, month;
  scanf("%d%d%d%d%d%d", &s, &m, &h, &day, &date, &month);
  if (day != -1) day--;
  if (date != -1) date--;
  if (month != -1) month--;
  long long x1 = 0;
  for (int h2 = 0; h2 < 24; h2++) {
    for (int m2 = 0; m2 < 60; m2++) {
      for (int s2 = 0; s2 < 60; s2++, x1++) {
        if ((s == -1 || s == s2) && (m == -1 || m == m2) &&
            (h == -1 || h == h2))
          ok1.push_back(x1);
      }
    }
  }
  int day2 = 3;
  long long x2 = 0;
  for (int year = 1970; year < 2370; year++) {
    bool leap = !(year % 400) || ((year % 100) && !(year % 4));
    for (int month2 = 0; month2 < 12; month2++) {
      for (int date2 = 0; date2 < month_day[leap][month2]; date2++, x2++) {
        if (-1 == month || month == month2) {
          if ((date != -1 && date == date2) || (day != -1 && day == day2) ||
              (date == -1 && day == -1))
            ok2.push_back(x2);
        }
        day2 = (day2 + 1) % 7;
      }
    }
  }
  int n;
  scanf("%d", &n);
  while (n--) {
    long long x;
    do {
      scanf("%I64d", &x);
    } while (false);
    long long whole_year = x / x1 / x2;
    long long remain_time = x % (x1 * x2);
    long long whole_day = remain_time / x1;
    remain_time %= x1;
    if (whole_day > ok2.back() ||
        (whole_day == ok2.back() && remain_time >= ok1.back())) {
      do {
        printf("%I64d\n", (whole_year + 1) * x1 * x2 + ok2[0] * x1 + ok1[0]);
      } while (false);
    } else if (remain_time >= ok1.back() ||
               !binary_search(ok2.begin(), ok2.end(), whole_day)) {
      do {
        printf("%I64d\n",
               whole_year * x1 * x2 +
                   *upper_bound(ok2.begin(), ok2.end(), whole_day) * x1 +
                   ok1[0]);
      } while (false);
    } else {
      do {
        printf("%I64d\n",
               whole_year * x1 * x2 + whole_day * x1 +
                   *upper_bound(ok1.begin(), ok1.end(), remain_time));
      } while (false);
    }
  }
  return 0;
}
