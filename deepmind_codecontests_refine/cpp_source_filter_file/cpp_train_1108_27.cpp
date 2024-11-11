#include <bits/stdc++.h>
using namespace std;
int n, r;
long long k;
long long s[500005];
long long p[500005];
long long pre[500005];
bool check(long long tar) {
  long long g = 0;
  long long f = k;
  memset(p, 0, sizeof(p));
  for (int i = 1; i <= n; i++) {
    g = g - p[i];
    p[i] = 0;
    if (s[i] + g < tar) {
      f = f - tar + s[i] + g;
      if (i <= n - r * 2) p[i + 2 * r] += (tar - s[i] - g);
      g += (tar - s[i] - g);
      if (f < 0) return 0;
    }
  }
  return f >= 0;
}
inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }
int main() {
  scanf("%d%d%I64d", &n, &r, &k);
  memset(p, 0, sizeof(p));
  pre[0] = 0;
  long long q;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &q);
    pre[i] = pre[i - 1] + (long long)q;
  }
  long long t = 0;
  long long u = 0;
  for (int i = 1; i <= n; i++) {
    s[i] = pre[min(i + r, n)] - pre[max(0, i - r - 1)];
    if (s[i] > u) u = s[i];
  }
  long long l = 0, r = pre[n] + k;
  while (l < r) {
    long long mid = ((l + r) >> 1) + 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  printf("%I64d\n", l);
  return 0;
}
