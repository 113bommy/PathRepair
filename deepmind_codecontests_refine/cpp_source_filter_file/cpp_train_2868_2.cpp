#include <bits/stdc++.h>
using namespace std;
struct my_time {
  int sec;
  int min;
  int hour;
  int wod;
  int day;
  int mon;
  int year;
};
bool isLeapYear(int x) {
  if (x % 4) return false;
  if (x % 100) return true;
  return !(x % 400);
}
int getDays(int y) { return y * 365 + y / 4 - y / 100 + y / 400; }
void getTime(my_time* cal, long long t) {
  cal->sec = t % 60;
  t /= 60;
  cal->min = t % 60;
  t /= 60;
  cal->hour = t % 24;
  t /= 24;
  cal->wod = (t + 3) % 7 + 1;
  int l = 1970, r = 31710;
  while (l <= r) {
    const int m = (l + r) / 2;
    const int w = getDays(m - 1) - getDays(1969);
    if (w > t) {
      r = m - 1;
    } else if (w < t) {
      cal->year = m;
      l = m + 1;
    } else {
      cal->year = m;
      break;
    }
  }
  t -= getDays(cal->year - 1) - getDays(1969);
  int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (isLeapYear(cal->year)) m[2] = 29;
  for (int i = 1; i <= 12; ++i) {
    if (t < m[i]) {
      cal->mon = i;
      cal->day = t + 1;
      return;
    }
    t -= m[i];
  }
}
int main() {
  my_time cron;
  cin >> cron.sec >> cron.min >> cron.hour >> cron.wod >> cron.day >> cron.mon;
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    long long t;
    cin >> t;
    t += 1;
    my_time cal;
    while (true) {
      getTime(&cal, t);
      if (cron.sec != -1 && cron.sec != cal.sec) {
        if (cron.sec > cal.sec)
          t += cron.sec - cal.sec;
        else
          t += 60 + cron.sec - cal.sec;
        continue;
      }
      if (cron.min != -1 && cron.min != cal.min) {
        if (cron.min > cal.min) {
          t += (cron.min - cal.min) * 60;
        } else {
          t += (60 + cron.min - cal.min) * 60;
        }
        t -= cal.sec;
        continue;
      }
      if (cron.hour != -1 && cron.hour != cal.hour) {
        if (cron.hour > cal.hour) {
          t += (cron.hour - cal.hour) * 3600;
        } else {
          t += (24 + cron.hour - cal.hour) * 3600;
        }
        t -= cal.sec + cal.min * 60;
        continue;
      }
      if (cron.mon != -1 && cron.mon != cal.mon) {
        t += 86400;
        t -= cal.sec + cal.min * 60 + cal.hour * 3600;
        continue;
      }
      if (cron.wod != -1 && cron.day != -1) {
        if (cron.wod != cal.wod && cron.day != cal.day) {
          t += 86400;
          t -= cal.sec + cal.min * 60 + cal.hour * 3600;
          continue;
        } else {
          break;
        }
      }
      if (cron.wod != -1) {
        if (cron.wod != cal.wod) {
          t += 86400;
          t -= cal.sec + cal.min * 60 + cal.hour * 3600;
          continue;
        } else {
          break;
        }
      } else if (cron.day != -1) {
        if (cron.day != cal.day) {
          t += 86400;
          t -= cal.sec + cal.min * 60 + cal.hour * 3600;
          continue;
        } else {
          break;
        }
      }
      break;
    }
    cout << t << endl;
  }
  return 0;
}
