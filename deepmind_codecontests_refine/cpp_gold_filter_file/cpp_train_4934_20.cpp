#include <bits/stdc++.h>
using namespace std;
int day(int d, int m, int y) {
  if (d > 31 || m > 13 || (m == 2 && d > 28 && y % 4 != 0)) return 1e8;
  m = (m + 9) % 12;
  y = y - m / 10;
  return 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (d - 1);
}
void res() {
  string s1, s2;
  cin >> s1 >> s2;
  int d1, m1, y1, d2, m2, y2;
  d1 = s1[0] - 48;
  d1 = d1 * 10 + (s1[1] - 48);
  m1 = s1[3] - 48;
  m1 = m1 * 10 + (s1[4] - 48);
  y1 = s1[6] - 48;
  y1 = y1 * 10 + (s1[7] - 48);
  d2 = s2[0] - 48;
  d2 = d2 * 10 + (s2[1] - 48);
  m2 = s2[3] - 48;
  m2 = m2 * 10 + (s2[4] - 48);
  y2 = s2[6] - 48;
  y2 = y2 * 10 + (s2[7] - 48);
  int day1 = day(d1, m1, y1);
  int day2 = day(y2, d2, m2);
  int day3 = day(d2, m2, y2);
  int day4 = day(d2, y2, m2);
  int day5 = day(m2, d2, y2);
  int day6 = day(m2, y2, d2);
  int day7 = day(y2, m2, d2);
  int d = 18 * (365) + 4;
  if ((day1 - day2 > d) || (day1 - day7 > d) || (day1 - day3 > d) ||
      (day1 - day4 > d) || (day1 - day5 > d) || (day1 - day6 > d))
    cout << "YES";
  else
    cout << "NO";
}
int main() { res(); }
