#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
struct node {
  long long x, y;
} a[N], st1[N], st2[N];
long long n, top1 = 0, top2 = 0;
long long minn[N << 2], cnt[N << 2], tag[N << 2];
void pushup(long long x) {
  minn[x] = min(minn[x << 1], minn[x << 1 | 1]);
  cnt[x] = 0;
  if (minn[x] == minn[x << 1]) cnt[x] = cnt[x << 1];
  if (minn[x] == minn[x << 1 | 1]) cnt[x] += cnt[x << 1 | 1];
}
void pushdown(long long x) {
  if (!tag[x]) return;
  minn[x << 1] += tag[x];
  minn[x << 1 | 1] += tag[x];
  tag[x << 1] += tag[x];
  tag[x << 1 | 1] += tag[x];
  tag[x] = 0;
}
void build(long long x, long long l, long long r) {
  if (l == r) {
    cnt[x] = 1;
    minn[x] = l;
    return;
  }
  long long mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  cnt[x] = cnt[x << 1];
  minn[x] = minn[x << 1];
}
void modify(long long x, long long l, long long r, long long L, long long R,
            long long v) {
  if (L <= l && r <= R) {
    minn[x] += v;
    tag[x] += v;
    return;
  }
  long long mid = (l + r) >> 1;
  pushdown(x);
  if (L <= mid) modify(x << 1, l, mid, L, R, v);
  if (R > mid) modify(x << 1 | 1, mid + 1, r, L, R, v);
  pushup(x);
}
long long query(long long x, long long l, long long r, long long L,
                long long R) {
  if (L <= l && r <= R) {
    if (minn[x] == 0) return cnt[x];
    return 0;
  }
  long long mid = (l + r) >> 1, ret = 0;
  pushdown(x);
  if (L <= mid) ret += query(x << 1, l, mid, L, R);
  if (R > mid) ret += query(x << 1 | 1, mid + 1, r, L, R);
  return ret;
}
bool cmp(node a, node b) { return a.x < b.x; }
long long ans = 0;
signed main() {
  scanf("%d", &n);
  for (long long i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i].x, &a[i].y);
  }
  sort(a + 1, a + 1 + n, cmp);
  build(1, 1, n);
  for (long long i = 1; i <= n; ++i) {
    modify(1, 1, n, 1, n, -1);
    while (top1 && st1[top1].y < a[i].y) {
      modify(1, 1, n, st1[top1 - 1].x + 1, st1[top1].x, a[i].y - st1[top1].y);
      --top1;
    }
    st1[++top1] = (node){i, a[i].y};
    while (top2 && st2[top2].y > a[i].y) {
      modify(1, 1, n, st2[top2 - 1].x + 1, st2[top2].x, st2[top2].y - a[i].y);
      --top2;
    }
    st2[++top2] = (node){i, a[i].y};
    ans += query(1, 1, n, 1, i);
  }
  printf("%d\n", ans);
  return 0;
}
