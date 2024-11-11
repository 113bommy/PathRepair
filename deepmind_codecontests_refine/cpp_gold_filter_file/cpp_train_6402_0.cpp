#include <bits/stdc++.h>
using namespace std;
long long pow(long long x, int y) {
  long long ret = 1, z = x;
  while (y) {
    if (y & 1) ret = ret * z % 1000000007;
    z = z * z % 1000000007;
    y >>= 1;
  }
  return ret;
}
int main() {
  int n;
  while (~scanf("%d", &n)) {
    n++;
    long long ans = 1;
    for (int i = n + 1; i <= 2 * n; i++) {
      ans = ans * i % 1000000007;
    }
    for (int i = 1; i <= n; i++) {
      ans = ans * pow(1LL * i, 1000000007 - 2) % 1000000007;
    }
    printf("%I64d\n", ((ans - 1) % 1000000007 + 1000000007) % 1000000007);
  }
  return 0;
}
