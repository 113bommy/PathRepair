#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e4 + 44;
const long long INF = 1e11 + 9;
const double eps = 1e-12;
int main() {
  int t;
  scanf("%d", &t);
  long long x1, y1, x2, y2, n, m;
  long long x3, y3, x4, y4;
  long long answ = 0, ansb = 0;
  while (t--) {
    scanf("%lld", &n);
    scanf("%lld", &m);
    if (n % 2 == 0 || m % 2 == 0) {
      answ = ansb = n * m / 2;
    } else {
      answ = (n * m) / 2 + 1;
      ansb = answ - 1;
    }
    scanf("%lld", &x1);
    scanf("%lld", &y1);
    scanf("%lld", &x2);
    scanf("%lld", &y2);
    long long dx = x2 - x1 + 1, dy = y2 - y1 + 1;
    if (dx % 2 == 0 || dy % 2 == 0) {
      answ += (dx * dy) / 2;
      ansb -= (dx * dy) / 2;
    } else {
      if (x1 % 2 && y1 % 2 || x1 % 2 == 0 && y1 % 2 == 0) {
        answ += (dx * dy) / 2;
        ansb -= (dx * dy) / 2;
      } else {
        answ += (dx * dy) / 2 + 1;
        ansb -= (dx * dy) / 2 + 1;
      }
    }
    scanf("%lld", &x3);
    scanf("%lld", &y3);
    scanf("%lld", &x4);
    scanf("%lld", &y4);
    dx = x4 - x3 + 1, dy = y4 - y3 + 1;
    if (dx % 2 == 0 || dy % 2 == 0) {
      answ -= (dx * dy) / 2;
      ansb += (dx * dy) / 2;
    } else {
      if (x3 % 2 && y3 % 2 || x3 % 2 == 0 && y3 % 2 == 0) {
        answ -= (dx * dy) / 2 + 1;
        ansb += (dx * dy) / 2 + 1;
      } else {
        answ -= (dx * dy) / 2;
        ansb += (dx * dy) / 2;
      }
    }
    long long x5, y5, x6, y6;
    if (y3 > y2 || y4 < y1 || x3 > x2 || x4 < x1) {
      printf("%lld %lld\n", answ, ansb);
      continue;
    }
    x5 = max(x1, x3);
    y5 = max(y1, y3);
    x6 = min(x2, x4);
    y6 = min(y2, y4);
    dx = x6 - x5 + 1, dy = y6 - y5 + 1;
    if (dx % 2 == 0 || dy % 2 == 0) {
      if (x5 % 2 == 0 && y5 % 2 == 0 || x5 % 2 && y5 % 2) {
        answ -= dx * dy / 2;
        ansb += dx * dy / 2;
      } else {
        answ -= dx * dy / 2;
        ansb += dx * dy / 2;
      }
    } else {
      if (x5 % 2 && y5 % 2 || x5 % 2 == 0 && y5 % 2 == 0) {
        answ -= dx * dy / 2;
        ansb += dx * dy / 2;
      } else {
        answ -= dx * dy / 2 + 1;
        ansb += dx * dy / 2 + 1;
      }
    }
    printf("%lld %lld\n", answ, ansb);
  }
}
