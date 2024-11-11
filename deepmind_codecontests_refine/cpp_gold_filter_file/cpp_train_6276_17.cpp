#include <bits/stdc++.h>
using namespace std;
int xx1, xx2, yy1, yy2;
int x, y, r, ans;
char v[30000000];
int zhuan(int x, int y) { return (x + 1000) * 10000 + y + 1000; }
void swap(int &a, int &b) {
  int h = a;
  a = b;
  b = h;
}
bool dis(int xx, int yy) {
  return (xx - x) * (xx - x) + (yy - y) * (yy - y) <= r * r;
}
void fun(int x1, int y1, int x2, int y2) {
  if (x1 > x2) swap(x1, x2);
  if (y1 > y2) swap(y1, y2);
  for (int i = x1; i <= x2; i++)
    for (int j = y1; j <= y2; j++) {
      int k = zhuan(i, j);
      if (v[k] == 0 && dis(i, j)) {
        v[k] = 1;
        ans++;
      }
    }
}
int main() {
  while (scanf("%d %d %d %d", &xx1, &yy2, &xx2, &yy1) != EOF) {
    if (xx1 > xx2) swap(xx1, xx2);
    if (yy1 > yy2) swap(yy1, yy2);
    int n, i, j, k, w;
    memset(v, 0, sizeof(v));
    scanf("%d", &n);
    ans = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d %d %d", &x, &y, &r);
      fun(xx1, yy1, xx1, yy2);
      fun(xx1, yy2, xx2, yy2);
      fun(xx2, yy2, xx2, yy1);
      fun(xx2, yy1, xx1, yy1);
    }
    w = (xx2 - xx1 + 1) * 2 + (yy2 - yy1 + 1) * 2 - 4;
    if (xx2 == xx1 && yy1 == yy2) w = 1;
    printf("%d\n", w - ans);
  }
  return 0;
}
