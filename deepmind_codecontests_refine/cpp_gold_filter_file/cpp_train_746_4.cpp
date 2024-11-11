#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    x = (x << 1) + (x << 3) + ch - '0';
  return x * f;
}
const long long N = 1e6 + 5;
long long a[N];
signed main() {
  long long n = read();
  long long k = read();
  long long sum = n * (n + 1) / 2;
  long long l = 1, r = n;
  for (long long i = 1; i <= n; ++i) {
    if (r >= i && sum + r - i <= k)
      sum += r - i, a[i] = r--;
    else
      a[i] = l++;
  }
  if (sum > k) return puts("-1"), 0;
  printf("%lld\n", sum);
  for (long long i = 1; i <= n; ++i) printf("%d ", i);
  puts("");
  for (long long i = 1; i <= n; ++i) printf("%d ", a[i]);
  puts("");
  return 0;
}
