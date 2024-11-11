#include <bits/stdc++.h>
using namespace std;
void getint(int &v) {
  char ch, fu = 0;
  for (ch = '*'; (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
    ;
  if (ch == '-') fu = 1, ch = getchar();
  for (v = 0; ch >= '0' && ch <= '9'; ch = getchar()) v = v * 10 + ch - '0';
  if (fu) v = -v;
}
long long ans;
int n, m, k, tmp[500010], mn[500010], ts, tag[500010], TMP[500010], a[500010],
    b[500010], c[500010], d[500010], TS;
vector<pair<int, int> > v[500010];
struct node {
  int v[30];
  node() { memset(v, 0, sizeof(v)); }
  node operator*(const int &A) const {
    node G;
    for (int i = 0; i <= k; ++i) G.v[i] = v[i] * A;
    return G;
  }
  node operator-(const node &A) const {
    node G;
    for (int i = 0; i <= k; ++i) G.v[i] = v[i] - A.v[i];
    return G;
  }
} T[500010], e[100010], ALL;
node cal(int n) {
  node ans;
  for (int i = k; i >= 0; --i) ans.v[i] = n / (1 << i);
  for (int i = 0; i <= k - 1; ++i) ans.v[i] = ans.v[i + 1] - ans.v[i];
  return ans;
}
void pushup(int rt) {
  mn[rt] = min(mn[rt << 1], mn[rt << 1 | 1]);
  for (int i = 0; i <= k; ++i) T[rt].v[i] = 0;
  if (mn[rt << 1] == mn[rt]) {
    for (int i = 0; i <= k; ++i) T[rt].v[i] += T[rt << 1].v[i];
  }
  if (mn[rt << 1 | 1] == mn[rt]) {
    for (int i = 0; i <= k; ++i) T[rt].v[i] += T[rt << 1 | 1].v[i];
  }
}
void TAG(int rt, int x) {
  mn[rt] += x;
  tag[rt] += x;
}
void pushdown(int rt) {
  if (tag[rt] != 0) {
    TAG(rt << 1, tag[rt]);
    TAG(rt << 1 | 1, tag[rt]);
    tag[rt] = 0;
  }
}
void build(int l, int r, int rt) {
  if (l == r) {
    mn[rt] = 0;
    T[rt] = e[l];
    return;
  }
  int m = l + r >> 1;
  build(l, m, rt << 1);
  build(m + 1, r, rt << 1 | 1);
  pushup(rt);
}
void upd(int l, int r, int rt, int L, int R, int x) {
  if (l >= L && r <= R) {
    TAG(rt, x);
    return;
  }
  pushdown(rt);
  int m = l + r >> 1;
  if (L <= m) upd(l, m, rt << 1, L, R, x);
  if (R > m) upd(m + 1, r, rt << 1 | 1, L, R, x);
  pushup(rt);
}
int main() {
  cin >> n >> m >> k;
  k = log2(k);
  for (int i = 1; i <= m; ++i) {
    getint(a[i]), getint(b[i]), getint(c[i]), getint(d[i]);
    tmp[++ts] = a[i];
    tmp[++ts] = c[i] + 1;
    TMP[++TS] = b[i];
    TMP[++TS] = d[i] + 1;
  }
  sort(tmp + 1, tmp + ts + 1);
  ts = unique(tmp + 1, tmp + ts + 1) - tmp - 1;
  sort(TMP + 1, TMP + TS + 1);
  TS = unique(TMP + 1, TMP + TS + 1) - TMP - 1;
  for (int i = 1; i <= m; ++i) {
    int l = lower_bound(TMP + 1, TMP + TS + 1, b[i]) - TMP;
    int r = upper_bound(TMP + 1, TMP + TS + 1, d[i]) - TMP;
    v[l].push_back(make_pair(i, 1));
    v[r].push_back(make_pair(i, -1));
  }
  for (int i = 1; i <= m; ++i) {
    a[i] = lower_bound(tmp + 1, tmp + ts + 1, a[i]) - tmp;
    c[i] = upper_bound(tmp + 1, tmp + ts + 1, c[i]) - tmp - 1;
  }
  --ts;
  for (int i = 1; i <= ts; ++i) {
    e[i] = cal(tmp[i + 1] - 1) - cal(tmp[i] - 1);
  }
  build(1, ts, 1);
  ALL = cal(tmp[ts + 1] - 1) - cal(tmp[1] - 1);
  for (int i = 1; i <= TS - 1; ++i) {
    for (int t = 0; t < v[i].size(); ++t) {
      pair<int, int> tt = v[i][t];
      upd(1, ts, 1, a[tt.first], c[tt.first], tt.second);
    }
    node O;
    if (!mn[1]) {
      for (int j = 0; j <= k; ++j) O.v[j] = T[1].v[j];
    }
    for (int j = 0; j <= k; ++j) O.v[j] = ALL.v[j] - O.v[j];
    node o = cal(TMP[i + 1] - 1) - cal(TMP[i] - 1);
    for (int p = 0; p <= k; ++p)
      for (int q = 0; q <= k; ++q)
        ans ^= (1ll << min(p, q)) * (1ll * O.v[p] * o.v[q] % 2);
  }
  if (ans)
    puts("Hamed");
  else
    puts("Malek");
  return 0;
}
