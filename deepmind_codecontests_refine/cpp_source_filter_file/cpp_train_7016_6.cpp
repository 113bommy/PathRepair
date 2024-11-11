#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
  Point(int x = 0, int y = 0) : x(x), y(y) {}
};
bool cmp(Point a, Point b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}
Point P[10];
const int n = 8;
int check() {
  sort(P, P + n, cmp);
  if (P[1].x != P[2].x || P[2].x != P[3].x) return 0;
  if (P[4].x != P[5].x) return 0;
  if (P[6].x != P[7].x || P[7].x != P[8].x) return 0;
  if (P[3].x == P[4].x) return 0;
  if (P[5].x == P[6].x) return 0;
  if (P[1].y != P[4].y || P[4].y != P[6].y) return 0;
  if (P[2].y != P[7].y) return 0;
  if (P[3].y != P[5].y || P[5].y != P[8].y) return 0;
  if (P[1].y == P[2].y || P[2].y == P[3].y) return 0;
  return 1;
}
int main() {
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    P[i] = Point(x, y);
  }
  if (check())
    printf("respectable\n");
  else
    printf("ugly\n");
}
