#include <bits/stdc++.h>
using namespace std;
struct Point {
  long long x, y;
  Point(long long x, long long y) : x(x), y(y) {}
};
bool cmpX(const Point &P1, const Point &P2) { return P1.x < P2.x; }
bool cmpY(const Point &P1, const Point &P2) { return P1.y < P2.y; }
vector<Point> points;
long long n, m, k;
const long long INF = 1e18;
long long leftMost(long long t) {
  long long col = 1;
  while (col <= m) {
    vector<Point> curPoints;
    long long minY = INF;
    for (int i = 0; i < points.size(); i++) {
      if (abs(points[i].y - col) <= t) {
        curPoints.push_back(points[i]);
        minY = min(minY, points[i].y);
      }
    }
    sort(curPoints.begin(), curPoints.end(), cmpX);
    long long row = 1;
    for (int i = 0; i < curPoints.size(); i++) {
      if (curPoints[i].x - t > row) {
        return col;
      } else {
        row = curPoints[i].x + t + 1;
      }
    }
    if (row < n) {
      return col;
    }
    col = minY + t + 1;
  }
  return m + 1;
}
long long rightMost(long long t) {
  long long col = m;
  while (col >= 1) {
    vector<Point> curPoints;
    long long maxY = 0;
    for (int i = 0; i < points.size(); i++) {
      if (abs(points[i].y - col) <= t) {
        curPoints.push_back(points[i]);
        maxY = max(maxY, points[i].y);
      }
    }
    sort(curPoints.begin(), curPoints.end(), cmpX);
    long long row = 1;
    for (int i = 0; i < curPoints.size(); i++) {
      if (curPoints[i].x - t > row) {
        return col;
      } else {
        row = curPoints[i].x + t + 1;
      }
    }
    if (row < n) {
      return col;
    }
    col = maxY - t - 1;
  }
  return 0;
}
long long upMost(long long t) {
  long long row = 1;
  while (row <= n) {
    vector<Point> curPoints;
    long long minX = INF;
    for (int i = 0; i < points.size(); i++) {
      if (abs(points[i].x - row) <= t) {
        curPoints.push_back(points[i]);
        minX = min(minX, points[i].x);
      }
    }
    sort(curPoints.begin(), curPoints.end(), cmpY);
    long long col = 1;
    for (int i = 0; i < curPoints.size(); i++) {
      if (curPoints[i].y - t > col) {
        return row;
      } else {
        col = curPoints[i].y + t + 1;
      }
    }
    if (col < m) {
      return row;
    }
    row = minX + t + 1;
  }
  return n + 1;
}
long long downMost(long long t) {
  long long row = n;
  while (row >= 1) {
    vector<Point> curPoints;
    long long maxX = 0;
    for (int i = 0; i < points.size(); i++) {
      if (abs(points[i].x - row) <= t) {
        curPoints.push_back(points[i]);
        maxX = max(maxX, points[i].x);
      }
    }
    sort(curPoints.begin(), curPoints.end(), cmpY);
    long long col = 1;
    for (int i = 0; i < curPoints.size(); i++) {
      if (curPoints[i].y - t > col) {
        return row;
      } else {
        col = curPoints[i].y + t + 1;
      }
    }
    if (col < m) {
      return row;
    }
    row = maxX - t - 1;
  }
  return 0;
}
bool checkTime(long long t) {
  long long dx = rightMost(t) - leftMost(t);
  long long dy = downMost(t) - upMost(t);
  return dx <= 2 * t && dy <= 2 * t;
}
long long minTime() {
  long long low = 0;
  long long high = 1e9;
  if (checkTime(low)) return low;
  assert(checkTime(high));
  while (high - low > 1) {
    long long mid = (low + high) / 2;
    if (checkTime(mid))
      high = mid;
    else
      low = mid;
  }
  return high;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  for (long long i = 0; i < (long long)k; i++) {
    long long x, y;
    cin >> x >> y;
    points.push_back(Point(x, y));
  }
  cout << minTime() << "\n";
  return 0;
}
