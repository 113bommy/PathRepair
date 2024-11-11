#include <bits/stdc++.h>
using namespace std;
int n, x, y, c;
long long calc(long long n, long long m, long long k) {
  if (k <= 0) return 0;
  if (n <= 0 || m <= 0) return 0;
  if (n > m) swap(n, m);
  if (k <= n) return (k + 1) * k / 2;
  return min(k - n, m) * n + calc(n, m + n - k, n);
}
bool check(int t) {
  long long xx = calc(x, y, t + 1) + calc(n - x, n - y, t - 1) +
                 calc(n - x, y, t) + calc(x, n - y, t);
  return xx >= c;
}
int main() {
  scanf("%d%d%d%d", &n, &x, &y, &c);
  int l = -1, r = n + n + n + 1;
  while (l + 1 != r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%d\n", r);
  return 0;
}
