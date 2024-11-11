#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N = 100005;
const double PI = acos(-1.0);
const double eps = 1e-9;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
struct Seg_T {
  int n, L, R;
  long long s[12 * N + 1005], lazy[12 * N + 1005], *a, v;
  void push_up(int rt) { s[rt] = min(s[rt << 1], s[rt << 1 | 1]); }
  void push_down(int rt) {
    if (!lazy[rt]) return;
    s[rt << 1] = lazy[rt << 1] = lazy[rt];
    s[rt << 1 | 1] = lazy[rt << 1 | 1] = lazy[rt];
    lazy[rt] = 0;
  }
  void B(int l, int r, int rt) {
    lazy[rt] = oo;
    if (l == r) {
      s[rt] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    B(l, mid, rt << 1);
    B(mid + 1, r, rt << 1 | 1);
    push_up(rt);
  }
  void Init(int _n, long long _a[] = NULL) {
    n = _n;
    if (_a == NULL) {
      for (int i = (0); i <= (12 * N + 1004); ++i) s[i] = oo;
      memset(lazy, 0, sizeof(lazy));
      return;
    }
    a = _a;
    B(1, n, 1);
  }
  void U(int l, int r, int rt) {
    if (L <= l && r <= R) {
      lazy[rt] = v;
      s[rt] = v;
      return;
    }
    push_down(rt);
    int mid = (l + r) >> 1;
    if (L <= mid) U(l, mid, rt << 1);
    if (R > mid) U(mid + 1, r, rt << 1 | 1);
    push_up(rt);
  }
  long long Q(int l, int r, int rt) {
    if (L <= l && r <= R) return s[rt];
    push_down(rt);
    int mid = (l + r) >> 1;
    long long ret = oo;
    if (L <= mid) ret = min(ret, Q(l, mid, rt << 1));
    if (R > mid) ret = min(ret, Q(mid + 1, r, rt << 1 | 1));
    push_up(rt);
    return ret;
  }
  void Update(int _L, int _R, long long _v) {
    L = _L, R = _R, v = _v;
    U(1, n, 1);
  }
  long long Query(int _L, int _R) {
    L = _L, R = _R;
    return Q(1, n, 1);
  }
};
struct ST {
  int n, log[N], dp[25][N];
  int *a;
  int h(int x, int y) { return a[x] <= a[y] ? x : y; }
  void Init(int _n, int *_a) {
    n = _n, a = _a, log[0] = -1;
    for (int i = (1); i <= (n); ++i) log[i] = log[i >> 1] + 1, dp[0][i] = i;
    for (int i = (1); i <= (log[n]); ++i)
      for (int j = (1); j <= (n + 1 - (1 << i)); ++j)
        dp[i][j] = h(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
  }
  int Query(int l, int r) {
    int L = log[r - l + 1];
    return a[h(dp[L][l], dp[L][r + 1 - (1 << L)])];
  }
};
int a[N], n, pre[N], suf[N], p[N], q[N], t, ans = oo, x, y, z;
Seg_T T;
ST A, B;
int main() {
  scanf("%d", &n), pre[0] = oo;
  for (int i = (1); i <= (n); ++i)
    scanf("%d", &a[i]), pre[i] = a[i] - i, suf[i] = a[i] + i;
  A.Init(n, pre), B.Init(n, suf);
  T.Init(3 * N + 105);
  for (int i = (1); i <= (n); ++i) {
    t = T.Query(2 * i - a[i] + N, 2 * i - a[i] + N);
    if (t == oo) T.Update(2 * i - a[i] + N, 2 * i - a[i] + N, i);
    p[i] = T.Query(i + 1 + N, 2 * N + N);
  }
  T.Init(N), q[1] = oo;
  for (int i = (n); i >= (1); --i) {
    if (i > 1) q[i] = T.Query(1, i - 1);
    T.Update(a[i], a[i], i);
  }
  for (int i = (1); i <= (n); ++i) {
    t = min(p[i], q[i]);
    if (t == oo) continue;
    x = y = z = oo;
    if (i < t) {
      x = A.Query(1, i) + i;
      if (i + 1 <= t - 1) y = B.Query(i + 1, t - 1) - i;
      z = B.Query(t, n) - i;
      ans = min(ans, max(min(x, y), z));
    } else if (i > t) {
      if (t >= 2) x = A.Query(1, t - 1) + i;
      y = B.Query(t, i) + i;
      if (i + 1 <= n) z = B.Query(i + 1, n) - i;
      ans = min(ans, max(x, min(y, z)));
    } else {
      if (i >= 2) x = A.Query(1, i - 1) + i;
      y = A.Query(i, i) + i;
      if (i + 1 <= n) z = B.Query(i + 1, n) - i;
      ans = min(ans, max(x, min(y, z)));
    }
  }
  if (ans != oo)
    printf("%d\n", ans);
  else
    printf("-1\n");
  return 0;
}
