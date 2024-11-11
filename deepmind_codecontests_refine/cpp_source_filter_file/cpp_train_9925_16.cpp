#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, y1, x2, y2;
  while (scanf(" %*d %*d %d %d %d %d", &x1, &y1, &x2, &y2) == 4) {
    int a = abs(x1 - x2), b = abs(y1 - y2);
    if (min(a, b) < 2 && max(a, b) < 5)
      puts("First");
    else if (max(a, b) < 4)
      puts("First");
    else
      puts("Second");
  }
  return 0;
}
