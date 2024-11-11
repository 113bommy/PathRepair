#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
long long a, b, c, d[N], n, m, pref[N], suff, vis[N], last[N], ans;
vector<int> dv[N];
struct SegmentTree {
  int T[N << 2], lz[N << 2];
  void form_tree(int l, int r, int v) {
    if (l == r) {
      T[v] = pref[l];
      return;
    }
    form_tree(l, ((l + r) >> 1), v << 1);
    form_tree(((l + r) >> 1) + 1, r, v << 1 | 1);
    T[v] = T[v << 1] + T[v << 1 | 1];
  }
  void shift(int l, int r, int v) {
    if (!lz[v]) return;
    T[v << 1] = (((l + r) >> 1) - l + 1) * lz[v];
    T[v << 1 | 1] = (r - ((l + r) >> 1)) * lz[v];
    lz[v << 1] = lz[v];
    lz[v << 1 | 1] = lz[v];
    lz[v] = 0;
  }
  long long get(int x, int y, int l, int r, int v) {
    if (y < l || r < x) return 0;
    if (x <= l && r <= y) return T[v];
    shift(l, r, v);
    return (get(x, y, l, ((l + r) >> 1), v << 1) +
            get(x, y, ((l + r) >> 1) + 1, r, v << 1 | 1));
  }
  void upd(int x, int y, int z, int l, int r, int v) {
    if (y < l || r < x) return;
    if (x <= l && r <= y) {
      T[v] = 1LL * (r - l + 1) * z, lz[v] = z;
      return;
    }
    shift(l, r, v);
    upd(x, y, z, l, ((l + r) >> 1), v << 1);
    upd(x, y, z, ((l + r) >> 1) + 1, r, v << 1 | 1);
    T[v] = T[v << 1] + T[v << 1 | 1];
  }
  void bul(int l, int r, int v) {
    int now = l;
    for (int i = 19; i >= 0; i--)
      if (now + (1 << i) <= r &&
          get(now + (1 << i), now + (1 << i), 1, n, 1) <= v)
        now += (1 << i);
    if (get(now, now, 1, n, 1) <= v) upd(l, now, v, 1, n, 1);
  }
} S;
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &d[i]);
  for (int i = 1; i < N - 4; i++)
    for (int j = i; j < N - 4; j += i) dv[j].push_back(i);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1];
    for (int j : dv[d[i]]) {
      if (vis[j])
        umax(pref[i], 1LL * j);
      else
        last[j] = i;
      vis[j] = 1;
    }
  }
  S.form_tree(1, n, 1);
  memset(vis, 0, sizeof(vis));
  for (int i = n; i > 0; i--) {
    ans += S.get(1, i - 1, 1, n, 1) + suff;
    for (int j : dv[d[i]]) {
      if (vis[j]) umax(suff, 1LL * j);
      if (last[j]) S.bul(last[j], i - 1, j), last[j] = 0;
      vis[j] = 1;
    }
    S.bul(1, i - 1, suff);
  }
  printf("%lld\n", ans);
  return 0;
}
