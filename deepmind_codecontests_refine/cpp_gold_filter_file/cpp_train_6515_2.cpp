#include <bits/stdc++.h>
using namespace std;
int ans, a, b, n, x;
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    if (n == 0) a = x;
    b = max(b, x);
  }
  printf("%d\n", a ^ b);
  return 0;
}
