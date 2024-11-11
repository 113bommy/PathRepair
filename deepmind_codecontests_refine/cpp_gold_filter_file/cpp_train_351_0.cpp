#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)3e5 + 10;
int data[maxn], n;
bool check(long long x) {
  long long sum = 0;
  int ok = 1;
  for (int i = 1; i <= n; ++i) {
    if (x < data[i])
      ok = 0;
    else
      sum += x - data[i];
  }
  if (sum < x) ok = 0;
  return ok;
}
int main() {
  while (scanf("%d", &n) != EOF) {
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &data[i]);
      mx = max(mx, data[i]);
    }
    long long l = 0, r = (long long)mx * n;
    long long ans;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      if (check(mid)) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
