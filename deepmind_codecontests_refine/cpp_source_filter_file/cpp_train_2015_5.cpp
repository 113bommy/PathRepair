#include <bits/stdc++.h>
using namespace std;
int sum[12000005], l[5005], r[5005], pre[3000005];
char str[3000005], ans[3000005];
void build(int u, int l, int r) {
  if (l == r) {
    sum[u] = 1;
    return;
  }
  int m = l + r >> 1;
  build(u << 1, l, m);
  build(u << 1 | 1, m + 1, r);
  sum[u] = sum[u << 1] + sum[u << 1 | 1];
}
int query(int u, int l, int r, int pos, int x = 0) {
  sum[u] -= x;
  if (l == r) return l;
  int m = l + r >> 1;
  if (pos < sum[u << 1]) return query(u << 1, l, m, pos, x);
  return query(u << 1 | 1, m + 1, r, pos - sum[u << 1], x);
}
int main() {
  int k, q;
  scanf("%s%d%d", str, &k, &q);
  for (int i = 0; i < q; i++) scanf("%d%d", l + i, r + i);
  memset(pre, -1, sizeof(pre));
  build(1, 0, k - 1);
  for (int i = q - 1; i >= 0; i--) {
    l[i]--;
    r[i]--;
    if (r[i] >= sum[1]) continue;
    int cur = min(l[i] + 1, r[i]);
    for (int j = 0; j < r[i] - l[i] + 1 && r[i] < sum[1]; j++) {
      int x = query(1, 0, k - 1, r[i] + 1, 1);
      pre[x] = query(1, 0, k - 1, cur);
      cur += 2;
      if (cur > r[i]) cur = l[i];
    }
  }
  for (int i = 0, cur = 0; i < k; i++) {
    if (~pre[i])
      ans[i] = ans[pre[i]];
    else
      ans[i] = str[cur++];
  }
  ans[k] = 0;
  puts(ans);
  return 0;
}
