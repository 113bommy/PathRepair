#include <bits/stdc++.h>
using namespace std;
const int MaxN = (1 << 19);
long long v[MaxN], p[MaxN], s[MaxN];
void construct(int x, int l, int r) {
  s[x] = r - l + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  construct(x * 2, l, mid);
  construct(x * 2 + 1, mid + 1, r);
}
int L, R;
inline void add(int x, int V) {
  v[x] += V * s[x];
  p[x] += V;
}
inline void prop(int x) {
  add(x * 2, p[x]);
  add(x * 2 + 1, p[x]);
  p[x] = 0;
}
void update(int x, int l, int r) {
  if (l > R || r < L) return;
  if (l >= L && r <= R) {
    add(x, 1);
    return;
  }
  prop(x);
  int mid = (l + r) >> 1;
  update(x * 2, l, mid);
  update(x * 2 + 1, mid + 1, r);
  s[x] = s[x * 2] + s[x * 2 + 1];
  v[x] = v[x * 2] + v[x * 2 + 1];
}
int get(int x, int l, int r) {
  if (l > R || r < L) return 0;
  if (l == r) return v[x];
  prop(x);
  int mid = (l + r) >> 1;
  int ret = get(x * 2, l, mid) + get(x * 2 + 1, mid + 1, r);
  s[x] = s[x * 2] + s[x * 2 + 1];
  v[x] = v[x * 2] + v[x * 2 + 1];
  return ret;
}
void rem(int x, int l, int r) {
  if (l > R || r < L) return;
  --s[x];
  if (l == r) {
    v[x] = 0;
    return;
  }
  prop(x);
  int mid = (l + r) >> 1;
  rem(x * 2, l, mid);
  rem(x * 2 + 1, mid + 1, r);
  s[x] = s[x * 2] + s[x * 2 + 1];
  v[x] = v[x * 2] + v[x * 2 + 1];
}
int rev(int x) {
  int ret = 0;
  while (x > 0) {
    ret = ret * 10 + x % 10;
    x /= 10;
  }
  return ret;
}
int n, m, w;
long long A[MaxN], B[MaxN];
int q[MaxN], pos[MaxN];
int cmp(int x, int y) {
  if (A[x] * B[y] != A[y] * B[x]) return A[x] * B[y] < A[y] * B[x];
  return x < y;
}
int lower(int a, int b) {
  int lo, hi;
  lo = 0;
  hi = m;
  while (lo < hi) {
    int mi = (lo + hi) >> 1;
    if (A[q[mi]] * b < a * B[q[mi]])
      lo = mi + 1;
    else
      hi = mi;
  }
  return lo;
}
int upper(int a, int b) {
  int lo, hi;
  lo = 0;
  hi = m;
  while (lo < hi) {
    int mi = (lo + hi) >> 1;
    if (A[q[mi]] * b <= a * B[q[mi]])
      lo = mi + 1;
    else
      hi = mi;
  }
  return lo - 1;
}
int main(void) {
  scanf("%d%d%d", &n, &m, &w);
  for (int i = 1; i <= m; ++i) {
    A[i] = rev(i);
    B[i] = i;
    q[i - 1] = i;
  }
  sort(q, q + m, cmp);
  for (int i = 0; i < m; ++i) pos[q[i]] = i;
  construct(1, 0, m - 1);
  long long sol = ((long long)1 << (long long)62);
  int sa, sb;
  sa = sb = -1;
  int last = m;
  for (int i = 1; i <= n; ++i) {
    L = lower(i, rev(i));
    R = upper(i, rev(i));
    if (R < L) continue;
    update(1, 0, m - 1);
    while (v[1] > w) {
      L = pos[last];
      R = L;
      int x = get(1, 0, m - 1);
      if (v[1] - x >= w) {
        rem(1, 0, m - 1);
        --last;
      } else
        break;
    }
    if (v[1] >= w)
      if (sol > (long long)i * (long long)last) {
        sol = (long long)i * (long long)last, sa = i;
        sb = last;
      }
  }
  if (sa != -1)
    printf("%d %d\n", sa, sb);
  else
    puts("-1");
  return 0;
}
