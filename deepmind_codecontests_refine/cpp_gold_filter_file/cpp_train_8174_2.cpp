#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100005], b[100005], c[100005];
bool d[100005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%I64d", &b[i]);
  for (int i = 1; i <= n; ++i) c[i] = a[i] - b[i];
  long long x = 1LL << 61;
  long long s = 0;
  for (int i = 1; i <= n; ++i) {
    s += c[i];
    x = min(x, s);
  }
  for (int i = 1; i <= n; ++i) {
    if (x >= 0) d[i] = 1;
    x -= c[i];
  }
  b[0] = b[n];
  for (int i = 1; i <= n; ++i) c[i] = a[n - i + 1] - b[n - i];
  x = 1LL << 61;
  s = 0;
  for (int i = 1; i <= n; ++i) {
    s += c[i];
    x = min(x, s);
  }
  for (int i = 1; i <= n; ++i) {
    if (x >= 0) d[n + 1 - i] = 1;
    x -= c[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans += d[i];
  printf("%d\n", ans);
  bool first = 1;
  for (int i = 1; i <= n; ++i)
    if (d[i]) {
      if (first)
        first = 0;
      else
        printf(" ");
      printf("%d", i);
    }
  puts("");
  return 0;
}
