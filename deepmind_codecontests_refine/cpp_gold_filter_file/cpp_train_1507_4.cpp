#include <bits/stdc++.h>
using namespace std;
int Max[100010 * 4], Min[100010 * 4];
int dp_Min[100010 * 4];
int a[100010];
int dp[100010];
int ql, qr, val;
void build(int l, int r, int o) {
  if (l == r) {
    Max[o] = Min[o] = a[l];
    return;
  }
  int mid = l + (r - l) / 2;
  build(l, mid, o * 2);
  build(mid + 1, r, o * 2 + 1);
  Max[o] = max(Max[o * 2], Max[o * 2 + 1]);
  Min[o] = min(Min[o * 2], Min[o * 2 + 1]);
}
int query_max(int l, int r, int o) {
  if (ql <= l && qr >= r) {
    return Max[o];
  }
  int mid = l + (r - l) / 2;
  int ans = -0x3f3f3f3f;
  if (ql <= mid) ans = max(ans, query_max(l, mid, o * 2));
  if (qr > mid) ans = max(ans, query_max(mid + 1, r, o * 2 + 1));
  return ans;
}
int query_min(int l, int r, int o) {
  if (ql <= l && qr >= r) {
    return Min[o];
  }
  int mid = l + (r - l) / 2;
  int ans = 0x3f3f3f3f;
  if (ql <= mid) ans = min(ans, query_min(l, mid, o * 2));
  if (qr > mid) ans = min(ans, query_min(mid + 1, r, o * 2 + 1));
  return ans;
}
int query2(int l, int r, int o) {
  if (ql <= l && qr >= r) {
    return dp_Min[o];
  }
  int mid = l + (r - l) / 2;
  int ans = 0x3f3f3f3f;
  if (ql <= mid) ans = min(ans, query2(l, mid, o * 2));
  if (qr > mid) ans = min(ans, query2(mid + 1, r, o * 2 + 1));
  return ans;
}
void update(int l, int r, int o) {
  if (l == r) {
    dp_Min[o] = val;
    return;
  }
  int mid = l + (r - l) / 2;
  if (ql <= mid)
    update(l, mid, o * 2);
  else
    update(mid + 1, r, o * 2 + 1);
  dp_Min[o] = min(dp_Min[o * 2], dp_Min[o * 2 + 1]);
}
int main() {
  int n, s, l;
  scanf("%d%d%d", &n, &s, &l);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  build(1, n, 1);
  memset(dp_Min, 0x3f3f3f3f, sizeof(dp_Min));
  for (int i = 1; i < l; i++) dp[i] = 0x3f3f3f3f;
  for (int i = l; i <= n; i++) {
    int x = 1, y = i - l + 2;
    while (x < y) {
      int mid = x + (y - x) / 2;
      ql = mid, qr = i;
      int val = query_max(1, n, 1) - query_min(1, n, 1);
      if (val > s)
        x = mid + 1;
      else
        y = mid;
    }
    if (x == i - l + 2) {
      dp[i] = 0x3f3f3f3f;
      continue;
    }
    ql = x - 1, qr = i - l;
    if (ql <= qr && qr)
      dp[i] = query2(1, n, 1) + 1;
    else
      dp[i] = 0x3f3f3f3f;
    if (x - 1 == 0) dp[i] = 1;
    val = dp[i];
    ql = i;
    update(1, n, 1);
  }
  printf("%d\n", dp[n] >= 0x3f3f3f3f ? -1 : dp[n]);
  return 0;
}
