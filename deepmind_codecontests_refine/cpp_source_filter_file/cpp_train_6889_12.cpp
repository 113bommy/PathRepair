#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 1e6 + 5;
const int S = (1 << 21);
int n, m;
long long len;
long long a[MAX_N + 1];
long long bit[MAX_N + 1];
long long dat[S];
long long sum(int i) {
  long long s = 0;
  while (i > 0) {
    s += bit[i];
    i -= i & -i;
  }
  return s;
}
void add(int i, long long x) {
  while (i <= m) {
    bit[i] += x;
    i += i & -i;
  }
}
void init(int k = 1, int l = 1, int r = len) {
  if (l == r) {
    dat[k] = a[l];
    return;
  }
  init(k * 2, l, (l + r) / 2);
  init(k * 2 + 1, (l + r) / 2 + 1, r);
  dat[k] = max(dat[k * 2], dat[k * 2 + 1]);
}
long long query(int L, int R, int k = 1, int l = 1, int r = len) {
  if (L <= l && R >= r) return dat[k];
  if (R < l || L > r) return -(1ll << 61);
  long long res1 = query(L, R, k * 2, l, (l + r) / 2);
  long long res2 = query(L, R, k * 2 + 1, (l + r) / 2 + 1, r);
  return max(res1, res2);
}
void solve() {
  init();
  if (m >= 2 * len) {
    for (int i = 1; i <= len; i++) {
      long long x = max((long long)0, query(1, i));
      add(i + 1, -x);
      add(i, x);
    }
    for (int i = m; i >= m - (len - 1); i--) {
      long long x = max((long long)0, query(len - (m - i), len));
      add(i + 1, -x);
      add(i, x);
    }
    long long x = max((long long)0, query(1, len));
    if (m != 2 * len) {
      add(len + 1, x);
      add(m - (len - 1), -x);
    }
  } else {
    for (int i = 1; i <= m; i++) {
      int l = len + i - m, r = i;
      bool t = false;
      if (l < 1) {
        l = 1;
        t = true;
      }
      if (r > len) {
        r = len;
        t = true;
      }
      long long x = query(l, r);
      if (t) x = max(x, (long long)0);
      add(i, x);
      add(i + 1, -x);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &len);
    for (int i = 1; i <= len; i++) scanf("%lld", a + i);
    solve();
  }
  for (int i = 1; i <= n; i++) printf("%lld ", sum(i));
  return 0;
}
