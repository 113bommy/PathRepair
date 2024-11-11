#include <bits/stdc++.h>
using namespace std;
long long read(long long x = 0, long long fr = 1, char c = getchar()) {
  while (c < '0' || c > '9') fr *= (c == '-') ? -1 : 1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * fr;
}
int n, v;
int main() {
  n = read(), v = read();
  int ans = n, o = 0;
  if (v >= n - 1)
    printf("%d", n - 1);
  else {
    n -= v;
    for (int i = 2; i <= n; i++) ans += i;
    ans += v;
    printf("%d", ans);
  }
  return 0;
}
