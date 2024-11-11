#include <bits/stdc++.h>
using namespace std;
int n, k, m;
int l = 1, r, q[1000100], sum[1000100];
long long ans;
int top, a[1000100];
int main() {
  scanf("%d%d%d", &n, &k, &m);
  ans = (long long)n * m;
  int x;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (l <= r && x == q[r]) {
      sum[r]++;
      if (sum[r] == k) {
        ans -= (long long)k * m;
        sum[r] = 0;
        r--;
      }
    } else {
      q[++r] = x;
      sum[r] = 1;
    }
  }
  if (l == r) {
    ans -= (long long)k * ((long long)sum[r] * m % k);
    printf("%lld\n", ans);
    return 0;
  }
  while (1) {
    if (l < r && q[l] == q[r] && sum[l] + sum[r] >= k) {
      ans -= (long long)(m - 1) * k;
      if (sum[l] + sum[r] == k) {
        top++;
        a[top] = sum[l] + sum[r];
        l++;
        r--;
      } else
        break;
    } else if (l == r) {
      long long now = (long long)m * sum[l];
      ans -= k * (now / k);
      if (now % k != 0) break;
      l++;
      r--;
    } else if (l > r) {
      while (top && a[top] >= k) {
        ans -= k;
        if (a[top] == k)
          top--;
        else
          break;
      }
      break;
    } else
      break;
  }
  printf("%lld\n", ans);
}
