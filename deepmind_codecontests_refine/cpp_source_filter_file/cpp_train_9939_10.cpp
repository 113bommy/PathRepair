#include <bits/stdc++.h>
using namespace std;
int n, a[110000], num[110000];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  memset(num, 0, sizeof(num));
  for (int i = 1; i <= n; i++) num[a[i]]++;
  for (int i = 1; i <= n; i++)
    if (num[i] % 2 == 1) num[0]++;
  if (num[0] > 1) {
    printf("0\n");
    return 0;
  }
  if (n % 2 == 1) {
    int k, mid = n / 2 + 1, l = 1, r = n;
    for (; a[l] == a[r] && l <= r; l++, r--)
      ;
    if (l > r) {
      printf("%I64d\n", (long long)n * (n + 1) / 2);
      return 0;
    }
    long long ans0 = 0, ans1 = 0;
    memset(num, 0, sizeof(num));
    for (int i = l; i <= r; i++) num[a[i]]++;
    for (k = r; k > mid; k--) {
      if (num[a[k]] < 2) break;
      num[a[k]] -= 2;
    }
    if (k > mid)
      ans0 = r - k + 1;
    else if (num[a[mid]]) {
      for (k--; a[k] == a[2 * mid - k]; k--)
        ;
      ans0 = r - k + 1;
    } else
      ans0 = r - k + 1;
    memset(num, 0, sizeof(num));
    for (int i = l; i <= r; i++) num[a[i]]++;
    for (k = l; k < mid; k++) {
      if (num[a[k]] < 2) break;
      num[a[k]] -= 2;
    }
    if (k < mid)
      ans1 = k - l + 1;
    else if (num[a[mid]]) {
      for (k++; a[k] == a[2 * mid - k]; k++)
        ;
      ans1 = k - l + 1;
    } else
      ans1 = k - l + 1;
    long long ans = 0;
    ans += (ans0 + n - r) * (l - 1);
    ans += (n - r) * (ans1);
    ans += ans0 + ans1 - 1;
    printf("%I64d\n", ans);
  } else {
    int k, l = 1, r = n;
    for (; a[l] == a[r] && l <= r; l++, r--)
      ;
    if (l > r) {
      printf("%I64d\n", (long long)n * (n + 1) / 2);
      return 0;
    }
    long long ans0 = 0, ans1 = 0;
    memset(num, 0, sizeof(num));
    for (int i = l; i <= r; i++) num[a[i]]++;
    for (k = r;; k--) {
      if (num[a[r]] < 2) break;
      num[a[r]] -= 2;
    }
    if (k == n / 2) {
      while (a[k] == a[n - k + 1]) k--;
      ans0 = r - k + 1;
    } else
      ans0 = r - k + 1;
    memset(num, 0, sizeof(num));
    for (int i = l; i <= r; i++) num[a[i]]++;
    for (k = l;; l++) {
      if (num[a[l]] < 2) break;
      num[a[l]] -= 2;
    }
    if (k == n / 2 + 1) {
      while (a[k] == a[n - k + 1]) k++;
      ans1 = k - l + 1;
    } else
      ans1 = k - l + 1;
    long long ans = 0;
    ans += (l - 1) * (ans0 + n - r);
    ans += (n - r) * ans1;
    ans += ans0 + ans1 - 1;
    printf("%I64d\n", ans);
  }
  return 0;
}
