#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, d;
  scanf("%d %d", &m, &d);
  if (m == 2) {
    if (d == 1)
      printf("4\n");
    else
      printf("5\n");
  } else if (m == 4 || m == 6 || m == 9 || m == 11) {
    if (d == 7)
      printf("6\n");
    else
      printf("5\n");
  } else {
    if (d == 6 || d == 7)
      printf("6\n");
    else
      printf("5\n");
  }
  return 0;
}
