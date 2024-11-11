#include <bits/stdc++.h>
using namespace std;
int n, x, a[5];
int main() {
  scanf("%d%d", &n, &x);
  n = n % 6;
  switch (n) {
    case 0:
      a[0] = 0;
      a[1] = 1;
      a[2] = 2;
      break;
    case 1:
      a[0] = 1;
      a[1] = 0;
      a[2] = 2;
      break;
    case 2:
      a[0] = 1;
      a[1] = 2;
      a[2] = 0;
      break;
    case 3:
      a[0] = 2;
      a[1] = 1;
      a[2] = 0;
      break;
    case 4:
      a[0] = 2;
      a[1] = 0;
      a[2] = 1;
      break;
    case 5:
      a[0] = 0;
      a[1] = 2;
      a[2] = 1;
      break;
  }
  printf("%d", a[x]);
  return 0;
}
