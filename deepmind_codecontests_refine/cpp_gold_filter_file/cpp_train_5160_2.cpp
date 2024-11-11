#include <bits/stdc++.h>
using namespace std;
int a[5010];
int n;
int main() {
  memset(a, 0, sizeof(a));
  scanf("%d", &n);
  int x, y, z;
  printf("? 1 2\n");
  fflush(stdout);
  scanf("%d", &x);
  printf("? 2 3\n");
  fflush(stdout);
  scanf("%d", &y);
  printf("? 1 3\n");
  fflush(stdout);
  scanf("%d", &z);
  a[2] = (x + y - z) / 2;
  a[1] = x - a[2];
  a[3] = z - a[1];
  for (int i = 4; i <= n; i++) {
    printf("? %d %d\n", i - 1, i);
    fflush(stdout);
    scanf("%d", &x);
    a[i] = x - a[i - 1];
  }
  printf("!");
  for (int i = 1; i <= n; i++) {
    printf(" %d", a[i]);
  }
  printf("\n");
  fflush(stdout);
}
