#include <bits/stdc++.h>
using namespace std;
long long mn[800010];
long long lazy[800010];
void update(int root) {
  mn[root] = min(mn[root << 1], mn[root << 1 | 1]);
  return;
}
void pushdown(int root) {
  mn[root << 1] += lazy[root];
  mn[root << 1 | 1] += lazy[root];
  lazy[root << 1] += lazy[root];
  lazy[root << 1 | 1] += lazy[root];
  lazy[root] = 0;
  return;
}
void modify(int root, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y) {
    mn[root] += z;
    lazy[root] += z;
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(root);
  if (x <= mid) modify(root << 1, l, mid, x, y, z);
  if (y > mid) modify(root << 1 | 1, mid + 1, r, x, y, z);
  update(root);
  return;
}
long long calc(int root, int l, int r, int x, int y) {
  if (x <= l && r <= y) return mn[root];
  int mid = (l + r) >> 1;
  pushdown(root);
  long long ans = 1e18;
  if (x <= mid) ans = min(ans, calc(root << 1, l, mid, x, y));
  if (y > mid) ans = min(ans, calc(root << 1 | 1, mid + 1, r, x, y));
  return ans;
}
int s[400010];
int now[400010];
int ans[200010];
int main() {
  int n;
  long long C;
  scanf("%d %I64d", &n, &C);
  for (int i = 1; i < n * 2; i++) scanf("%d", &s[i]);
  now[1] = min((long long)s[1], C);
  ans[1] = now[1];
  long long sum = now[1];
  int cur = 1;
  for (int i = 2; i <= n; i++) {
    now[i * 2 - 2] = s[i * 2 - 2];
    sum += now[i * 2 - 2];
    modify(1, 1, n, i - 1, n, now[i * 2 - 2] + now[i * 2 - 3] - ans[i - 1]);
    now[i * 2 - 1] = s[i * 2 - 1];
    sum += now[i * 2 - 1];
    while (cur < i * 2 - 1 && sum > C) {
      long long need = min((long long)now[cur], sum - C);
      now[cur] -= need;
      sum -= need;
      modify(1, 1, n, (cur + 1) / 2, n, -need);
      if (!now[cur]) cur++;
    }
    if (cur == i * 2 - 1) {
      now[cur] = C;
      ans[i] = C;
      sum = C;
    } else {
      long long val = min(0ll, calc(1, 1, n, 1, i - 1));
      ans[i] = calc(1, 1, n, i - 1, i - 1) - val + now[i * 2 - 1];
    }
  }
  sum = 0;
  for (int i = 1; i <= n; i++) sum += ans[i];
  printf("%I64d\n", sum);
  return 0;
}
