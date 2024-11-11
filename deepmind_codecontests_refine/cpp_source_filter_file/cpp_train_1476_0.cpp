#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int i = 0, n, min_x = INT_MAX, max_x = INT_MIN, min_y = INT_MAX,
      max_y = INT_MIN, x, y;
  cin >> n;
  int aa = n;
  n = 4 * n + 1;
  int temp = n;
  int xx[51] = {0}, yy[51] = {0};
  vector<pair<int, int>> p(4 * n + 100);
  while (n--) {
    cin >> x >> y;
    p[i].first = x;
    p[i].second = y;
    xx[x]++;
    yy[y]++;
    i++;
  }
  for (int i = 0; i <= 50; i++) {
    if (xx[i] >= aa + 1) {
      if (i > max_x) max_x = i;
      if (i < min_x) min_x = i;
    }
    if (yy[i] >= aa + 1) {
      if (i > max_y) max_y = i;
      if (i < min_y) min_y = i;
    }
  }
  for (i = 0; i < temp; i++) {
    if ((p[i].first == min_x && p[i].second >= min_y && p[i].second <= max_y) ||
        (p[i].first == max_x && p[i].second >= min_y && p[i].second <= max_y) ||
        (p[i].second == min_y && p[i].first >= min_x && p[i].first <= max_x) ||
        (p[i].second == max_y && p[i].first >= min_x && p[i].first <= max_x)) {
    } else {
      cout << p[i].first << " " << p[i].second;
      break;
    }
  }
  return 0;
}
