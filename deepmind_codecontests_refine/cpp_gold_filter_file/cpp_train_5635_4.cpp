#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, t = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') t = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * t;
}
int t;
long long n, k;
long long f[34];
inline long long check() {
  for (register long long i = 0; i < n; ++i) {
    long long l = 0, r = 0, up = n - i;
    for (register long long j = 1; j <= up; ++j) l += (1ll << j) - 1;
    if (k < l) continue;
    r = f[n] - ((1ll << (up + 1)) - 1) * f[i];
    if (k > r) continue;
    return i;
  }
  return -1;
}
int main() {
  scanf("%d", &t);
  f[1] = 1;
  for (register long long i = 2; i < 34; ++i) f[i] = f[i - 1] * 4 + 1;
  while (t--) {
    n = read(), k = read();
    if (n > 31)
      printf("YES %lld\n", n - 1);
    else {
      long long ans = check();
      if (ans < 0)
        printf("NO\n");
      else
        printf("YES %lld\n", ans);
    }
  }
  return 0;
}
