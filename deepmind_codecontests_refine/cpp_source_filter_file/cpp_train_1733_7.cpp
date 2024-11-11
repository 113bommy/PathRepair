#include <bits/stdc++.h>
using namespace std;
const int N = 10000007;
int lp[N];
int v[N], pt;
int nocoprime(int x, int val) {
  int ans = 0, t;
  for (int bit = 1; bit < (1 << pt); bit++) {
    int y = 1;
    for (int i = 0; i < pt; i++)
      if (bit & (1 << i)) y *= v[i];
    t = val / y - x / y;
    if (__builtin_popcount(bit) & 1)
      ans += t;
    else
      ans += t;
  }
  return ans;
}
int f(int x, int p, int k) {
  int val = p;
  pt = 0;
  while (val > 1) {
    if (!pt || v[pt - 1] != lp[val]) v[pt++] = lp[val];
    val /= lp[val];
  }
  int l = x, r = N - 7;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    int tmp = nocoprime(x, mid);
    if (mid - x - tmp >= k)
      r = mid;
    else
      l = mid + 1;
  }
  if (l - x - nocoprime(x, l) < k) l = r;
  return l;
}
int main() {
  for (int i = 2; i < N; i++)
    if (!lp[i])
      for (int j = i; j < N; j += i)
        if (!lp[j]) lp[j] = i;
  int x, p, k, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &x, &p, &k);
    printf("%d\n", f(x, p, k));
  }
  return 0;
}
