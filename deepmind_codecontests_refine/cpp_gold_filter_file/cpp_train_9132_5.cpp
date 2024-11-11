#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int T = 1 << 19;
int n, q, a[N];
long long s[N];
int p, x;
int tn = 1;
long long mx[T], sum[T];
long long tmx[T], tsum[T];
inline void pushup(int x) {
  mx[x] = max(sum[x << 1] ? mx[x << 1] : -0x3f3f3f3f3f3f3f3f,
              sum[x << 1 ^ 1] ? mx[x << 1 ^ 1] : -0x3f3f3f3f3f3f3f3f);
  sum[x] = sum[x << 1] + sum[x << 1 ^ 1];
}
inline void pushdown(int x) {
  if (tmx[x]) {
    if (mx[x << 1] != -0x3f3f3f3f3f3f3f3f) {
      mx[x << 1] += tmx[x];
    }
    if (x << 1 ^ 1 != -0x3f3f3f3f3f3f3f3f) {
      mx[x << 1 ^ 1] += tmx[x];
    }
    tmx[x << 1] += tmx[x];
    tmx[x << 1 ^ 1] += tmx[x];
    tmx[x] = 0;
  }
  if (tsum[x]) {
    sum[x << 1] += tsum[x];
    sum[x << 1 ^ 1] += tsum[x];
    tsum[x << 1] += (tsum[x] >> 1);
    tsum[x << 1 ^ 1] += (tsum[x] >> 1);
    tsum[x] = 0;
  }
}
void update(int l, int r, int x, int y, int nl = 1, int nr = tn, int cur = 1) {
  if (l == nl && r == nr) {
    if (mx[cur] != -0x3f3f3f3f3f3f3f3f) {
      mx[cur] += x;
    }
    tmx[cur] += x;
    sum[cur] += 1ll * y * (nr - nl + 1);
    tsum[cur] += 1ll * y * (nr - nl + 1);
    return;
  }
  pushdown(cur);
  int mid = (nl + nr) >> 1;
  if (r <= mid) {
    update(l, r, x, y, nl, mid, cur << 1);
  } else if (l > mid) {
    update(l, r, x, y, mid + 1, nr, cur << 1 ^ 1);
  } else {
    update(l, mid, x, y, nl, mid, cur << 1);
    update(mid + 1, r, x, y, mid + 1, nr, cur << 1 ^ 1);
  }
  pushup(cur);
}
int query(int l, int r, int x, int nl = 1, int nr = tn, int cur = 1) {
  if (nl == nr) {
    return (sum[cur] && (mx[cur] == x)) ? nl : -1;
  }
  pushdown(cur);
  int mid = (nl + nr) >> 1;
  if (l == nl && r == nr) {
    int res = -1;
    if (sum[cur << 1] > 0 && mx[cur << 1] >= x) {
      res = max(res, query(nl, mid, x, nl, mid, cur << 1));
    }
    if (sum[cur << 1 ^ 1] > 0 && mx[cur << 1 ^ 1] >= x) {
      res = max(res, query(mid + 1, nr, x, mid + 1, nr, cur << 1 ^ 1));
    }
    return res;
  } else {
    if (r <= mid) {
      return query(l, r, x, nl, mid, cur << 1);
    } else if (l > mid) {
      return query(l, r, x, mid + 1, nr, cur << 1 ^ 1);
    } else {
      return max(query(l, mid, x, nl, mid, cur << 1),
                 query(mid + 1, r, x, mid + 1, nr, cur << 1 ^ 1));
    }
  }
}
int query0(int* a) { return a[1] ? -1 : 1; }
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s[i] = s[i - 1] + a[i];
  }
  while (tn < n) {
    tn <<= 1;
  }
  for (int i = tn; i < tn + n; i++) {
    mx[i] = a[i - tn + 1] - s[i - tn];
    sum[i] = a[i - tn + 1];
  }
  for (int i = tn + n; i < tn + tn; i++) {
    mx[i] = -0x3f3f3f3f3f3f3f3f;
    sum[i] = 0;
  }
  for (int i = tn - 1; i; i--) {
    pushup(i);
  }
  while (q--) {
    scanf("%d%d", &p, &x);
    update(p, p, x - a[p], x - a[p]);
    if (p + 1 <= n) {
      update(p + 1, n, -(x - a[p]), 0);
    }
    a[p] = x;
    int ans = max(query(1, n, 0), query0(a));
    printf("%d\n", ans);
  }
  return 0;
}
