#include <bits/stdc++.h>
int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  int ax, ay;
  scanf("%d", &ax);
  scanf("%d", &ay);
  int bx, by;
  scanf("%d", &bx);
  scanf("%d", &by);
  int cx, cy;
  scanf("%d", &cx);
  scanf("%d", &cy);
  if ((bx < ax && cx > ax) || (bx > ax && cx > ax)) {
    printf("NO\n");
  } else if ((by < ay && cy > ay) || (by > ay && cy > ay)) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
  return 0;
}
