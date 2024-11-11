#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long double PI = acos((long double)-1);
string str;
long long n;
long long deltaX, deltaY;
long long reqX, reqY;
bool check(long long days) {
  long long times = days / n;
  long long availX = deltaX * times;
  long long availY = deltaY * times;
  long long y = days;
  y -= times * n;
  for (int i = 0; i < y; ++i) {
    if (str[i] == 'L')
      --availX;
    else if (str[i] == 'R')
      ++availX;
    else if (str[i] == 'U')
      ++availY;
    else
      --availY;
  }
  long long needX = reqX - availX;
  long long needY = reqY - availY;
  return (abs(needX) + abs(needY) <= days);
}
void solve() {
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> n;
  cin >> str;
  deltaX = deltaY = 0;
  for (int i = 0; i < n; ++i) {
    if (str[i] == 'L')
      --deltaX;
    else if (str[i] == 'R')
      ++deltaX;
    else if (str[i] == 'U')
      ++deltaY;
    else
      --deltaY;
  }
  reqX = x2 - x1;
  reqY = y2 - y1;
  long long s = -1, e = 1e16;
  while (s + 1 < e) {
    long long m = (s + e) / 2;
    if (check(m)) {
      e = m;
    } else {
      s = m;
    }
  }
  if (e == 1e16) {
    cout << -1 << '\n';
  } else {
    cout << e << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
