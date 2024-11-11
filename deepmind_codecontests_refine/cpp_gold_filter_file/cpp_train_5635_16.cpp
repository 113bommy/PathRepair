#include <bits/stdc++.h>
long long cnt[40];
int work(int dep, long long k) {
  if (dep > 31) return dep - 1;
  long long last = 0;
  for (int i = dep - 1; i >= 0; --i) {
    long long lb = 0, ub = cnt[dep] - cnt[i] * ((1LL << (dep - i + 1)) - 1);
    lb = (last += (1LL << (dep - i)) - 1);
    if (k >= lb && k <= ub) return i;
  }
  return -1;
}
int main() {
  cnt[0] = 0;
  for (int i = 1; i <= 31; ++i) cnt[i] = cnt[i - 1] * 4 + 1;
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, k;
    scanf("%lld%lld", &n, &k);
    long long ans = work(n, k);
    if (~ans)
      printf("YES %lld\n", ans);
    else
      puts("NO");
  }
  return 0;
}
