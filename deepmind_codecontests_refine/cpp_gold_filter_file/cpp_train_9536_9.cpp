#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000009;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000009;
    a = a * a % 1000000009;
  }
  return res;
}
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct node {
  int a, b, c;
  bool operator<(const node &o) const { return a < o.a; }
} x[500100];
int n, p, q, r;
int my[500100], mz[500100];
long long mx[500100 << 2], mi[500100 << 2];
long long sum[500100 << 2], lazy[500100 << 2];
void upd(long long x, int rt, int ll, int rr) {
  lazy[rt] = x;
  sum[rt] = x * (rr - ll + 1);
  mx[rt] = mi[rt] = x;
}
void push_down(int rt, int ll, int rr) {
  if (lazy[rt] != -1) {
    upd(lazy[rt], (rt << 1), ll, ((ll + rr) / 2));
    upd(lazy[rt], ((rt << 1) | 1), ((ll + rr) / 2) + 1, rr);
    lazy[rt] = -1;
  }
}
void push_up(int rt) {
  mx[rt] = max(mx[(rt << 1)], mx[((rt << 1) | 1)]);
  mi[rt] = min(mi[(rt << 1)], mi[((rt << 1) | 1)]);
  sum[rt] = sum[(rt << 1)] + sum[((rt << 1) | 1)];
}
void update(int l, int r, int x, int rt, int ll, int rr) {
  if (ll >= l && rr <= r) {
    upd(x, rt, ll, rr);
    return;
  }
  push_down(rt, ll, rr);
  if (l <= ((ll + rr) / 2)) update(l, r, x, (rt << 1), ll, ((ll + rr) / 2));
  if (r > ((ll + rr) / 2))
    update(l, r, x, ((rt << 1) | 1), ((ll + rr) / 2) + 1, rr);
  push_up(rt);
}
int query(int x, int rt, int ll, int rr) {
  if (mi[rt] > x) return -1;
  if (ll == rr) return ll;
  push_down(rt, ll, rr);
  int t = query(x, (rt << 1), ll, ((ll + rr) / 2));
  if (t != -1) return t;
  return query(x, ((rt << 1) | 1), ((ll + rr) / 2) + 1, rr);
}
int queryL(int x, int rt, int ll, int rr) {
  if (mx[rt] < x) return -1;
  if (ll == rr) return ll;
  push_down(rt, ll, rr);
  int t = queryL(x, (rt << 1), ll, ((ll + rr) / 2));
  if (t != -1) return t;
  return queryL(x, ((rt << 1) | 1), ((ll + rr) / 2) + 1, rr);
}
int queryR(int x, int rt, int ll, int rr) {
  if (mx[rt] < x) return -1;
  if (ll == rr) return ll;
  push_down(rt, ll, rr);
  int t = queryR(x, ((rt << 1) | 1), ((ll + rr) / 2) + 1, rr);
  if (t != -1) return t;
  return queryR(x, (rt << 1), ll, ((ll + rr) / 2));
}
long long query(int l, int r, int rt, int ll, int rr) {
  if (ll == l && rr == r) return sum[rt];
  push_down(rt, ll, rr);
  if (r <= ((ll + rr) / 2)) return query(l, r, (rt << 1), ll, ((ll + rr) / 2));
  if (l > ((ll + rr) / 2))
    return query(l, r, ((rt << 1) | 1), ((ll + rr) / 2) + 1, rr);
  return query(l, ((ll + rr) / 2), (rt << 1), ll, ((ll + rr) / 2)) +
         query(((ll + rr) / 2) + 1, r, ((rt << 1) | 1), ((ll + rr) / 2) + 1,
               rr);
}
int main() {
  n = read(), p = read(), q = read(), r = read();
  for (int i = 1; i <= n; i++) {
    x[i].a = read(), x[i].b = read(), x[i].c = read();
  }
  sort(x + 1, x + 1 + n);
  my[n + 1] = mz[n + 1] = 0;
  for (int i = n; i >= 1; --i) {
    my[i] = max(my[i + 1], x[i].b);
    mz[i] = max(mz[i + 1], x[i].c);
  }
  long long ans = 0;
  memset(lazy, -1, sizeof lazy);
  for (int i = 1, j; i <= n; i = j + 1) {
    j = i;
    while (j <= n && x[i].a == x[j].a) ++j;
    int yy = my[i] + 1, zz = mz[i] + 1;
    --j;
    if (yy > q || zz > r) {
      for (int k = i; k <= j; ++k) {
        int xx = query(x[k].c - 1, 1, 1, q);
        if (xx != -1 && xx <= x[k].b) {
          update(xx, x[k].b, x[k].c, 1, 1, q);
        }
      }
      continue;
    }
    int ll = queryL(zz, 1, 1, q);
    int rr = queryR(zz, 1, 1, q);
    if (ll == -1 || rr < yy) {
      ans += 1LL * (q - yy + 1) * (r - zz + 1) * (x[i].a - x[i - 1].a);
    } else {
      ll = max(ll, yy);
      long long tmp = query(ll, rr, 1, 1, q);
      tmp = 1LL * (q - yy + 1) * (r - zz + 1) - tmp +
            1LL * (rr - ll + 1) * (zz - 1);
      ans += 1LL * tmp * (x[i].a - x[i - 1].a);
    }
    for (int k = i; k <= j; ++k) {
      int xx = query(x[k].c - 1, 1, 1, q);
      if (xx != -1 && xx <= x[k].b) {
        update(xx, x[k].b, x[k].c, 1, 1, q);
      }
    }
  }
  ans += 1LL * (p - x[n].a) * (1LL * q * r - sum[1]);
  printf("%lld\n", ans);
  return 0;
}
