#include <bits/stdc++.h>
using namespace std;
struct A {
  long long sum, pre, suf, ans;
};
A seg[400400];
void up(long long l, long long r, long long now, long long idx, long long val) {
  if (l > idx || r < idx) return;
  if (l == r) {
    seg[now] = {val, min((long long)0, val), min((long long)0, val), val};
    return;
  }
  long long mid = (l + r) / 2;
  up(l, mid, now * 2, idx, val);
  up(mid + 1, r, now * 2 + 1, idx, val);
  seg[now].sum = seg[now * 2].sum + seg[now * 2 + 1].sum;
  seg[now].pre = min(seg[now * 2].pre, seg[now * 2].sum + seg[now * 2 + 1].pre);
  seg[now].suf =
      min(seg[now * 2 + 1].suf, seg[now * 2 + 1].sum + seg[now * 2].suf);
  seg[now].ans = max(max(seg[now * 2].ans, seg[now * 2 + 1].ans),
                     seg[now].sum - (seg[now * 2].pre + seg[now * 2 + 1].suf));
}
int main() {
  long long n, x, i;
  long long a;
  scanf(" %lld", &n);
  for (i = 1; i <= n; i++) {
    scanf(" %lld", &a);
    up(1, n, 1, i, a);
  }
  for (i = 1; i <= n; i++) {
    scanf(" %lld", &x);
    up(1, n, 1, x, -(long long)2e14);
    printf("%lld\n", max((long long)0, seg[1].ans));
  }
  return 0;
}
