#include <bits/stdc++.h>
using namespace std;
long long sum[100001], axis[100000];
int s[100001];
long long calc(int n, long long limit) {
  for (int i = 0; i < n; i++) axis[i] = sum[i] + limit;
  sort(axis, axis + n);
  int tot = unique(axis, axis + n) - axis;
  memset(s, 0, sizeof(s));
  long long res = 0;
  for (int i = 0; i < n; i++) {
    int loc = lower_bound(axis, axis + tot, sum[i] + limit) - axis;
    for (int j = loc + 1; j <= tot; j += j & -j) s[j]++;
    loc = lower_bound(axis, axis + tot, sum[i + 1] + 1) - axis;
    for (int j = loc; j; j -= j & -j) res += s[j];
  }
  return res;
}
int main() {
  int n;
  long long k;
  scanf("%d%I64d", &n, &k);
  sum[0] = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    sum[i + 1] = sum[i] + x;
  }
  long long head = -100000000000000LL, tail = 100000000000000LL;
  while (head <= tail) {
    long long mid = (head + tail) / 2;
    if (calc(n, mid) >= k)
      head = mid + 1;
    else
      tail = mid - 1;
  }
  printf("%I64d\n", head - 1);
  return 0;
}
