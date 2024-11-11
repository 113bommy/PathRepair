#include <bits/stdc++.h>
inline unsigned int getuint() {
  char w = getchar();
  while (w < '0' || '9' < w) w = getchar();
  unsigned int ans = 0;
  for (; '0' <= w && w <= '9'; w = getchar()) ans = ans * 10 + w - '0';
  return ans;
}
inline unsigned long long getuint64() {
  char w = getchar();
  while (w < '0' || '9' < w) w = getchar();
  unsigned long long ans = 0;
  for (; '0' <= w && w <= '9'; w = getchar()) ans = ans * 10 + w - '0';
  return ans;
}
long long a[23333];
int main() {
  long long n = getuint64();
  int m = 0;
  if (n % 3) return puts("0"), 0;
  n /= 3;
  for (long long i = 1; i * i <= n; i++)
    if (n % i == 0) {
      a[++m] = i;
      if (i * i < n) a[++m] = n / i;
    }
  std::sort(a + 1, a + m + 1);
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    long long x = a[i];
    if (x * x * x > n) break;
    long long limit = n / x;
    for (int j = i; j <= m; j++)
      if (limit % a[j] == 0) {
        long long y = a[j];
        if (limit % y || y * y > limit) break;
        long long z = limit / y, t = x + y + z;
        if (t & 1) continue;
        t >>= 1;
        long long a = t - x, b = t - y, c = t - z;
        if (a < 0 || b < 0 || c < 0) continue;
        if (a == b && b == c)
          ans++;
        else if (a == b || b == c || a == c)
          ans += 3;
        else
          ans += 6;
      }
  }
  printf("%d\n", ans);
  return 0;
}
