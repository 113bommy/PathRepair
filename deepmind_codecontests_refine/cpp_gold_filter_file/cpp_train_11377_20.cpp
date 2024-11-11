#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int N = 5e5 + 5;
const int M = 8e5 + 5;
const int inf = 0x3f3f3f3f;
const long long mod = 1e8 + 7;
const double eps = 1e-5;
const long double pi = acos(-1.0L);
long long read() {
  long long x = 0, t = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    if (ch == '-') t = -1;
  while (isdigit(ch)) {
    x = 10 * x + ch - '0';
    ch = getchar();
  }
  return x * t;
}
long long c[N << 2], ma[N << 2], lz[N << 2], fz[N << 2];
inline void pushdown(int i, int l, int r) {
  if (fz[i]) {
    long long &x = fz[i];
    int mid = l + r >> 1;
    c[(i << 1)] = 1LL * x * (mid - l + 1);
    c[(i << 1 | 1)] = 1LL * x * (r - mid);
    ma[(i << 1)] = ma[(i << 1 | 1)] = x;
    fz[(i << 1)] = fz[(i << 1 | 1)] = x;
    x = lz[(i << 1)] = lz[(i << 1 | 1)] = 0;
  }
  if (lz[i]) {
    long long &x = lz[i];
    int mid = l + r >> 1;
    c[(i << 1)] += 1LL * x * (mid - l + 1);
    c[(i << 1 | 1)] += 1LL * x * (r - mid);
    ma[(i << 1)] += x;
    ma[(i << 1 | 1)] += x;
    lz[(i << 1)] += x;
    lz[(i << 1 | 1)] += x;
    x = 0;
  }
}
void update(int i, int l, int r, int ll, int rr, int x, const int flag) {
  if (ll <= l && r <= rr) {
    if (flag)
      c[i] += 1LL * x * (r - l + 1), ma[i] += x, lz[i] += x;
    else
      c[i] = 1LL * x * (r - l + 1), ma[i] = x, fz[i] = x, lz[i] = 0;
    return;
  }
  pushdown(i, l, r);
  int mid = l + r >> 1;
  if (mid >= ll) update((i << 1), l, mid, ll, rr, x, flag);
  if (mid < rr) update((i << 1 | 1), mid + 1, r, ll, rr, x, flag);
  c[i] = c[(i << 1)] + c[(i << 1 | 1)];
  ma[i] = max(ma[(i << 1)], ma[(i << 1 | 1)]);
}
int query(int i, int l, int r, int x) {
  if (l == r) return l;
  pushdown(i, l, r);
  int mid = l + r >> 1;
  if (x <= ma[(i << 1 | 1)])
    return query((i << 1 | 1), mid + 1, r, x);
  else
    return query((i << 1), l, mid, x);
}
char s[N];
int main() {
  int n = read();
  scanf("%s", s + 1);
  long long ans = 0;
  int last = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1') {
      if (!last) last = i;
      int x = query(1, 1, n, i - last + 1);
      update(1, 1, n, last, i, 1, 1);
      if (x < last) update(1, 1, n, x, last - 1, i - last + 1, 0);
    } else
      last = 0;
    ans += c[1];
  }
  printf("%lld\n", ans);
  return 0;
}
