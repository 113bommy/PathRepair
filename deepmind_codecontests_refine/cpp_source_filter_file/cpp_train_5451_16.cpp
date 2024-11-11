#include <bits/stdc++.h>
using namespace std;
int x, y, z, a, b, c;
int a0() {
  if (y < 0)
    return 1;
  else
    return 0;
}
int a1() {
  if (y > b)
    return 1;
  else
    return 0;
}
int a2() {
  if (a < 0)
    return 1;
  else
    return 0;
}
int a3() {
  if (z > c)
    return 1;
  else
    return 0;
}
int a4() {
  if (x < 0)
    return 1;
  else
    return 0;
}
int a5() {
  if (x > a)
    return 1;
  else
    return 0;
}
int d[10];
int main() {
  int i;
  scanf("%d%d%d", &x, &y, &z);
  scanf("%d%d%d", &a, &b, &c);
  for (i = 0; i < 6; i++) scanf("%d", &d[i]);
  int ans = 0;
  if (a0()) ans += d[0];
  if (a1()) ans += d[1];
  if (a2()) ans += d[2];
  if (a3()) ans += d[3];
  if (a4()) ans += d[4];
  if (a5()) ans += d[5];
  printf("%d\n", ans);
}
