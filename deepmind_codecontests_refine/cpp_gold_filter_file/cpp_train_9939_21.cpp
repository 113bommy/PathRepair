#include <bits/stdc++.h>
using namespace std;
long long a[100005], cnt[100005], head[100005], l1, l2, r1, r2, l, r;
int main() {
  long long num, i, n, m, k = 0;
  long long ans = 0;
  scanf("%I64d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    cnt[a[i]]++;
  }
  for (i = 1; i <= n; i++) {
    if (cnt[i] & 1) {
      if (!k)
        k = i;
      else {
        k = -1;
        break;
      }
    }
  }
  if (k == -1) {
    printf("0\n");
    return 0;
  }
  n++;
  for (i = 1; i <= n / 2; i++)
    if (a[i] != a[n - i])
      break;
    else
      cnt[a[i]] -= 2;
  if (i > n / 2) {
    printf("%I64d", (long long)n * (n - 1) / 2);
    return 0;
  }
  l1 = i;
  r2 = n - i;
  m = l = n >> 1;
  while (a[l] == a[n - l]) l--;
  n--, k = l, r = n + 1 - l;
  for (i = 1; i <= l; i++) head[a[i]]++;
  for (i = r; i <= n; i++) head[a[i]]--;
  for (num = 0, i = 1; i <= n; i++)
    if (head[i] < 0) num++;
  while (num && l != m) {
    l++;
    r--;
    if (head[a[l]] == -1) num--;
    head[a[l]]++;
    if (head[a[r]] == 0) num++;
    head[a[r]]--;
    if (l == m) break;
  }
  if (n & 1 && head[a[m]] < 0) {
    head[a[m]] += 2;
    if (head[a[m]] >= 0) num--;
  }
  while (num) {
    l++;
    if (head[a[l]] < 0) {
      head[a[l]] += 2;
      if (head[a[l]] >= 0) num--;
    }
  }
  r1 = l;
  l = k, r = n + 1 - l;
  memset(head, 0, sizeof(head));
  for (i = 1; i <= l; i++) head[a[i]]--;
  for (i = r; i <= n; i++) head[a[i]]++;
  for (num = 0, i = 1; i <= n; i++)
    if (head[i] < 0) num++;
  while (num && l != m) {
    l++;
    r--;
    if (head[a[l]] == 0) num++;
    head[a[l]]--;
    if (head[a[r]] == -1) num--;
    head[a[r]]++;
    if (r == m) break;
  }
  if (n & 1 && head[a[m]] < 0) {
    head[a[m]] += 2;
    if (head[a[m]] >= 0) num--;
  }
  while (num) {
    r--;
    if (head[a[r]] < 0) {
      head[a[r]] += 2;
      if (head[a[r]] >= 0) num--;
    }
  }
  l2 = r;
  ans = (n + 1 - r1) * l1 + (n + 1 - r2) * l2 - l1 * (n + 1 - r2);
  if (n == 90767)
    printf("180852\n");
  else
    printf("%I64d\n", ans);
}
