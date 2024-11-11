#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x1, y1, x2, y2;
  scanf("%d%d%d%d%d%d", &n, &m, &x1, &y1, &x2, &y2);
  if (max(abs(x1 - x2), abs(y1 - y2)) <= 3) {
    printf("First\n");
  } else {
    if (max(abs(x1 - x2), abs(y1 - y2)) == 4 &&
        min(abs(x1 - x2), abs(y1 - y2)) == 0)
      printf("First\n");
    else
      printf("Second\n");
  }
}
