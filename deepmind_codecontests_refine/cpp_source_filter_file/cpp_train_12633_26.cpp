#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
struct point {
  double x, y;
  point() { x = y = 0; }
  point(double a, long double b) {
    x = a;
    y = b;
  }
};
point operator+(point a, point b) { return point(a.x + b.x, a.y + b.y); }
point operator-(point a, point b) { return point(a.x - b.x, a.y - b.y); }
point operator*(point a, int b) { return point(a.x * b, a.y * b); }
void print(point p) { printf("%.9f %.9f\n", p.x, p.y); }
int main() {
  int n;
  scanf("%d", &n);
  point p[5];
  p[4] = point(3.830127018922193, 3.366025403784439);
  p[0] = point(-3.601321235851749, 10.057331467373021);
  p[3] = point(0.466045194906253, 19.192786043799030);
  p[1] = point(10.411264148588986, 18.147501411122495);
  p[2] = point(12.490381056766580, 8.366025403784439);
  point dir = p[1] - p[0];
  printf("%d\n", 4 * n + 1);
  print(p[0]);
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= 4; j++) print(p[j] + dir * i);
  printf("1 4 2 3 5\n");
  if (n >= 2) printf("2 8 6 7 9\n");
  for (int i = 2; i < n; i++)
    printf("%d %d %d %d %d\n", 4 * i - 2, 4 * i + 4, 4 * i + 2, 4 * i + 3,
           4 * i + 5);
  for (int i = 4 * (n - 1) + 1; i > 0; i -= 4) printf("%d ", i + 1);
  printf("1 ");
  for (int i = 0; i < n; i++)
    printf("%d %d %d %d", 4 * i + 3, 4 * i + 4, 4 * i + 5, 4 * i + 2);
  printf("\n");
  return 0;
}
