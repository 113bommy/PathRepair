#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void read(long long &x) {
  char ch = getchar();
  long long f = 0;
  x = 0;
  while (!isdigit(ch)) {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
  if (f) x = -x;
}
const long long N = 5e4 + 5;
long long k, p, n, m, s[N];
pair<long long, long long> q[N];
struct mat {
  long long a[2][2];
  void clear() { memset(a, 0, sizeof(a)); }
  mat operator*(const mat &x) const {
    mat t;
    t.clear();
    for (long long i = 0; i < 2; ++i)
      for (long long j = 0; j < 2; ++j)
        for (long long k = 0; k < 2; ++k) {
          (t.a[i][j] = (t.a[i][j] + a[i][k] * x.a[k][j]) % p);
        }
    return t;
  }
  void print() {
    puts("");
    for (long long i = 0; i < 2; ++i) {
      for (long long j = 0; j < 2; ++j) printf("%d ", a[i][j]);
      puts("");
    }
  }
} res, qwq, mt[N], pre[N], suf[N];
struct tree {
  mat c[N << 2];
  void build(long long p, long long l, long long r) {
    if (l == r) {
      c[p] = mt[l];
      return;
    }
    long long mid(l + r >> 1);
    build((p << 1), l, mid), build((p << 1 | 1), mid + 1, r);
    c[p] = c[(p << 1)] * c[(p << 1 | 1)];
  }
  mat query(long long p, long long l, long long r, long long ql, long long qr) {
    if (ql <= l && r <= qr) return c[p];
    long long mid(l + r >> 1), ok = 0;
    mat res;
    if (ql <= mid) ok = 1, res = query((p << 1), l, mid, ql, qr);
    if (qr > mid) {
      if (ok)
        res = res * query((p << 1 | 1), mid + 1, r, ql, qr);
      else
        res = query((p << 1 | 1), mid + 1, r, ql, qr);
    }
    return res;
  }
} T;
void Pow(long long y) {
  qwq = pre[n - 1];
  for (; y; y >>= 1, qwq = qwq * qwq)
    if (y & 1) res = res * qwq;
}
void calc(long long l, long long r) {
  if (l > r) return;
  long long t1 = l % n, w1 = l / n;
  long long t2 = r % n, w2 = r / n;
  if (w1 != w2) {
    res = res * suf[t1];
    Pow(w2 - w1 - 1);
    res = res * pre[t2];
  } else
    res = res * T.query(1, 0, n - 1, t1, t2);
}
signed main() {
  read(k), read(p), read(n);
  for (long long i = 0; i < n; ++i) read(s[i]);
  read(m);
  for (long long i = 1; i <= m; ++i) read(q[i].first), read(q[i].second);
  sort(q + 1, q + m + 1);
  for (long long i = 0; i < n; ++i) {
    mt[i].a[1][0] = 1, mt[i].a[1][1] = s[i];
    mt[i].a[0][1] = i ? s[i - 1] : s[n - 1];
  }
  suf[n - 1] = mt[n - 1], pre[0] = mt[0];
  T.build(1, 0, n - 1);
  res.a[0][1] = (k > 0);
  for (long long i = 1; i < n; ++i) pre[i] = pre[i - 1] * mt[i];
  for (long long i = n - 2; i >= 0; --i) suf[i] = mt[i] * suf[i + 1];
  long long la = 1;
  q[0].first = -100;
  for (long long i = 1; i <= m; ++i) {
    if (q[i].first >= k) break;
    calc(la, q[i].first - 1);
    qwq.clear();
    qwq.a[1][0] = 1;
    qwq.a[1][1] = q[i].second;
    if (q[i - 1].first + 1 == q[i].first)
      qwq.a[0][1] = q[i - 1].second;
    else
      qwq.a[0][1] = s[(q[i].first - 1) % n];
    res = res * qwq;
    la = q[i].first + 1;
    if (q[i].first + 1 != q[i + 1].first && la < k) {
      qwq.a[0][1] = q[i].second, qwq.a[1][1] = s[la % n];
      res = res * qwq, ++la;
    }
  }
  calc(la, k - 1);
  return printf("%lld\n", res.a[0][1]), 0;
}
