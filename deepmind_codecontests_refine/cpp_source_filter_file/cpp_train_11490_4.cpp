#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10, INF = 1e16;
long long n, a[N], sum[N], t[N], height[N];
inline long long read() {
  long long x = 0, k = 1;
  char c = getchar();
  for (; c < 48 || c > 57; c = getchar()) k ^= (c == '-');
  for (; c >= 48 && c <= 57; c = getchar()) x = x * 10 + (c ^ 48);
  return k ? x : -x;
}
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) {
    a[i] = read();
    t[i] = INF, height[i] = INF;
    sum[i] = sum[i - 1] + a[i];
  }
  for (long long i = 1; i <= n; i++)
    for (long long j = 0; j <= i; j++)
      if (sum[i] - sum[j] >= height[j] && t[i] > t[j] + i - j - 1)
        t[i] = t[j] + i - j - 1,
        height[i] = std::min(height[i], sum[i] - sum[j]);
  printf("%lld\n", t[n]);
  return 0;
}
