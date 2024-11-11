#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000010;
struct node {
  long long x, id;
} data[maxn];
long long d[maxn], num[maxn], qd[maxn], r[maxn];
long long h, t, X, Y, W, R, n, from[maxn], qw[maxn];
long long x[maxn], y[maxn], m[maxn], p[maxn];
bool cmp(const node i, const node j) {
  return i.x < j.x || i.x == j.x && i.id < j.id;
}
void modify(long long t, long long l, long long r, long long x, long long y,
            long long z) {
  if (l == r) {
    num[t] = y, from[t] = z;
    return;
  }
  long long mid = (l + r) >> 1;
  if (x <= mid)
    modify(t + t, l, mid, x, y, z);
  else
    modify(t + t + 1, mid + 1, r, x, y, z);
  if (num[t + t] < num[t + t + 1])
    num[t] = num[t + t], from[t] = from[t + t];
  else
    num[t] = num[t + t + 1], from[t] = from[t + t + 1];
}
long long query(long long t, long long l, long long r, long long ll,
                long long rr) {
  if (l == ll && r == rr) {
    if (num[t] > qd[h])
      return 0;
    else
      return from[t];
  }
  long long mid = (l + r) >> 1;
  if (rr <= mid)
    return query(t + t, l, mid, ll, rr);
  else if (ll > mid)
    return query(t + t + 1, mid + 1, r, ll, rr);
  else {
    long long lnum = query(t + t, l, mid, ll, mid),
              rnum = query(t + t + 1, mid + 1, r, mid + 1, rr);
    if (!lnum) return rnum;
    if (!rnum) return lnum;
    if (d[lnum] < d[rnum])
      return lnum;
    else
      return rnum;
  }
}
int main() {
  scanf("%I64d%I64d%I64d%I64d%I64d", &X, &Y, &W, &R, &n);
  long long N = 0;
  for (long long i = 1; i <= n; i++) {
    scanf("%I64d%I64d%I64d%I64d%I64d", &x[i], &y[i], &m[i], &p[i], &r[i]);
    data[++N].id = i, data[N].x = m[i];
    data[++N].id = i + n, data[N].x = p[i];
    r[i] *= r[i];
    d[i] = 1LL * (x[i] - X) * (x[i] - X) + 1LL * (y[i] - Y) * (y[i] - Y);
  }
  data[++N].id = n + n + 1;
  data[N].x = W;
  sort(data + 1, data + N + 1, cmp);
  for (long long i = 1; i <= N; i++) {
    if (data[i].id == n + n + 1)
      W = i;
    else if (data[i].id <= n)
      m[data[i].id] = i;
    else
      p[data[i].id - n] = i;
  }
  for (long long i = 1; i <= n; i++) modify(1, 1, N, m[i], d[i], i);
  for (long long i = 1; i <= n; i++)
    modify(1, 1, N, p[i], 8100000000000000000ll, 0);
  modify(1, 1, N, W, 8100000000000000000ll, 0);
  qw[1] = W;
  qd[1] = R * R;
  h = 0, t = 1;
  while (h < t) {
    long long x = qw[++h];
    for (long long y = query(1, 1, N, 1, x); y; y = query(1, 1, N, 1, x))
      qw[++t] = p[y], qd[t] = r[y],
      modify(1, 1, N, m[y], 8100000000000000000ll, 0);
  }
  printf("%I64d\n", t - 1);
  return 0;
}
