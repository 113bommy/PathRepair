#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:100000000")
int matrix[1010][1010];
int main() {
  int r, x, y, xa, ya;
  scanf("%d %d %d %d %d", &r, &x, &y, &xa, &ya);
  if (x == xa && y == ya) {
    printf("0");
    return 0;
  }
  r *= 2;
  double dist = sqrt((double)((double)(xa - x) * (double)(xa - x) +
                              (double)(ya - y) * (double)(ya - y)));
  printf("%d", (int)(dist / (double)r + 1.0 - 1e-11));
  return 0;
}
