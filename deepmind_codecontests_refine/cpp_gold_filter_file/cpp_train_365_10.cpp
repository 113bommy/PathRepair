#include <bits/stdc++.h>
using namespace std;
struct pointVector {
  long long int x;
  long long int y;
};
bool crossProductIsPositive(pointVector A, pointVector B, pointVector C) {
  double cross = ((B.x - A.x) * (C.y - A.y)) - ((B.y - A.y) * (C.x - A.x));
  if (cross <= 0) {
    return false;
  }
  return true;
}
long long int xIntercept(pointVector A, pointVector B) {
  return ((B.x * A.y - A.x * B.y) / (A.y - B.y));
}
long long int xInterceptLow(pointVector A, pointVector B) {
  float h = (((float)B.x * (float)A.y - (float)A.x * (float)B.y) /
             ((float)A.y - (float)B.y));
  return (long long int)ceil(h);
}
int main() {
  long long int N, x, y, x0, y0, X1, Y1;
  bool toLeft = false;
  cin >> N;
  vector<pointVector> points;
  pointVector P0, P1, P;
  cin >> X1 >> Y1;
  cin >> x0 >> y0;
  P0 = {X1 - x0, Y1 - y0};
  P1 = {x0 - x0, y0 - y0};
  if (P1.x > P0.x) {
    toLeft = true;
    P0.x *= -1;
    P0.y *= -1;
  }
  points.push_back(P0);
  points.push_back(P1);
  for (int i = 0; i < N - 2; ++i) {
    cin >> x >> y;
    if (toLeft)
      P = {-1 * (x - x0), -1 * (y - y0)};
    else
      P = {x - x0, y - y0};
    points.push_back(P);
  }
  long long int lower = 0, upper = points[0].x;
  for (int i = 2; i + 1 < N; ++i) {
    if (crossProductIsPositive(P0, points[i], points[i + 1]) &&
        crossProductIsPositive(P1, points[i], points[i + 1])) {
      cout << 0 << endl;
      return 0;
    }
    long long int y0 = points[i].y, y1 = points[i + 1].y, xInter;
    if (y1 - y0 != 0) {
      if (crossProductIsPositive(P0, points[i], points[i + 1])) {
        xInter = xIntercept(points[i], points[i + 1]);
        upper = min(upper, xInter);
      }
      if (crossProductIsPositive(P1, points[i], points[i + 1])) {
        xInter = xInterceptLow(points[i], points[i + 1]);
        lower = max(lower, xInter);
      }
    }
  }
  if (upper >= lower) {
    cout << (long long int)(upper - lower) + 1 << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
