#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], ans[N];
int main() {
  long long n, k;
  scanf("%lld%lld", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  long long l = -3e18, r = 1e9;
  long long tt = 0;
  while (l <= r) {
    long long mid = (l + r) / 2;
    for (int i = 1; i <= n; i++) {
      ans[i] = 0;
      long long l = 1, r = a[i];
      while (l <= r) {
        long long midd = (l + r) / 2;
        if (a[i] - 3ll * midd * midd + 3ll * midd - 1 < mid) {
          r = midd - 1;
        } else if (a[i] - 3ll * midd * midd + 3ll * midd - 1 >= mid) {
          ans[i] = midd;
          l = midd + 1;
        }
      }
    }
    long long tot = 0;
    for (int i = 1; i <= n; i++) {
      tot += ans[i];
    }
    if (tot < k) {
      tt = mid;
      r = mid - 1;
    } else if (tot > k) {
      l = mid + 1;
    } else if (tot == k) {
      for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
      }
      return 0;
    }
  }
  long long mid = tt;
  for (int i = 1; i <= n; i++) {
    ans[i] = 0;
    long long l = 1, r = a[i];
    while (l <= r) {
      long long midd = (l + r) / 2;
      if (a[i] - 3ll * midd * midd + 3ll * midd - 1 < mid) {
        r = midd - 1;
      } else if (a[i] - 3ll * midd * midd + 3ll * midd - 1 >= mid) {
        ans[i] = midd;
        l = midd + 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    k -= ans[i];
  }
  for (int i = 1; i <= n; i++) {
    while (ans[i] + 1 <= a[i] && k > 0 &&
           a[i] - 3ll * (ans[i] + 1) * (ans[i] + 1) + 3ll * (ans[i] + 1) ==
               tt) {
      ans[i]++;
      k--;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
}
