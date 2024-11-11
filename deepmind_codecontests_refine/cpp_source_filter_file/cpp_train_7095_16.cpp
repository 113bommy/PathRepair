#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, x, b, y;
  scanf("%d%d%d%d", &n, &a, &x, &b, &y);
  a--, b--, x--, y--;
  if (a == b) {
    printf("YES\n");
    return 0;
  }
  while (a != x && b != y) {
    a = (a + 1) % n;
    b = ((b - 1) % n + n) % n;
    if (a == b) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}
