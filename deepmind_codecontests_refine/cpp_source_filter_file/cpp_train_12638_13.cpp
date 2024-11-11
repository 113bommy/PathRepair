#include <bits/stdc++.h>
struct Point {
  long long int x;
  long long int y;
  std::string pToString() {
    return std::to_string(x) + " " + std::to_string(y);
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
  Point a = t2 - t1;
  Point b = t3 - t2;
  return a.x * b.y - b.x * a.y;
}
long long int getDist(Point const &p1, Point const &p2) {
  Point temp = p1 - p2;
  long long int dist = temp.x * temp.x + temp.y * temp.y;
  return dist;
}
struct SortByDist {
  Point _c;
  SortByDist(Point &c) : _c(c) {}
  bool operator()(Point &a, Point &b) const {
    long long int angle = cross(a, _c, b);
    if (angle == 0) {
      return getDist(_c, b) > getDist(_c, a);
    }
    return angle < 0;
  }
};
void printStack(std::vector<Point> points) {
  for (Point p : points) {
    std::cout << p.pToString() << std::endl;
  }
}
std::vector<Point> getStack(std::vector<Point> centers) {
  std::vector<Point> stack;
  if (centers.size() < 3) {
    stack = centers;
    return stack;
  }
  stack.emplace_back(centers[0]);
  int j = 1;
  for (int i = 1; i < centers.size(); i++) {
    while (stack.size() > 2 &&
           cross(stack[j - 2], stack[j - 1], centers[i]) <= 0) {
      j--;
      stack.pop_back();
    }
    stack.emplace_back(centers[i]);
    j++;
  }
  return stack;
}
std::vector<Point> getCompares(std::vector<Point> centers, long long int d,
                               int i) {
  std::vector<Point> compares;
  for (int j = i++; j < centers.size(); j++) {
    if (getDist(centers[i], centers[j]) >= d) {
      compares.emplace_back(centers[j]);
    }
  }
  return compares;
}
bool isNewLower(std::vector<Point> stack, long long int d) {
  for (int i = 0; i < stack.size(); i++) {
    long long int max = 0;
    for (int j = i + 1; j < stack.size(); j++) {
      long long int dist = getDist(stack[i], stack[j]);
      if (dist >= d) return true;
      if (dist < max) continue;
      max = dist;
    }
  }
  return false;
}
bool testCheck(std::vector<Point> const &centers, long long int &d) {
  std::vector<Point> compares;
  std::vector<Point> stack;
  for (int i = 0; i < centers.size(); i++) {
    compares = getCompares(centers, d, i);
    printStack(compares);
    stack = getStack(compares);
    printStack(stack);
    if (isNewLower(stack, d)) {
      std::cout << d << std::endl;
      return true;
    } else
      continue;
  }
  return false;
}
bool check(std::vector<Point> const &centers, long long int &d) {
  std::vector<Point> compares;
  std::vector<Point> stack;
  for (int i = 0; i < centers.size(); i++) {
    compares = getCompares(centers, d, i);
    stack = getStack(compares);
    if (isNewLower(stack, d))
      return true;
    else
      continue;
  }
  return false;
}
int main() {
  int numCenters;
  long long int inputX;
  long long int inputY;
  std::vector<Point> centers;
  std::cin >> numCenters;
  for (int i = 0; i < numCenters; i++) {
    std::cin >> inputX >> inputY;
    Point p = {inputX, inputY};
    centers.emplace_back(p);
  }
  auto min = std::min_element(centers.begin(), centers.end());
  std::swap(*centers.begin(), *min);
  Point first = centers[0];
  std::sort(centers.begin()++, centers.end(), SortByDist(first));
  long long int lower = 0;
  long long int upper = 800000000;
  long long int d = 0;
  while (upper - lower > 1) {
    d = (lower + upper) / 2;
    if (check(centers, d)) {
      lower = d;
    } else {
      upper = d;
    }
  }
  std::cout.precision(12);
  std::cout.fixed;
  std::cout << std::sqrt(lower) / 2 << std::endl;
  return 0;
}
