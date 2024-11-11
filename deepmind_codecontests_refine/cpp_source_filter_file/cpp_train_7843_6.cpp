#include <bits/stdc++.h>
using namespace std;
int x;
bool b[15];
int f(int x) {
  int res = 1;
  while (x) {
    if (!b[x % 10]) res = 0;
    x /= 10;
  }
  return res;
}
int main() {
  scanf("%d", &x);
  int tmp = x;
  while (tmp) {
    b[tmp % 10] = 1;
    tmp /= 10;
  }
  int ans = 0;
  for (int i = 1; i * i <= x; ++i)
    if (x % i == 0) {
      ans += f(i);
      if (i * i != x) ans += f(x / i);
    }
  printf("%d\n", ans);
  return 0;
}
