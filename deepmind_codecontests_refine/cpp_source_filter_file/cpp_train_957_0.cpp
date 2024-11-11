#include <bits/stdc++.h>
int diru[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dirv[] = {-1, 0, 1, -1, 1, -1, 0, 1};
using namespace std;
template <class T>
T sq(T n) {
  return n * n;
}
template <class T>
T gcd(T a, T b) {
  return (b != 0 ? gcd<T>(b, a % b) : a);
}
template <class T>
T lcm(T a, T b) {
  return (a / gcd<T>(a, b) * b);
}
template <class T>
bool inside(T a, T b, T c) {
  return a <= b && b <= c;
}
template <class T>
void setmax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
void setmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
T power(T N, T P) {
  return (P == 0) ? 1 : N * power(N, P - 1);
}
int main() {
  int n, T, t = 1, m, i, j, k;
  int t1, t2, t0;
  int y1, y2, Y1, Y2;
  int x1, x2;
  while (scanf("%d", &t1) == 1) {
    scanf("%d", &t2);
    scanf("%d", &x1);
    scanf("%d", &x2);
    scanf("%d", &t0);
    if (t2 == t0) {
      if (t1 != t2)
        printf("0 %d\n", x2);
      else
        printf("%d %d\n", x1, x2);
      return 0;
    }
    double M = (1 << 29);
    M *= M;
    for (y1 = 0; y1 < x1 + 1; y1++) {
      long long int y2 =
          (long long int)(((double)(t0 - t1) / (double)(t2 - t0)) * (double)y1);
      for (i = -2; i < 3; i++) {
        int yy = y2 + i;
        if (yy < 0) yy = 0;
        if (y1 + yy == 0) continue;
        if (yy > (long long int)x2) continue;
        double p = (double)((double)t1 * (double)y1 + (double)t2 * (double)yy) /
                   (double)(y1 + yy);
        if (p < (double)t0)
          ;
        else {
          if (M > p || ((fabs(M - p) < 1e-9) && Y1 + Y2 < y1 + yy)) {
            M = p;
            Y1 = y1;
            Y2 = yy;
          }
        }
      }
    }
    printf("%d %d\n", Y1, Y2);
  }
  return 0;
}
