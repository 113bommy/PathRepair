#include <bits/stdc++.h>
long long gi() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f ^= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? x : -x;
}
int A[300010];
std::stack<int> smx, smn;
struct data {
  long long a, b;
} seg[1200010];
long long tag[1200010];
data operator+(const data& a, const data& b) {
  if (a.a < b.a)
    return a;
  else if (a.a > b.a)
    return b;
  return {a.a, a.b + b.b};
}
void build(int x, int l, int r) {
  seg[x] = {1000000000000000000ll, r - l + 1};
  if (l == r) return;
  build(x << 1, l, ((l + r) >> 1)), build(x << 1 | 1, ((l + r) >> 1) + 1, r);
}
void upd(int x, long long d) { tag[x] += d, seg[x].a += d; }
void down(int x) {
  if (tag[x]) upd(x << 1, tag[x]), upd(x << 1 | 1, tag[x]), tag[x] = 0;
}
void update(int x, int l, int r, int L, int R, long long d) {
  if (L <= l && r <= R) return upd(x, d);
  down(x);
  if (L <= ((l + r) >> 1)) update(x << 1, l, ((l + r) >> 1), L, R, d);
  if (((l + r) >> 1) < R) update(x << 1 | 1, ((l + r) >> 1) + 1, r, L, R, d);
  seg[x] = seg[x << 1] + seg[x << 1 | 1];
}
data query(int x, int l, int r, int L, int R) {
  if (L <= l && r <= R) return seg[x];
  down(x);
  if (L <= ((l + r) >> 1))
    if (((l + r) >> 1) < R)
      return query(x << 1, l, ((l + r) >> 1), L, R) +
             query(x << 1 | 1, ((l + r) >> 1) + 1, r, L, R);
    else
      return query(x << 1, l, ((l + r) >> 1), L, R);
  else
    return query(x << 1 | 1, ((l + r) >> 1) + 1, r, L, R);
}
int main() {
  int n = gi(), a, b, d;
  for (int i = 1; i <= n; ++i) a = gi(), b = gi(), A[a] = b;
  long long ans = 0;
  build(1, 1, n);
  smx.push(0);
  smn.push(0);
  for (int i = 1; i <= n; ++i) {
    while (smx.top() && A[smx.top()] < A[i])
      d = A[i] - A[smx.top()], smx.pop(),
      update(1, 1, n, smx.top() + 1, i - 1, d);
    while (smn.top() && A[smn.top()] > A[i])
      d = A[smn.top()] - A[i], smn.pop(),
      update(1, 1, n, smn.top() + 1, i - 1, d);
    if (i > 1) update(1, 1, n, 1, i - 1, -1);
    update(1, 1, n, i, i, -1000000000000000000ll);
    ans += seg[1].b;
    smx.push(i);
    smn.push(i);
  }
  printf("%lld\n", ans);
  return 0;
}
