#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  if (x > y)
    return x % y ? gcd(x % y, y) : y;
  else
    return y % x ? gcd(y % x, x) : x;
}
signed main() {
  long long n, m, T;
  cin >> n >> m >> T;
  long long x = gcd(n, m);
  long long block1 = n / x, block2 = m / x;
  while (T--) {
    long long s1, s2, e1, e2;
    cin >> s1 >> s2 >> e1 >> e2;
    long long num1 = 0, num2 = 0;
    if (s1 == 1)
      num1 = (s2 % block1 ? s2 / block1 + 1 : s2 / block1);
    else
      num1 = (s2 % block2 ? s2 / block2 + 1 : s2 / block2);
    if (e1 == 1)
      num2 = (e2 % block1 ? e2 / block1 + 1 : e2 / block1);
    else
      num2 = (e2 % block2 ? e2 / block2 + 1 : e2 / block2);
    if (num1 != num2)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
