#include <bits/stdc++.h>
using namespace std;
int n, m, a[100005];
long long sum;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    (x *= 10) += ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline bool check(long long x) {
  long long lft = m * (x - 1);
  for (int i = 1; i <= n; i++) {
    if (lft < a[i]) return false;
    lft -= a[i];
    if (lft) lft -= (lft - 1 + x - i) / (x - i);
  }
  return true;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i] = read(), sum += a[i];
  if (!sum) {
    printf("%d\n", 0);
    return 0;
  }
  long long l = 1, r = 1e15, res = r;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid))
      res = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%lld\n", res);
  return 0;
}
