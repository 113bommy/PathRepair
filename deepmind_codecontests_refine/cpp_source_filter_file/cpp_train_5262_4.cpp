#include <bits/stdc++.h>
using namespace std;
bool isLeapYear(int year) {
  if (year % 400 == 0)
    return true;
  else if (year % 100 == 0)
    return false;
  else if (year % 4 == 0)
    return true;
  else
    return false;
}
int main() {
  int n, days = 1, ourYearDay = 0, max = 100000;
  cin >> n;
  bool isLeap = isLeapYear(n), ready = false;
  for (int year = 0; year <= max; year++) {
    if (year == n) {
      ourYearDay = days;
      ready = true;
    } else {
      if (ready && (ourYearDay == days) && (isLeapYear(year) == isLeap)) {
        cout << year << endl;
        return 0;
      }
    }
    if (isLeapYear(year)) {
      days += 2;
    } else {
      days++;
    }
    days %= 7;
  }
}
