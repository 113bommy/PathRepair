#include <bits/stdc++.h>
using namespace std;
long long n, s, num, ans, a[200010];
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ '0');
    c = getchar();
  }
  return x * f;
}
int main() {
  n = read();
  s = read();
  for (int i = 1; i <= n; i++)
    if (i == s)
      ans += read() > 0;
    else
      a[read()]++;
  for (int i = 1; num < n; i++) {
    num += a[i] ? a[i] : 1;
    ans += a[i] == 0;
  }
  printf("%lld", ans);
  return 0;
}
