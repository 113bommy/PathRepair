#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000;
inline double sqr(double x) { return x * x; }
double radius(double xa, double ra, double xb) {
  return sqr(xb - xa) / (4 * ra);
}
int searchpos(int rad, int last, int lastrad) {
  int left = last + 1, right = inf, mid;
  while (left + 1 < right) {
    mid = (left + right) / 2;
    if (radius(last, lastrad, mid) < rad)
      left = mid;
    else
      right = mid;
  }
  return right;
}
int main() {
  static int pos[500];
  int first = 20000;
  printf("%d\n", 303);
  printf("%d %d\n", 0, first);
  int last = 0, lastrad = first;
  int x1;
  for (int i = 1; i <= 302; i++) {
    pos[i] = last = searchpos(302 - i + 1, last, lastrad);
    printf("%d %d\n", last, 302 - i + 1);
    if (i == 1) x1 = last;
    lastrad = 302 - i + 1;
  }
  int nowrad = inf;
  for (int i = 1; i <= 302; i++)
    pos[303] = max(pos[303], searchpos(inf, pos[i], 302 - i + 1));
  printf("%d %d\n", pos[303], inf);
  return 0;
}
