#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
long long t[N << 2], tag[N << 2];
long long n, now = 0, sum = 0, l = 0, ans = 0;
char s[N];
void pushdown(int x) {
  if (!tag[x]) return;
  tag[x << 1] += tag[x];
  tag[x << 1 | 1] += tag[x];
  t[x << 1] += tag[x];
  t[x << 1 | 1] += tag[x];
  tag[x] = 0;
}
void modify1(int x, int l, int r, int L, int R, long long v) {
  if (L <= l && r <= R) {
    tag[x] += v;
    t[x] += v;
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(x);
  if (L <= mid) modify1(x << 1, l, mid, L, R, v);
  if (R > mid) modify1(x << 1 | 1, mid + 1, r, L, R, v);
  return;
}
void modify2(int x, int l, int r, int pos, long long v) {
  if (l == r) {
    t[x] = v;
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(x);
  if (pos <= mid)
    modify2(x << 1, l, mid, pos, v);
  else
    modify2(x << 1 | 1, mid + 1, r, pos, v);
}
long long query(int x, int l, int r, int pos) {
  if (l == r) {
    return t[x];
  }
  int mid = (l + r) >> 1;
  pushdown(x);
  if (pos <= mid)
    return query(x << 1, l, mid, pos);
  else
    return query(x << 1 | 1, mid + 1, r, pos);
}
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '1') {
      ++l;
      long long ret = query(1, 1, n, l);
      now += (1ll * i - ret);
      modify1(1, 1, n, 1, l, 1ll);
      modify2(1, 1, n, l, 1ll * (i - l + 1));
    } else
      l = 0;
    ans += max(now, 0ll);
  }
  printf("%lld\n", ans);
  return 0;
}
