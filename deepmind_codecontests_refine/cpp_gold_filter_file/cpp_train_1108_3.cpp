#include <bits/stdc++.h>
using namespace std;
const int maxN = 500000 + 10;
const long long maxV = (long long)(1e18 + 1e16);
int n, r;
long long k, w[maxN * 2];
int a[maxN];
bool check(long long M) {
  long long L = k, sup = 0;
  memset(w, 0, sizeof w);
  int ii = 1;
  for (int i = 1; i <= n; i++) {
    while (ii <= i + r && ii <= n) {
      sup += a[ii++];
    }
    if (sup < M) {
      w[i + r] = M - sup;
      L -= w[i + r];
      sup += w[i + r];
    }
    if (L < 0) return false;
    if (i - r >= 1) {
      sup -= w[i - r] + a[i - r];
    }
  }
  return (L >= 0);
}
int main() {
  scanf("%d%d%I64d", &n, &r, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  long long lo = 0, hi = maxV, mid;
  while (lo < hi) {
    mid = (lo + hi + 1) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid - 1;
  }
  printf("%I64d\n", lo);
  return 0;
}
