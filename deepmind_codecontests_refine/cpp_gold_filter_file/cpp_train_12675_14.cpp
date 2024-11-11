#include <bits/stdc++.h>
using namespace std;
long long int l, r, x, y, m, n;
int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  scanf("%lld %lld %lld %lld", &l, &r, &x, &y);
  n = y / x;
  int flag = 0;
  if (y % x != 0) {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i * i <= n; i++) {
    m = n / i;
    if (n % i == 0 && gcd(m, i) == 1 && l <= i * x && i * x <= r &&
        l <= m * x && m * x <= r) {
      if (m == i)
        flag++;
      else
        flag += 2;
    }
  }
  cout << flag << endl;
  return 0;
}
