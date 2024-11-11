#include <bits/stdc++.h>
using namespace std;
int n, K, D;
int nu[200200];
struct SEG {
  long long mi[2000200];
  long long laz[2000200];
  void build(int rt, int l, int r) {
    if (l == r) {
      mi[rt] = 1ll * l * D;
      return;
    }
    int mid = (l + r) / 2;
    build(rt * 2, l, mid);
    build(rt * 2 + 1, mid + 1, r);
    mi[rt] = min(mi[rt * 2], mi[rt * 2 + 1]);
  }
  void Tag(int rt, long long v) {
    mi[rt] += v;
    laz[rt] += v;
  }
  void pd(int rt) {
    if (!laz[rt]) return;
    Tag(rt * 2, laz[rt]);
    Tag(rt * 2 + 1, laz[rt]);
    laz[rt] = 0;
  }
  void change(int rt, int l, int r, int st, int ed, long long v) {
    pd(rt);
    if (l >= st && r <= ed) {
      Tag(rt, v);
      return;
    }
    int mid = (l + r) / 2;
    if (mid >= st) change(rt * 2, l, mid, st, ed, v);
    if (mid < ed) change(rt * 2 + 1, mid + 1, r, st, ed, v);
    mi[rt] = min(mi[rt * 2], mi[rt * 2 + 1]);
  }
  int ask(int rt, int l, int r, int st, int ed, long long v) {
    pd(rt);
    if (mi[rt] > v || l > ed || r < st) return n + 1;
    if (l == r) return l;
    int mid = (l + r) / 2;
    int lp = ask(rt * 2, l, mid, st, ed, v);
    if (lp <= n) return lp;
    return ask(rt * 2 + 1, mid + 1, r, st, ed, v);
  }
} seg;
int s1[200200], t1;
int s2[200200], t2;
map<int, int> la;
int ml[200200];
int main() {
  scanf("%d%d%d", &n, &K, &D);
  for (int i = 1; i <= n; ++i) scanf("%d", &nu[i]);
  if (D == 0) {
    int ans, len = 0;
    for (int i = 1, j; i <= n; ++i) {
      for (j = i; j < n && nu[j + 1] == nu[i]; ++j)
        ;
      if (j - i + 1 > len) len = j - i + 1, ans = i;
    }
    printf("%d %d\n", ans, ans + len - 1);
    return 0;
  }
  ml[0] = 1;
  int L = 0;
  seg.build(1, 1, n);
  int p;
  int ans, len = 0;
  for (int i = 1; i <= n; ++i) {
    if ((nu[i] % D + D) % D == (nu[i - 1] % D + D) % D)
      ml[i] = ml[i - 1];
    else
      ml[i] = i;
    L = max(L, la[nu[i]]);
    la[nu[i]] = i;
    seg.change(1, 1, n, 1, n, -D);
    while (t1 && nu[i] >= nu[s1[t1]])
      seg.change(1, 1, n, s1[t1 - 1] + 1, s1[t1], -nu[s1[t1]]), t1--;
    s1[++t1] = i;
    seg.change(1, 1, n, s1[t1 - 1] + 1, s1[t1], nu[s1[t1]]);
    while (t2 && nu[i] >= nu[s2[t2]])
      seg.change(1, 1, n, s2[t2 - 1] + 1, s2[t2], nu[s2[t2]]), t2--;
    s2[++t2] = i;
    seg.change(1, 1, n, s2[t2 - 1] + 1, s2[t2], -nu[s2[t2]]);
    p = seg.ask(1, 1, n, max(ml[i], L + 1), i, 1ll * K * D);
    if (i - p + 1 > len) len = i - p + 1, ans = p;
  }
  printf("%d %d\n", ans, ans + len - 1);
  return 0;
}
