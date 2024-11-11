#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
} a[10];
int main() {
  for (int i = 1; i <= 3; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
  }
  printf("3\n");
  printf("%d %d\n", a[1].x + a[3].x - a[2].x, a[1].y + a[3].y - a[2].y);
  printf("%d %d\n", a[2].x + a[3].x - a[1].x, a[2].y + a[3].y - a[1].y);
  printf("%d %d\n", a[1].x + a[3].x - a[2].x, a[1].y + a[3].y - a[2].y);
  return 0;
}
