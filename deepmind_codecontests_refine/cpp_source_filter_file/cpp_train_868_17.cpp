#include <bits/stdc++.h>
using namespace std;
int read() {
  int x;
  scanf("%d", &x);
  return x;
}
int read(int &x) {
  scanf("%d", &x);
  return x;
}
const int MAX_N = 5 * int(1e6) + 6;
const int nDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char s[MAX_N];
deque<int> q;
int parseInt(int &p) {
  int ans = 0;
  for (; p < MAX_N && isdigit(s[p]); ++p) ans = ans * 10 + (s[p] - '0');
  ++p;
  return ans;
}
int calTime(int month, int day, int hour, int minute, int second) {
  int ans = 0;
  for (int i = 0; i < month - 1; ++i) ans += nDays[i] * 86400;
  ans += (day - 1) * 86400;
  ans += 3600 * hour;
  ans += 60 * minute;
  ans += second;
  return ans;
}
string fs(int x) {
  string s = "";
  while (x % 10 > 0) {
    s = char(x % 10 + '0') + s;
    x /= 10;
  }
  if (s.length() < 2) s = "0" + s;
  return s;
}
int main() {
  int n, m, c = 0;
  scanf("%d%d\n", &n, &m);
  while (scanf("%[0-9A-Za-z!.,?:- ]\n", s) != EOF) {
    int p = 0;
    int year = parseInt(p);
    int month = parseInt(p);
    int day = parseInt(p);
    int hour = parseInt(p);
    int minute = parseInt(p);
    int second = parseInt(p);
    int value = calTime(month, day, hour, minute, second);
    while (!q.empty() && q.front() + n <= value) {
      q.pop_front();
      --c;
    }
    q.push_back(value);
    ++c;
    if (c >= m) {
      cout << "2012-" << fs(month) << "-" << fs(day) << " " << fs(hour) << ":"
           << fs(minute) << ":" << fs(second) << endl;
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
