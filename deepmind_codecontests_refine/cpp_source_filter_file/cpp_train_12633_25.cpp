#include <bits/stdc++.h>
using namespace std;
struct pt {
  double x, y;
  pt(double _x = 0, double _y = 0) : x(_x), y(_y) {}
  void print() { printf("%.18lf %.18lf\n", x, y); }
};
inline pt operator-(const pt &p1, const pt &p2) {
  return pt(p1.x - p2.x, p1.y - p2.y);
}
inline pt operator+(const pt &p1, const pt &p2) {
  return pt(p1.x + p2.x, p1.y + p2.y);
}
pt p0[5];
int main() {
  p0[0] = pt(3.830127018922193, 3.366025403784439);
  p0[1] = pt(-3.601321235851749, 10.057331467373021);
  p0[2] = pt(0.466045194906253, 19.192786043799030);
  p0[3] = pt(10.411264148588986, 18.147501411122495);
  p0[4] = pt(12.490381056766580, 8.366025403784439);
  for (int i = 1; i < 4; i++) p0[i] = (p0[i] - p0[0]);
  p0[0] = pt(0, 0);
  int n;
  while (scanf("%d", &n) >= 1) {
    pt now(0, 0);
    printf("%d\n", 4 * n + 1);
    now.print();
    for (int it = 0; it < n; it++) {
      for (int i = 1; i < 5; i++) (now + p0[i]).print();
      now = now + p0[2];
    }
    printf("1 2 3 4 5\n");
    for (int i = 1; i < n; i++)
      printf("%d %d %d %d %d\n", 4 * i - 1, 4 * i + 2, 4 * i + 3, 4 * i + 4,
             4 * i + 5);
    printf("1");
    for (int i = 0; i < n - 1; i++) printf(" %d", 3 + 4 * i);
    for (int i = n - 1; i >= 0; i--) {
      printf(" %d", 3 + 4 * i);
      printf(" %d", 5 + 4 * i);
      printf(" %d", 2 + 4 * i);
      printf(" %d", 4 + 4 * i);
    }
    printf(" 1\n");
  }
  return 0;
}
