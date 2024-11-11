#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b;
  while (scanf("%d %d %d %d", &n, &m, &a, &b) == 4) {
    a--;
    b--;
    int ans, ant;
    if (b == n - 1) {
      if (a % m == 0)
        ant = 1;
      else
        ant = 2;
    }
    if (a % m == 0 && b % m == m - 1) {
      ans = 1;
    } else if (b / m - a / m == 0) {
      ans = 1;
    } else if (b / m - a / m == 1) {
      ans = 2;
    } else if (b % m + 1 == a % m) {
      ans = 2;
    } else if (a % m == 0 || b % m == m - 1) {
      ans = 2;
    } else {
      ans = 3;
    }
    printf("%d\n", min(ans, ant));
  }
  return 0;
}
