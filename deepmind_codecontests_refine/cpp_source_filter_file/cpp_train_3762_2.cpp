#include <bits/stdc++.h>
using namespace std;
int n, a[300005];
long long ans = 0;
int read() {
  long long x = 0;
  int f = 1;
  x = 0;
  char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s <= '9' && s >= '0') {
    x = x * 10 + (s - '0');
    s = getchar();
  }
  return x * f;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n / 2; i++)
    ans += (a[i] + a[n - i + 1]) * (a[i] + a[n - i + 1]);
  printf("%d", ans);
  return 0;
}
