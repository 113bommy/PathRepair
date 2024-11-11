#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int x, sol;
int main() {
  scanf("%d", &n);
  while (n--) {
    sol = 0;
    scanf("%d%d", &a, &b);
    while (true) {
      if (a > b) swap(a, b);
      x = b / a;
      b -= a * x;
      sol += x;
      if (a == 0 || b == 0) break;
    }
    printf("%d", sol);
  }
  return 0;
}
