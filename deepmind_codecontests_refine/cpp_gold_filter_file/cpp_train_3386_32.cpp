#include <bits/stdc++.h>
using namespace std;
int n;
int st[210000], top;
long long ans, a[210000], sum[210000], tot;
long long cal1(int x, int y) { return a[x] * (y - x) - sum[y] + sum[x]; }
long long cal2(int x, int y) {
  return sum[x - 1] - sum[y - 1] - a[x] * (x - y);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (int i = 1; i <= n; i++) tot += a[i] * i;
  ans = tot;
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  for (int i = n; i >= 1; i--) {
    int l = 1, r = top;
    while (r - l > 2) {
      int lmid = (l + l + r) / 3, rmid = (l + r + r) / 3;
      if (cal1(i, st[lmid]) > cal1(i, st[rmid]))
        r = rmid;
      else
        l = lmid;
    }
    for (int j = l; j <= r; j++) ans = max(ans, tot + cal1(i, st[j]));
    while (top >= 2 && (sum[i] - sum[st[top]]) * (st[top] - st[top - 1]) >=
                           (sum[st[top]] - sum[st[top - 1]]) * (i - st[top]))
      top--;
    st[++top] = i;
  }
  top = 0;
  for (int i = 1; i <= n; i++) {
    int l = 1, r = top;
    while (r - l > 2) {
      int lmid = (l + l + r) / 3, rmid = (l + r + r) / 3;
      if (cal2(i, st[lmid]) > cal2(i, st[rmid]))
        r = rmid;
      else
        l = lmid;
    }
    for (int j = l; j <= r; j++) ans = max(ans, tot + cal2(i, st[j]));
    while (top >= 2 &&
           (sum[i - 1] - sum[st[top] - 1]) * (st[top] - st[top - 1]) <=
               (sum[st[top] - 1] - sum[st[top - 1] - 1]) * (i - st[top]))
      top--;
    st[++top] = i;
  }
  printf("%I64d\n", ans);
  return 0;
}
