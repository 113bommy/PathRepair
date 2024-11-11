#include <bits/stdc++.h>
using namespace std;
const int MAX_K = 502;
int n, m, k, min_x, min_y, a, b, s;
int x[MAX_K], y[MAX_K];
bool exist;
pair<int, int> _min;
bool check_line_x(int x_cord, int number_of_points, int time) {
  vector<pair<int, int> > intervals;
  for (int i = 0; i < number_of_points; i++) {
    if (x[i] - time <= x_cord && x[i] + time >= x_cord) {
      intervals.push_back(make_pair(max(1, y[i] - time), min(y[i] + time, m)));
    }
  }
  if (intervals.empty()) {
    return true;
  } else {
    sort(intervals.begin(), intervals.end());
    if (intervals.front().first != 1 || intervals.back().second != m) {
      return true;
    } else {
      for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].first > intervals[i - 1].second) {
          return true;
        }
      }
    }
    return false;
  }
}
bool check_line_y(int y_cord, int number_of_points, int time) {
  vector<pair<int, int> > intervals;
  for (int i = 0; i < number_of_points; i++) {
    if (y[i] - time <= y_cord && y[i] + time >= y_cord) {
      intervals.push_back(make_pair(max(1, x[i] - time), min(x[i] + time, n)));
    }
  }
  if (intervals.empty()) {
    return true;
  } else {
    sort(intervals.begin(), intervals.end());
    if (intervals.front().first != 1 || intervals.back().second != n) {
      return true;
    } else {
      for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].first > intervals[i - 1].second + 1) {
          return true;
        }
      }
    }
    return false;
  }
}
pair<int, int> minimums(int time, int number_of_points) {
  min_x = min_y = 1000010000;
  exist = false;
  if (check_line_x(1, number_of_points, time)) {
    min_x = 1;
    exist = true;
  } else {
    for (int i = 0; i < number_of_points; i++) {
      if (x[i] + time + 1 <= n) {
        if (check_line_x(x[i] + time + 1, number_of_points, time)) {
          min_x = min(min_x, x[i] + time + 1);
          exist = true;
        }
      }
    }
  }
  if (check_line_y(1, number_of_points, time)) {
    min_y = 1;
    exist = true;
  } else {
    for (int i = 0; i < number_of_points; i++) {
      if (y[i] + time + 1 <= m) {
        if (check_line_y(y[i] + time + 1, number_of_points, time)) {
          min_y = min(min_y, y[i] + time + 1);
          exist = true;
        }
      }
    }
  }
  return make_pair(min_x, min_y);
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }
  a = 1;
  b = max(n, m);
  while (a < b) {
    s = (a + b) / 2;
    _min = minimums(s, k);
    if (!exist) {
      b = s;
    } else {
      x[k] = min(n, _min.first + s);
      y[k] = min(m, _min.second + s);
      _min = minimums(s, k + 1);
      if (!exist) {
        b = s;
      } else {
        a = s + 1;
      }
    }
  }
  printf("%d", a);
}
