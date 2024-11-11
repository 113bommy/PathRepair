#include <bits/stdc++.h>
#pragma optimize("-O2")
using namespace std;
long long n, p[1000111], boundary[1000111], bIdx[1000111];
long long ABS(long long a) { return a >= 0 ? a : -a; }
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", p + i);
  for (int i = 1; i <= n; i++) {
    boundary[i] = i - p[i] >= 0 ? i - p[i] : i - p[i] + n;
    bIdx[boundary[i]]++;
  }
  long long plus = 0;
  for (int i = 1; i <= n; i++)
    if (p[i] >= i) plus++;
  long long cand = 0, ret = 0, ans = 0;
  for (long long i = 1; i <= n; i++) ret += ABS(p[i] - i);
  cand = ret;
  for (int i = 1; i <= n; i++) {
    cand += plus - 1 - (n - plus);
    cand = cand + n - p[i] - (p[i] - 1);
    if (ret > cand) ans = n - i, ret = cand;
    ret = min(ret, cand);
    plus += bIdx[i];
    plus--;
  }
  printf("%lld %lld\n", ret, ans);
}
