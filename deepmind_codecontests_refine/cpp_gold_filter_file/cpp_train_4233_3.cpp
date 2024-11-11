#include <bits/stdc++.h>
using namespace std;
const int N = 2000010, Mo = 1000000007;
int a[N], b[N], v[N], s1[N], s2[N];
inline int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch == '-' ? o = -1 : 0, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return o * x;
}
inline int Pow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1LL * ret * x % Mo;
    x = 1LL * x * x % Mo, y >>= 1;
  }
  return ret;
}
struct Tree {
  int lz[N], tr[N];
  inline void pushdown(int l, int mid, int r, int o) {
    int &z = lz[o];
    tr[o << 1] = 1LL * (mid - l + 1) * z % Mo,
            tr[o << 1 | 1] = 1LL * (r - mid) * z % Mo;
    lz[o << 1] = lz[o << 1 | 1] = z, z = -1;
  }
  inline void update(int l, int r, int L, int R, int z, int o) {
    if (L <= l && r <= R) {
      lz[o] = z, tr[o] = 1LL * (r - l + 1) * z % Mo;
      return;
    }
    int mid = (l + r) >> 1;
    if (~lz[o]) pushdown(l, mid, r, o);
    if (L <= mid) update(l, mid, L, R, z, o << 1);
    if (R > mid) update(mid + 1, r, L, R, z, o << 1 | 1);
    tr[o] = (tr[o << 1] + tr[o << 1 | 1]) % Mo;
  }
} T[2];
int main() {
  int k, n, m, tp = 2, ans = 1;
  cin >> k >> n >> m, v[2] = k;
  for (int i = 1; i <= n; i++) a[i] = v[++tp] = gi() - 1, b[i] = v[++tp] = gi();
  for (int i = 1, j = n; i <= m; i++)
    a[++j] = v[++tp] = gi() - 1, b[j] = v[++tp] = gi();
  sort(v + 1, v + 1 + tp);
  tp = unique(v + 1, v + 1 + tp) - v - 1;
  for (int i = 1; i <= n + m; i++) {
    int x, y;
    x = lower_bound(v + 1, v + 1 + tp, a[i]) - v;
    y = lower_bound(v + 1, v + 1 + tp, b[i]) - v;
    if (i <= n)
      s1[y] = max(s1[y], x);
    else
      s2[y] = max(s2[y], x);
  }
  for (int i = 0; i < 2; i++) memset(T[0].lz, -1, sizeof(T[0].lz));
  for (int i = 2; i <= tp; i++) {
    int x = T[0].tr[1], y = T[1].tr[1];
    T[0].update(1, tp, i, i, (ans + y) % Mo, 1);
    T[1].update(1, tp, i, i, (ans + x) % Mo, 1);
    if (s1[i]) T[0].update(1, tp, 1, s1[i] + 1, 0, 1);
    if (s2[i]) T[1].update(1, tp, 1, s2[i] + 1, 0, 1);
    ans = (1LL * ans + x + y) * (Pow(2, v[i] - v[i - 1]) - 2) % Mo;
  }
  cout << ((1LL * ans + T[0].tr[1] + T[1].tr[1]) % Mo + Mo) % Mo;
  return 0;
}
