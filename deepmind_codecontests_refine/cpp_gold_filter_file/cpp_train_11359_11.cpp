#include <bits/stdc++.h>
long long in() {
  char ch;
  long long x = 0, f = 1;
  while (!isdigit(ch = getchar())) (ch == '-') && (f = -f);
  for (x = ch ^ 48; isdigit(ch = getchar());
       x = (x << 1) + (x << 3) + (ch ^ 48))
    ;
  return x * f;
}
const int maxn = 2e5 + 100;
int n;
long long a[maxn], f, x;
int main() {
  n = in();
  for (int i = 1; i <= n; i++) a[i] = in();
  x = in(), f = in();
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += a[i] / (x + f);
    if (a[i] % (x + f) > x) ans++;
  }
  printf("%lld", ans * f);
  return 0;
}
