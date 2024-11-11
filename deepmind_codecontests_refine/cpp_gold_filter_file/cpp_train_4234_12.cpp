#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x, y;
} r[11], b[11];
int p[11], R, B;
bool lineIntersectSide(Point A, Point B, Point C, Point D) {
  double fC = (C.y - A.y) * (A.x - B.x) - (C.x - A.x) * (A.y - B.y);
  double fD = (D.y - A.y) * (A.x - B.x) - (D.x - A.x) * (A.y - B.y);
  if (fC * fD > 0) return false;
  return true;
}
bool sideIntersectSide(Point A, Point B, Point C, Point D) {
  if (!lineIntersectSide(A, B, C, D)) return false;
  if (!lineIntersectSide(C, D, A, B)) return false;
  return true;
}
bool solve() {
  for (int i = 1; i <= R; i++) {
    Point A = r[i];
    Point B = b[p[i]];
    for (int j = 1; j <= R; j++) {
      if (i == j) continue;
      Point C = r[j];
      Point D = b[p[j]];
      if (sideIntersectSide(A, B, C, D)) return false;
    }
  }
  return true;
}
int main() {
  scanf("%d%d", &R, &B);
  if (R != B) {
    printf("No\n");
    return 0;
  }
  for (int i = 1; i <= R; i++) {
    scanf("%lf%lf", &r[i].x, &r[i].y);
  }
  for (int i = 1; i <= B; i++) {
    scanf("%lf%lf", &b[i].x, &b[i].y);
  }
  for (int i = 1; i <= B; i++) {
    p[i] = i;
  }
  do {
    if (solve()) {
      printf("Yes\n");
      return 0;
    }
  } while (next_permutation(p + 1, p + B + 1));
  printf("No\n");
  return 0;
}
