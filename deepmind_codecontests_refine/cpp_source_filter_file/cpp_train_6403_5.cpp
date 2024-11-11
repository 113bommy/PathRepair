#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
long double PI = acos(-1);
struct Point {
  int x, y, id;
  Point(int a = 0, int b = 0, int c = 0) { x = a, y = b, id = c; }
  friend int cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
};
Point A[maxn];
int N;
long double ang[maxn];
bool cmp(Point a, Point b) { return cross(a, b) > 0; }
void Done() {
  int i = 1, j = N;
  for (int k = (1), _k = (N); k <= _k; k++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (y > 0 || (y == 0 && x > 0))
      A[i++] = Point(x, y, k);
    else
      A[j--] = Point(x, y, k);
  }
  sort(A + 1, A + i, cmp);
  sort(A + i, A + N + 1, cmp);
  for (int k = (1), _k = (N); k <= _k; k++)
    ang[k] = atan2(A[k].y, A[k].x) + (k >= i ? 2 * PI : 0);
  long double ans = 2 * PI - (ang[N] - ang[1]);
  int ansx = A[1].id, ansy = A[N].id;
  for (int i = (1), _i = (N - 1); i <= _i; i++) {
    long double rr = ang[i + 1] - ang[i];
    if (rr < ans) ans = rr, ansx = A[i].id, ansy = A[i + 1].id;
  }
  printf("%d %d\n", ansx, ansy);
}
int main() {
  for (; scanf("%d", &N) != EOF;) {
    Done();
  }
  return 0;
}
