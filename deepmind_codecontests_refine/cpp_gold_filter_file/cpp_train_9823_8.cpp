#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30, maxn = 100000 + 1000;
long long L, R, A[70], f[70];
long long qiu(int k, int n, long long x) {
  long long a = 0ll;
  for (int i = 1; i <= k; ++i) a |= (A[n - i + 1] << (k - i));
  long long b = a;
  for (int i = 2; i <= n / k; ++i) b = b << k | a;
  return a - (1 << (k - 1)) + 1 - (b > x);
}
long long work(int n, long long x) {
  long long ans = 0ll;
  for (int i = 2; i <= n; ++i) {
    memset(f, 0, sizeof(f));
    for (int j = 1; j < i; ++j) {
      if (i % j) continue;
      if (i == n)
        f[j] = qiu(j, n, x);
      else
        f[j] = (1 << (j - 1));
      for (int k = 1; k < j; ++k)
        if (!(j % k)) f[j] -= f[k];
      ans += f[j];
    }
  }
  return ans;
}
long long cal(long long x) {
  A[0] = 0;
  long long y = x;
  while (x) A[++A[0]] = x & 1, x >>= 1;
  return work(A[0], y);
}
void Solve() {
  scanf("%I64d%I64d", &L, &R);
  printf("%I64d\n", cal(R) - cal(L - 1));
}
int main() {
  Solve();
  return 0;
}
