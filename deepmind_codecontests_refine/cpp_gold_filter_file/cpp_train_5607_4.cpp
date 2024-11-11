#include <stdio.h>

int solve(int x, int y) {
  int ay = y > 0 ? y : -y;
  int ax = x > 0 ? x : -x;
  if(ax == ay) return x != y;
  if(ay < ax) return (x > 0) + ax - ay + (y > 0);
  return (x < 0) + ay - ax + (y < 0);
}

int main(){
  int x, y;
  scanf("%d %d", &x, &y);
  printf("%d\n", solve(x, y));
  return 0;
}