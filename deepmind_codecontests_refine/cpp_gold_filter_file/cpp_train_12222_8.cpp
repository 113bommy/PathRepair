#include <bits/stdc++.h>
using namespace std;
char s[100005];
long long ans, x, y, z, len, k;
long long qpow(long long a, long long p) {
  long long ret = 1, base = a % 1000000007;
  while (p) {
    if (p & 1) ret = ret * base % 1000000007;
    base = base * base % 1000000007;
    p >>= 1;
  }
  return ret;
}
int main() {
  scanf("%s", s);
  scanf("%d", &k);
  len = strlen(s);
  ans = 0;
  for (int i = 0; i < len; i++)
    if (s[i] == '5' || s[i] == '0') {
      z = qpow(2, i);
      x = (qpow(2, len * k) - 1 + 1000000007) % 1000000007;
      y = qpow(qpow(2, len) - 1, 1000000007 - 2);
      ans = (ans + ((z * x) % 1000000007 * y) % 1000000007) % 1000000007;
    }
  printf("%I64d\n", ans);
  return 0;
}
