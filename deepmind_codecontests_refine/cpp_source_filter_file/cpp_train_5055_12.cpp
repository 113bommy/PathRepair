#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const long long inf = (long long)1e18 + 10;
int n, q;
int a[N];
long long b[N], d[N];
long long tr[N * 4];
void pushdown(int p, int l, int r) {
  if (tr[p] == 0) return;
  tr[(p << 1)] += tr[p];
  tr[(p << 1 | 1)] += tr[p];
  tr[p] = 0;
}
void build(int p, int l, int r) {
  if (l == r) {
    tr[p] = a[l];
    return;
  }
  build((p << 1), l, ((l + r) >> 1));
  build((p << 1 | 1), ((l + r) >> 1) + 1, r);
}
void update(int p, int l, int r, int ll, int rr, int v) {
  if (ll > rr) return;
  if (rr < l || ll > r) return;
  if (ll <= l && rr >= r) {
    tr[p] += v;
    return;
  }
  pushdown(p, l, r);
  update((p << 1), l, ((l + r) >> 1), ll, rr, v);
  update((p << 1 | 1), ((l + r) >> 1) + 1, r, ll, rr, v);
}
long long query(int p, int l, int r, int x) {
  if (l == r) return tr[p];
  pushdown(p, l, r);
  if (x <= ((l + r) >> 1))
    return query((p << 1), l, ((l + r) >> 1), x);
  else
    return query((p << 1 | 1), ((l + r) >> 1) + 1, r, x);
}
struct node {
  long long lz[2], mn[2];
} tr2[N * 4];
node mrg(const node &a, const node &b) {
  node c;
  c.lz[0] = c.lz[1] = 0;
  c.mn[0] = min(a.mn[0], b.mn[0]);
  c.mn[1] = min(a.mn[1], b.mn[1]);
  return c;
}
void pushdown2(int p, int l, int r) {
  if (tr2[p].lz[0] != 0) {
    tr2[(p << 1)].lz[0] += tr2[p].lz[0];
    tr2[(p << 1 | 1)].lz[0] += tr2[p].lz[0];
    tr2[(p << 1)].mn[0] += tr2[p].lz[0];
    tr2[(p << 1 | 1)].mn[0] += tr2[p].lz[0];
    tr2[p].lz[0] = 0;
  }
  if (tr2[p].lz[1] != 0) {
    tr2[(p << 1)].lz[1] += tr2[p].lz[1];
    tr2[(p << 1 | 1)].lz[1] += tr2[p].lz[1];
    tr2[(p << 1)].mn[1] += tr2[p].lz[1];
    tr2[(p << 1 | 1)].mn[1] += tr2[p].lz[1];
    tr2[p].lz[1] = 0;
  }
}
void build2(int p, int l, int r) {
  if (l == r) {
    tr2[p].mn[l & 1] = b[l];
    tr2[p].mn[(l & 1) ^ 1] = inf;
    return;
  }
  build2((p << 1), l, ((l + r) >> 1));
  build2((p << 1 | 1), ((l + r) >> 1) + 1, r);
  tr2[p] = mrg(tr2[(p << 1)], tr2[(p << 1 | 1)]);
}
void update2(int p, int l, int r, int id, int ll, int rr, int v) {
  if (ll > rr) return;
  if (ll > r || rr < l) return;
  if (ll <= l && rr >= r) {
    tr2[p].lz[id] += v;
    tr2[p].mn[id] += v;
    return;
  }
  pushdown2(p, l, r);
  update2((p << 1), l, ((l + r) >> 1), id, ll, rr, v);
  update2((p << 1 | 1), ((l + r) >> 1) + 1, r, id, ll, rr, v);
  tr2[p] = mrg(tr2[(p << 1)], tr2[(p << 1 | 1)]);
}
long long query2(int p, int l, int r, int x) {
  if (x < 0) return 0;
  if (l == r) {
    return tr2[p].mn[x & 1];
  }
  pushdown2(p, l, r);
  if (x <= ((l + r) >> 1))
    return query2((p << 1), l, ((l + r) >> 1), x);
  else
    return query2((p << 1 | 1), ((l + r) >> 1) + 1, r, x);
}
pair<long long, long long> mrg(const pair<long long, long long> &a,
                               const pair<long long, long long> &b) {
  return make_pair(min(a.first, b.first), min(a.second, b.second));
}
pair<long long, long long> querymn(int p, int l, int r, int ll, int rr) {
  if (ll > rr) return make_pair(inf, inf);
  if (ll > r || rr < l) return make_pair(inf, inf);
  if (ll <= l && rr >= l) return make_pair(tr2[p].mn[0], tr2[p].mn[1]);
  pushdown(p, l, r);
  return mrg(querymn((p << 1), l, ((l + r) >> 1), ll, rr),
             querymn((p << 1 | 1), ((l + r) >> 1) + 1, r, ll, rr));
}
void upd(int l, int r, int v) {
  update(1, 0, n - 1, l, r, v);
  update2(1, 0, n - 1, l & 1, l, n - 1, v);
  update2(1, 0, n - 1, (r + 1) & 1, r + 1, n - 1, -v);
}
bool check(int l, int r) {
  int l0 = 1;
  long long l1 = query(1, 0, n - 1, l) + 1 - l0;
  if (l1 <= 0) return 0;
  long long fi0 = query2(1, 0, n - 1, l - 1);
  long long fi1 = query2(1, 0, n - 1, l);
  auto p = querymn(1, 0, n - 1, l, r);
  if ((l - 1) & 1) {
    if (p.second - fi0 + l0 <= 0) {
      return 0;
    }
  } else {
    if (p.first - fi0 + l0 <= 0) {
      return 0;
    }
  }
  if (l & 1) {
    if (p.second - fi1 + l1 <= 0) {
      return 0;
    }
  } else {
    if (p.first - fi1 + l1 <= 0) {
      return 0;
    }
  }
  long long fin = query2(1, 0, n - 1, r);
  if ((r & 1) == (l & 1)) {
    if (fin - fi1 + l1 != 1) return 0;
  } else {
    if (fin - fi0 + l0 != 1) return 0;
  }
  return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  for (int i = 1; i < n; ++i) d[i] = a[i] - a[i - 1];
  for (int i = 1; i < n; i += 2) b[i] = (i - 2 > 0 ? b[i - 2] : 0) + d[i];
  for (int i = 2; i < n; i += 2) b[i] = b[i - 2] + d[i];
  build(1, 0, n - 1);
  build2(1, 0, n - 1);
  scanf("%d", &q);
  for (int i = 0, t; i < q; ++i) {
    scanf("%d", &t);
    if (t == 1) {
      int a, b, k;
      scanf("%d%d%d", &a, &b, &k);
      upd(a, b, k);
    } else {
      int a, b;
      scanf("%d%d", &a, &b);
      puts(check(a, b) ? "1" : "0");
    }
  }
  return 0;
}
