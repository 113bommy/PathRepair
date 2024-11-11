#include <bits/stdc++.h>
using namespace std;
const int MILLION = 1000000;
struct Point {
  int x;
  int y;
  int pop;
  Point() {}
  Point(int _x, int _y, int _pop) : x(_x), y(_y), pop(_pop) {}
  bool operator<(const Point &b) const {
    return (x * x + y * y) < (b.x * b.x + b.y * b.y);
  }
};
int main() {
  int n, pop;
  scanf("%d%d", &n, &pop);
  vector<Point> vec;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    vec.push_back(Point(a, b, c));
  }
  sort(vec.begin(), vec.end());
  if (pop >= MILLION) {
    printf("0\n");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    pop += vec[i].pop;
    if (pop >= MILLION) {
      printf("%.7f\n", sqrt(vec[i].x * vec[i].x + vec[i].y * vec[i].y));
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
