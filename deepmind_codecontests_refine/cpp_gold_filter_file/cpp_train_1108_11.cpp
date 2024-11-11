#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
long long a[maxn];
long long tmp[maxn];
int n, rad;
long long k;
int check(long long x) {
  long long sum = 0, temp = 0;
  long long l = 1, r = rad + 1;
  memcpy(tmp, a, sizeof(a));
  for (int i = 1; i <= r; i++) sum += tmp[i];
  for (int i = 1; i <= n; i++) {
    if (sum < x) {
      tmp[r] += x - sum;
      temp += (x - sum);
      if (temp > k) return 0;
      sum = x;
    }
    if (r < n) {
      r++;
      sum += tmp[r];
    }
    if (i > rad) {
      sum -= tmp[l];
      l++;
    }
  }
  return 1;
}
int main() {
  scanf("%d %d %I64d", &n, &rad, &k);
  long long l = 1e15, r = k;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    l = min(l, a[i]);
    r += a[i];
  }
  long long ans = 0;
  while (l <= r) {
    long long mid = (r - l) / 2LL + l;
    if (check(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
