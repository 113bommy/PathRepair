#include <bits/stdc++.h>
struct Point {
  long long int x;
  long long int y;
  std::string pToString() {
    std::string x_s(std::to_string(x));
    std::string y_s(std::to_string(y));
    std::string printP(x_s + " " + y_s);
    return printP;
  }
};
bool operator<(Point const &p1, Point const &p2) {
  if (p1.x == p2.x) {
    return p1.y < p2.y;
  }
  return p1.x < p2.x;
}
Point operator-(Point const &p1, Point const &p2) {
  long long x = p1.x - p2.x;
  long long y = p1.y - p2.y;
  Point temp = {x, y};
  return temp;
}
long long int cross(const Point &t1, const Point &t2, const Point &t3) {
  Point a = t1 - t3;
  Point b = t2 - t3;
  return a.x * b.y - b.x * a.y;
}
long long int getDist(Point const &p1, Point const &p2) {
  Point temp = p1 - p2;
  long long int dist = temp.x * temp.x + temp.y * temp.y;
  return dist;
}
void printStack(std::vector<Point> points) {
  for (Point p : points) {
    std::cout << p.pToString() << std::endl;
  }
}
void adjustPolygon(std::vector<Point> &polygon) {
  auto pointA = polygon[0];
  auto pointB = polygon[1];
  for (int i = 0; i < polygon.size(); i++) {
    polygon[i] = polygon[i] - pointB;
  }
  if (polygon[1].y > polygon[2].y) {
    for (int i = 0; i < polygon.size(); i++) {
      polygon[i].x *= -1;
      polygon[i].y *= -1;
    }
  }
}
long double getIntersect(Point a, Point b) {
  if (a.y == b.y) {
    return 1e9L;
  }
  if (a.y > b.y) {
    std::swap(a, b);
  }
  long double slope = (long double)b.y / (b.y - a.y);
  return b.x + (a.x - b.x) * slope;
}
int getTowers(std::vector<Point> polygon) {
  int numTowers;
  long long int min = 0;
  long long int max = polygon[0].x;
  Point maxBase = polygon[0];
  Point minBase = polygon[1];
  if (polygon.size() < 3) {
    return (max - min) + 1;
  }
  for (int i = 2; i < polygon.size() - 1; i++) {
    long long int crs1 = cross(polygon[i + 1], polygon[i], maxBase);
    long long int crs2 = cross(polygon[i + 1], polygon[i], minBase);
    if (crs1 < 0 && crs2 < 0) {
      return 0;
    }
    long double inter = getIntersect(polygon[i], polygon[i + 1]);
    if (crs1 < 0) {
      max = std::min(max, (long long int)std::floor(inter));
    }
    if (crs2 < 0) {
      min = std::max(min, (long long int)std::ceil(inter));
    }
    if (min > max) {
      return 0;
    }
  }
  numTowers = max - min;
  return numTowers + 1;
}
int main() {
  int numPoints;
  long long int inputX;
  long long int inputY;
  std::vector<Point> polygon;
  int numTowers;
  std::cin >> numPoints;
  for (int i = 0; i < numPoints; i++) {
    std::cin >> inputX >> inputY;
    Point p = {inputX, inputY};
    polygon.emplace_back(p);
  }
  adjustPolygon(polygon);
  numTowers = getTowers(polygon);
  if (numTowers < 0) {
    std::cout << "0" << std::endl;
  } else {
    std::cout << numTowers << std::endl;
  }
  return 0;
}
