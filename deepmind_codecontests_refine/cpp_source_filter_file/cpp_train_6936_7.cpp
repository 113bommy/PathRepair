#include <bits/stdc++.h>
using namespace std;
const long long p = 1000000007;
long long ksm(long long d, long long z) {
  long long r = d, ans = 1;
  while (z > 0) {
    if (z & 1) ans = ans * r % p;
    r = r * r % p;
    z >>= 1;
  }
  return ans;
}
long long inv(long long x) {
  long long ans = ksm(x, p - 2);
  return ans;
}
long long c(long long n, long long m) {
  if (m > n / 2) m = n - m;
  long long ans = 1;
  for (int i = 1; i <= m; i++) {
    ans = ans * (n - i + 1) % p;
  }
  for (int i = 1; i <= m; i++) ans = ans * inv(i) % p;
  return ans;
}
bool pd(int x) {
  for (int i = 2; i <= x / i; i++)
    if (x % i == 0) return 0;
  return 1;
}
int ds[1000], zs[1000], f = 0;
int main() {
  for (int i = 2; i <= 1000; i++) {
    if (pd(i)) ds[++f] = i;
  }
  int t, x, y;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &x, &y);
    memset(zs, 0, sizeof(zs));
    int tmp = x;
    for (int i = 1; i <= f; i++) {
      while (x % ds[i] == 0) {
        zs[i]++;
        x /= ds[i];
      }
    }
    long long ans = 1;
    if (x > 1) {
      ans = y % p;
    } else {
      for (int i = 1; i <= f; i++) ans = ans * c(zs[i] + y - 1, y - 1) % p;
    }
    ans = ans * ksm(2, y - 1) % p;
    printf("%lld\n", ans);
  }
  return 0;
}
