#include <bits/stdc++.h>
using namespace std;
int n, m, xa, ya, xb, yb;
int main() {
  scanf("%d%d%d%d%d%d", &n, &m, &xa, &ya, &xb, &yb);
  if (abs(xa - xb) >= 5 || abs(ya - yb) >= 5) {
    printf("Second");
    return 0;
  }
  if (abs(xa - xb) == 4 && abs(ya - yb) == 4) {
    printf("Second");
    return 0;
  }
  if (abs(xa - xb) == 4 && abs(ya - yb) == 3) {
    printf("Second");
    return 0;
  }
  if (abs(xa - xb) == 3 && abs(ya - yb) == 4) {
    printf("Second");
    return 0;
  }
  printf("First");
  return 0;
}
