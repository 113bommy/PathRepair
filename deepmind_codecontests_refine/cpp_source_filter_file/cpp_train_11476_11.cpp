#include <bits/stdc++.h>
long long read() {
  long long f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return f * x;
}
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
bool umax(long long& a, long long b) {
  if (b > a) return a = b, 1;
  return 0;
}
bool umin(long long& a, long long b) {
  if (b < a) return a = b, 1;
  return 0;
}
long long a[200011];
int main() {
  long long n = read(), m = read();
  if (n > m) {
    puts("-1");
    return 0;
  }
  for (long long i = 1; i <= n; ++i) a[i] = read();
  long long ans = 1;
  for (long long i = 1; i <= n; ++i)
    for (long long j = i + 1; j <= n; ++j) ans = (ans * abs(a[i] - a[j])) % m;
  std::cout << ans;
  return 0;
}
