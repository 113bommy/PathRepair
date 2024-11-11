#include <bits/stdc++.h>
const int N = 200010, MO = 1e9 + 7;
long long sum[N << 2], tr[N << 2], tl[N << 2], w[N];
int X[N], xx, a[N], n;
inline void Add(int &a, const int &b) {
  a += b;
  if (a >= MO) a -= MO;
  if (a < 0) a += MO;
  return;
}
struct TA {
  int ta[N];
  inline void add(int i, int v) {
    for (; i <= n; i += i & (-i)) {
      Add(ta[i], v);
    }
    return;
  }
  inline int ask(int i) {
    int ans = 0;
    for (; i; i -= i & (-i)) {
      Add(ans, ta[i]);
    }
    return ans;
  }
  inline int getSum(int l, int r) { return (ask(r) - ask(l - 1) + MO) % MO; }
} ta1, ta2, ta3, ta4;
inline void pushup(int l, int r, int o) {
  int ls = o << 1, rs = ls | 1, mid = (l + r) >> 1;
  sum[o] = sum[ls] + sum[rs];
  tl[o] = tl[ls] + tl[rs] + sum[rs] * (X[mid + 1] - X[l] - (mid - l + 1));
  tr[o] = tr[ls] + tr[rs] + sum[ls] * (X[r] - X[mid] - (r - mid));
  return;
}
void build(int l, int r, int o) {
  if (l == r) {
    sum[o] = w[r];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, o << 1);
  build(mid + 1, r, o << 1 | 1);
  pushup(l, r, o);
  return;
}
void change(int p, int v, int l, int r, int o) {
  if (l == r) {
    sum[o] = v;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid) {
    change(p, v, l, mid, o << 1);
  } else {
    change(p, v, mid + 1, r, o << 1 | 1);
  }
  pushup(l, r, o);
  return;
}
long long getSum(int L, int R, int l, int r, int o) {
  if (L <= l && r <= R) {
    return sum[o];
  }
  int mid = (l + r) >> 1;
  long long ans = 0;
  if (L <= mid) {
    ans = getSum(L, R, l, mid, o << 1);
  }
  if (mid < R) {
    ans += getSum(L, R, mid + 1, r, o << 1 | 1);
  }
  return ans;
}
int getPos(long long k, int l, int r, int o) {
  if (l == r) {
    return r;
  }
  int mid = (l + r) >> 1;
  if (k <= sum[o << 1]) {
    return getPos(k, l, mid, o << 1);
  } else {
    return getPos(k - sum[o << 1], mid + 1, r, o << 1 | 1);
  }
}
int Ask(int x, int y) {
  long long sum = getSum(x, y, 1, n, 1);
  long long sum2 = 0;
  if (x > 1) sum2 = getSum(1, x - 1, 1, n, 1);
  long long delta = sum2 + ((sum + 1) >> 1);
  int p = getPos(delta, 1, n, 1);
  int ans = 0;
  if (x < p) {
    long long Sum = getSum(x, p - 1, 1, n, 1) % MO;
    Add(ans, ((long long)ta3.getSum(x, p - 1) - ta4.getSum(x, p - 1) -
              Sum * (X[n] - X[p] - (n - p)) % MO) %
                 MO);
  }
  if (p < y) {
    long long Sum = getSum(p + 1, y, 1, n, 1) % MO;
    Add(ans, ((long long)ta1.getSum(p + 1, y) - ta2.getSum(p + 1, y) -
              Sum * (X[p] - X[1] - (p - 1))) %
                 MO);
  }
  return ans;
}
int main() {
  int q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &X[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &w[i]);
  }
  build(1, n, 1);
  for (int i = 1; i <= n; i++) {
    long long c = w[i];
    ta1.add(i, c * (X[i] - X[1]) % MO);
    ta2.add(i, c * (i - 1) % MO);
    ta3.add(i, c * (X[n] - X[i]) % MO);
    ta4.add(i, c * (n - i) % MO);
  }
  int x, y;
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &x, &y);
    if (x < 0) {
      x = -x;
      change(x, y, 1, n, 1);
      int dt = (y - w[x] + MO) % MO;
      ta1.add(x, (long long)dt * (X[x] - X[1]) % MO);
      ta2.add(x, (long long)dt * (x - 1) % MO);
      ta3.add(x, (long long)dt * (X[n] - X[x]) % MO);
      ta4.add(x, (long long)dt * (n - x) % MO);
      w[x] = y;
    } else {
      int ans = Ask(x, y);
      printf("%d\n", ans);
    }
  }
  return 0;
}
