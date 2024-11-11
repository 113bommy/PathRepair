#include <bits/stdc++.h>
using namespace std;
int m = 1e6 + 3;
int modadd(int a, int b) { return (a + b + m) % m; }
int modprod(int a, int b) { return (1ll * a * b) % m; }
int main() {
  int n;
  scanf("%d", &n);
  int last = 3;
  int val = 4;
  for (int i = 2; i <= n; ++i) {
    last = modadd(modprod(3, last), val);
    val = modprod(val, 4);
  }
  int ans = modadd(val, -last);
  if (n == 0)
    printf("1");
  else
    printf("%d", ans);
  return 0;
}
