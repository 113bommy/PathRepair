#include <bits/stdc++.h>
using namespace std;
int fpow(int a, int n, int mod) {
  long long tmp = a, ans = 1;
  while (n) {
    if (n & 1) ans *= tmp, ans %= mod;
    tmp *= tmp, tmp %= mod, n >>= 1;
  }
  return ans;
}
int n, p[1000000 + 5], cnt;
bool check(int x) {
  x %= n + 1;
  for (int i = 1; i <= cnt; i++)
    if (fpow(x, n / p[i], n + 1) == 1) return 0;
  return 1;
}
int main() {
  int x;
  scanf("%d%d", &n, &x);
  int tmp = n;
  for (int i = 2; i <= tmp; i++)
    while (tmp % i == 0) {
      if (p[cnt] != i) p[++cnt] = i;
      tmp /= i;
    }
  for (int i = 2; i * i <= n + 1; i++)
    if ((n + 1) % i == 0) {
      puts("-1");
      return 0;
    }
  for (int i = 1; i <= n && i < x; i++)
    if (check(x - i)) {
      printf("%d\n", x - i);
      return 0;
    }
  puts("-1");
  return 0;
}
