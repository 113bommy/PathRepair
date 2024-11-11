#include <bits/stdc++.h>
using namespace std;
int md[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int second, minute, hour, day, date, month;
int n;
long long x, tmp1 = 0, tmp2 = 0, today = 3;
vector<long long> a, b;
int match(int h, int m, int s) {
  if ((second != -1) && (second != s)) return 0;
  if ((minute != -1) && (minute != m)) return 0;
  if ((hour != -1) && (hour != h)) return 0;
  return 1;
}
int lp(int x) { return ((x % 400 == 0) || (x % 100 != 0)) && (x % 4 == 0); }
void prepare() {
  for (int h = 0; h < 24; h++)
    for (int m = 0; m < 60; m++)
      for (int s = 0; s < 60; s++, tmp1++)
        if (match(h, m, s)) a.push_back(tmp1);
  for (int y = 1970; y < 1970 + 400; y++)
    for (int m = 0; m < 12; m++)
      for (int d = 0; d < md[lp(y)][m]; d++, tmp2++) {
        if ((month == -1) || (month == m))
          if (((date != -1) && (date == d)) ||
              ((day != -1) && (day == today)) || ((date == -1) && (day == -1)))
            b.push_back(tmp2);
        today = (today + 1) % 7;
      }
}
int main() {
  cin >> second >> minute >> hour >> day >> date >> month;
  day -= (day != -1), date -= (date != -1), month -= (month != -1);
  prepare();
  cin >> n;
  while (n--) {
    cin >> x;
    long long y = x / tmp1 / tmp2, r = x % (tmp1 * tmp2), d = r / tmp1, ans;
    r %= tmp1;
    if ((d > b.back()) || ((d == b.back()) && (r > a.back())))
      ans = (y + 1) * tmp1 * tmp2 + b[0] * tmp1 + a[0];
    else if ((r >= a.back()) || (!binary_search(b.begin(), b.end(), d)))
      ans = y * tmp1 * tmp2 + *upper_bound(b.begin(), b.end(), d) * tmp1 + a[0];
    else
      ans = y * tmp1 * tmp2 + d * tmp1 + *upper_bound(a.begin(), a.end(), r);
    cout << ans << endl;
  }
}
