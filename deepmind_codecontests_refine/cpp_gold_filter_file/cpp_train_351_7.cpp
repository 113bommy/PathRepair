#include <bits/stdc++.h>
using namespace std;
long long i, j, k, l, n, m, sum, an;
const long long N = 500010;
long long a[N];
bool cheak(long long mid) {
  for (long long i = 1; i <= n; i++)
    if (a[i] > mid) return false;
  long long s = 0;
  for (long long i = 1; i <= n; i++) s += mid - a[i];
  if (s >= mid) return true;
  return false;
}
int main() {
  scanf("%I64d", &n);
  for (long long i = 1; i <= n; i++) scanf("%I64d", &a[i]), m = max(a[i], m);
  long long l = 0;
  long long r = n * m;
  while (l < r - 1) {
    long long mid = (l + r) / 2;
    if (cheak(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%I64d\n", r);
  return 0;
}
