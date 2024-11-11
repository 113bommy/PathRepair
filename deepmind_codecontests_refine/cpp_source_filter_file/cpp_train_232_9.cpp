#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
const int N = 1e5 + 10;
int a[N], n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  if (n == 1) {
    puts("1 1\n0\n1 1\n0\n1 1");
    printf("%d\n", -a[1]);
    return 0;
  }
  printf("%d %d\n", 1, n);
  for (int i = 1; i <= n; i++)
    printf("%lld%c", -a[i] * 1ll * n, (i == n) ? '\n' : ' ');
  printf("%d %d\n", 1, n - 1);
  for (int i = 1; i <= n - 1; i++)
    printf("%lld%c", a[i] * 1ll * (n - 1), (i == n - 1) ? '\n' : ' ');
  printf("%d %d\n", n, n);
  printf("%lld\n", -a[n] * 1ll * n);
  return 0;
}
