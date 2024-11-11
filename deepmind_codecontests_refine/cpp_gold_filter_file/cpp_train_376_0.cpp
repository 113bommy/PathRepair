#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  int x = abs(a - b), flag = 0;
  if (x % 2) {
    flag = 1;
  }
  x /= 2;
  int ans = (1 + x) * x;
  if (flag) ans += x + 1;
  printf("%d\n", ans);
  return 0;
}
