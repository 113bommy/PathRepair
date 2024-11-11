#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int n;
  scanf("%d", &n);
  int m;
  scanf("%d", &m);
  int x;
  scanf("%d", &x);
  int y;
  scanf("%d", &y);
  int a;
  scanf("%d", &a);
  int b;
  scanf("%d", &b);
  int d = gcd(a, b);
  a /= d;
  b /= d;
  int k1 = n / a, k2 = m / b;
  int k = min(k1, k2);
  int w = k * a, h = k * b;
  int x1, y1, x2, y2;
  if (w & 1) {
    x1 = x - (w / 2) - 1;
    x2 = x + (w / 2);
  } else {
    x1 = x - (w / 2);
    x2 = x + (w / 2);
  }
  if (h & 1) {
    y1 = y - (h / 2) - 1;
    y2 = y + (h / 2);
  } else {
    y1 = y - (h / 2);
    y2 = y + (h / 2);
  }
  if (x1 < 0) {
    x2 -= x1;
    x1 = 0;
  }
  if (x2 > n) {
    x1 -= (x2 - n);
    x2 = n;
  }
  if (y1 < 0) {
    y2 -= y1;
    y1 = 0;
  }
  if (y2 > n) {
    y1 -= (y2 - m);
    y2 = m;
  }
  printf("%d %d %d %d\n", x1, y1, x2, y2);
}
