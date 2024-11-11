#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int a, b;
int main() {
  scanf("%d %d", &a, &b);
  int base = 1;
  while (a + b > 0) {
    ans += base * (((a % 3) + (b % 3)) % 3);
    a /= 3;
    b /= 3;
    base *= 3;
  }
  printf("%d", ans);
  return 0;
}
