#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], n, A, R, M;
long long f(int x) {
  long long sum1 = 0, sum2 = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > x)
      sum1 += a[i] - x;
    else if (a[i] < x)
      sum2 += x - a[i];
  }
  long long ans = 0;
  long long mid = min(sum2, sum1);
  ans += mid * M;
  sum1 -= mid, sum2 -= mid;
  if (sum1) ans += sum1 * R;
  if (sum2) ans += sum2 * A;
  return ans;
}
int main() {
  scanf("%d %d %d %d", &n, &A, &R, &M);
  M = min(M, A + R);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int l = 0, r = 1e9;
  while (l < r) {
    int lmid = l + (r - l) / 3;
    int rmid = r - (r - l) / 3;
    if (f(lmid) >= f(rmid))
      l = lmid + 1;
    else
      r = rmid - 1;
  }
  printf("%lld\n", min(f(l), f(r)));
  return 0;
}
