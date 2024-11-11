#include <bits/stdc++.h>
struct pnt {
  int x, y;
};
int x, y, z;
int a, b, c;
int ar[7];
int kenar() {
  pnt p1, p2, p3, p4;
  pnt vas;
  p1.x = 0;
  p1.y = 0;
  p2.x = a;
  p2.y = 0;
  p3.x = a;
  p2.y = c;
  p4.x = 0;
  p4.y = c;
  vas.x = x;
  vas.y = z;
  int res = 0;
  if (vas.y < p1.y) res += ar[3];
  if (vas.y > p3.y) res += ar[4];
  if (vas.x < p1.x) res += ar[5];
  if (vas.x > p2.x) res += ar[6];
  return res;
}
int yukari() {
  if (y > b) return ar[2];
  if (y < 0) return ar[1];
  return 0;
}
int main() {
  scanf(" %d %d %d %d %d %d", &x, &y, &z, &a, &b, &c);
  scanf(" %d %d %d %d %d %d", &ar[1], &ar[2], &ar[3], &ar[4], &ar[5], &ar[6]);
  printf("%d\n", kenar() + yukari());
  return 0;
}
