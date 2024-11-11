#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 100010;
int n, m, a[N], p[N], lp, pre[N], suf[N], ans;
int tr[N];
int tot, rt[N], lf[N * 30], rf[N * 30];
int L[N * 30], R[N * 30], LM[N * 30], MR[N * 30], LMR[N * 30], cnt[N * 30];
inline int add(const int &x, const int &y) {
  return x + y < mod ? x + y : x + y - mod;
}
inline int sub(const int &x, const int &y) {
  return x - y < 0 ? x - y + mod : x - y;
}
inline int mul(const int &x, const int &y) {
  return (int)((long long)x * y % mod);
}
inline void Add(int x, int w) {
  for (; x <= lp; x += x & -x) tr[x] += w;
}
inline int Ask(int x) {
  int w = 0;
  for (; x; x -= x & -x) w += tr[x];
  return w;
}
void pushup(int u) {
  cnt[u] = add(cnt[lf[u]], cnt[rf[u]]);
  L[u] = add(L[lf[u]], L[rf[u]]), R[u] = add(R[lf[u]], R[rf[u]]);
  LM[u] = add(LM[lf[u]], add(LM[rf[u]], mul(cnt[rf[u]], L[lf[u]])));
  MR[u] = add(MR[lf[u]], add(MR[rf[u]], mul(cnt[lf[u]], R[rf[u]])));
  LMR[u] = add(LMR[lf[u]], LMR[rf[u]]);
  LMR[u] = add(LMR[u], add(mul(LM[lf[u]], R[rf[u]]), mul(L[lf[u]], MR[rf[u]])));
}
void mdy(int &u, int l, int r, int x, int wx, int wy, int w) {
  if (!u) u = ++tot;
  if (l >= r) {
    L[u] = wx, R[u] = wy, cnt[u] += w;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    mdy(lf[u], l, mid, x, wx, wy, w);
  else
    mdy(rf[u], mid + 1, r, x, wx, wy, w);
  pushup(u);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), p[i] = a[i];
  sort(p + 1, p + n + 1), lp = unique(p + 1, p + n + 1) - p - 1;
  for (int i = 1; i <= n; i++) a[i] = lower_bound(p + 1, p + lp + 1, a[i]) - p;
  for (int i = 1; i <= n; i++) pre[i] = Ask(a[i]), Add(a[i], 1);
  for (int i = 1; i <= lp; i++) tr[i] = 0;
  for (int i = n; i >= 1; i--) suf[i] = Ask(a[i]), Add(a[i], 1);
  for (int i = 1; i <= n; i++) {
    ans = sub(ans, LMR[rt[a[i]]]);
    mdy(rt[a[i]], 1, n, i, pre[i], suf[i], 1);
    ans = add(ans, LMR[rt[a[i]]]);
  }
  scanf("%d", &m);
  for (int opt, x; m; --m) {
    scanf("%d%d", &opt, &x);
    ans = sub(ans, LMR[rt[a[x]]]);
    if (opt == 1)
      mdy(rt[a[x]], 1, n, x, 0, 0, -1);
    else
      mdy(rt[a[x]], 1, n, x, pre[x], suf[x], 1);
    ans = add(ans, LMR[rt[a[x]]]);
    printf("%d\n", ans);
  }
  return 0;
}
