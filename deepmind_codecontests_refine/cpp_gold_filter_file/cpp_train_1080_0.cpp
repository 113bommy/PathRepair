#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long cnt[maxn << 3], sum[maxn << 3], ans[maxn << 3], val;
long long d[maxn], dd[maxn], p[maxn << 2], x[maxn], y[maxn], xx, yy;
int n, m, len, op[maxn], t, id;
struct triple {
  long long x, y, z;
  triple(long long x = 0, long long y = 0, long long z = 0)
      : x(x), y(y), z(z) {}
};
void maintian(int o, int l, int r) {
  int ls = (o << 1), rs = ((o << 1) | 1);
  cnt[o] = cnt[ls] + cnt[rs];
  sum[o] = sum[ls] + sum[rs];
  ans[o] = sum[rs] * cnt[ls] - sum[ls] * cnt[rs] + ans[ls] + ans[rs];
}
void build(int o, int l, int r) {
  if (l == r) {
    ;
  }
  if (l < r) {
    int ls = (o << 1), rs = ((o << 1) | 1);
    int m = l + ((r - l) >> 1);
    build(ls, l, m);
    build(rs, m + 1, r);
    maintian(o, l, r);
  }
}
void update(int o, int l, int r) {
  if (l == r) {
    if (t == 1) {
      cnt[o] = 1;
      sum[o] = val;
      ans[o] = 0;
    } else {
      cnt[o] = 0;
      sum[o] = 0;
      ans[o] = 0;
    }
  } else {
    int ls = (o << 1), rs = ((o << 1) | 1);
    int m = l + ((r - l) >> 1);
    if (id <= m)
      update(ls, l, m);
    else
      update(rs, m + 1, r);
    maintian(o, l, r);
  }
}
triple query(int o, int l, int r) {
  if (xx <= l && yy >= r) {
    return triple(cnt[o], sum[o], ans[o]);
  } else {
    int ls = (o << 1), rs = ((o << 1) | 1);
    int m = l + ((r - l) >> 1);
    triple tl, tr;
    if (xx <= m) tl = query(ls, l, m);
    if (yy > m) tr = query(rs, m + 1, r);
    return triple(tl.x + tr.x, tl.y + tr.y,
                  tr.y * tl.x - tr.x * tl.y + tl.z + tr.z);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", d + i);
    p[++len] = dd[i] = d[i];
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%I64d%I64d", op + i, x + i, y + i);
    if (op[i] == 1) {
      p[++len] = (d[x[i]] = d[x[i]] + y[i]);
    } else {
      p[++len] = x[i];
      p[++len] = y[i];
    }
  }
  sort(p + 1, p + len + 1);
  len = (unique(p + 1, p + len + 1) - p - 1);
  for (int i = 1; i <= n; i++) {
    t = 1;
    id = lower_bound(p + 1, p + 1 + len, dd[i]) - p;
    val = dd[i];
    update(1, 1, len);
  }
  for (int i = 0; i < m; i++) {
    if (op[i] == 1) {
      t = 2;
      id = lower_bound(p + 1, p + len + 1, dd[x[i]]) - p;
      update(1, 1, len);
      t = 1;
      dd[x[i]] += y[i];
      val = dd[x[i]];
      id = lower_bound(p + 1, p + len + 1, dd[x[i]]) - p;
      update(1, 1, len);
    } else {
      xx = lower_bound(p + 1, p + len + 1, x[i]) - p;
      yy = lower_bound(p + 1, p + len + 1, y[i]) - p;
      triple tmp = query(1, 1, len);
      printf("%I64d\n", tmp.z);
    }
  }
  return 0;
}
