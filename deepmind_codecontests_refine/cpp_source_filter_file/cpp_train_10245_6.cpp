#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b;
  scanf("%lld%lld", &a, &b);
  string s;
  cin >> s;
  long long int i, l = s.length();
  s = s + s;
  pair<long long int, long long int> p[2 * l];
  long long int k, x, y, dx, dy;
  x = 0;
  y = 0;
  for (i = 0; i < (2 * l); i++) {
    if (s.at(i) == 'U') {
      p[i].first = x;
      p[i].second = y + 1;
    } else if (s.at(i) == 'D') {
      p[i].first = x;
      p[i].second = y - 1;
    } else if (s.at(i) == 'L') {
      p[i].first = x - 1;
      p[i].second = y;
    } else {
      p[i].first = x + 1;
      p[i].second = y;
    }
    x = p[i].first;
    y = p[i].second;
  }
  int flag = 0;
  if (a == 0 && b == 0) {
    flag = 1;
  } else {
    for (i = 0; i < l; i++) {
      if (p[i].first == a && p[i].second == b) {
        flag = 1;
        break;
      }
      dx = p[i + l].first - p[i].first;
      dy = p[i + l].second - p[i].second;
      if ((a - p[i].first) * dy == (b - p[i].second) * dx) {
        if (dx != 0) {
          k = (a - p[i].first) / dx;
        } else if (dy != 0) {
          k = (b - p[i].second) / dy;
        } else
          continue;
        if (k >= 0) {
          flag = 1;
          break;
        }
      }
    }
  }
  if (flag) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}
