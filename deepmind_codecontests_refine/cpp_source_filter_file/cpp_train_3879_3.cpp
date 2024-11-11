#include <bits/stdc++.h>
using namespace std;
const int N = 202000;
int n, m, l[N], r[N], num, du[N];
char str[N];
int fir[N], cnt;
struct node {
  int nxt, to;
} e[N << 2];
void add(int u, int v) {
  e[++cnt].nxt = fir[u];
  fir[u] = cnt;
  e[cnt].to = v;
}
void dfs(int u) {
  l[u] = ++num;
  for (int i = fir[u]; i; i = e[i].nxt) dfs(e[i].to);
  r[u] = num;
}
int tot, qtot;
struct matrix {
  int U, D, L, R;
  matrix() {}
  matrix(int a, int b, int c, int d) : U(a), D(b), L(c), R(d) {}
} a[N];
struct Query {
  int U, D, pos, opt;
  Query() {}
  Query(int a, int b, int c, int d) : U(a), D(b), pos(c), opt(d) {}
} q[N << 1];
bool cmp(const Query& aa, const Query& bb) {
  return aa.pos == bb.pos ? aa.opt < bb.opt : aa.pos < bb.pos;
}
struct seg_tree {
  int l, r, tag, len;
} tr[N << 2];
void build(int p, int l, int r) {
  tr[p].l = l, tr[p].r = r;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
}
int solve(int p) {
  if (tr[p].tag) return tr[p].r - tr[p].l + 1;
  return tr[p << 1].len + tr[p << 1 | 1].len;
}
void update(int p, int L, int R, int val) {
  if (L <= tr[p].l && tr[p].r <= R) {
    tr[p].tag += val;
    tr[p].len = solve(p);
    return;
  }
  int mid = (tr[p].l + tr[p].r) >> 1;
  if (L <= mid) update(p << 1, L, R, val);
  if (R > mid) update(p << 1 | 1, L, R, val);
  tr[p].len = solve(p);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", str + (i - 1) * m + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (i - 2 >= 1 && str[(i - 2 - 1) * m + j] == 'U') {
        add((i - 1) * m + j, (i - 2 - 1) * m + j);
        ++du[(i - 2 - 1) * m + j];
      }
      if (j - 2 >= 1 && str[(i - 1) * m + j - 2] == 'L') {
        add((i - 1) * m + j, (i - 1) * m + j - 2);
        ++du[(i - 1) * m + j - 2];
      }
      if (i + 2 <= n && str[(i + 2 - 1) * m + j] == 'D') {
        add((i - 1) * m + j, (i + 2 - 1) * m + j);
        ++du[(i + 2 - 1) * m + j];
      }
      if (j + 2 <= m && str[(i - 1) * m + j + 2] == 'R') {
        add((i - 1) * m + j, (i - 1) * m + j + 2);
        ++du[(i - 1) * m + j + 2];
      }
    }
  for (int i = 1; i <= n * m; ++i)
    if (!du[i]) {
      dfs(i);
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (str[(i - 1) * m + j] == 'U' && str[(i + 1 - 1) * m + j] == 'D') {
        a[++tot] = matrix(l[(i - 1) * m + j], r[(i - 1) * m + j],
                          l[(i + 1 - 1) * m + j], r[(i + 1 - 1) * m + j]);
        a[++tot] = matrix(l[(i + 1 - 1) * m + j], r[(i + 1 - 1) * m + j],
                          l[(i - 1) * m + j], r[(i - 1) * m + j]);
      } else if (str[(i - 1) * m + j] == 'L' &&
                 str[(i - 1) * m + j + 1] == 'R') {
        a[++tot] = matrix(l[(i - 1) * m + j], r[(i - 1) * m + j],
                          l[(i - 1) * m + j + 1], r[(i - 1) * m + j + 1]);
        a[++tot] = matrix(l[(i - 1) * m + j + 1], r[(i - 1) * m + j + 1],
                          l[(i - 1) * m + j], r[(i - 1) * m + j]);
      }
    }
  for (int i = 1; i <= tot; ++i) {
    q[++qtot] = Query(a[i].U, a[i].D, a[i].L, 1);
    q[++qtot] = Query(a[i].U, a[i].D, a[i].R + 1, -1);
  }
  sort(q + 1, q + qtot + 1, cmp);
  build(1, 1, n * m + 1);
  long long ans = 0;
  for (int i = 1; i <= qtot; ++i) {
    update(1, q[i].U, q[i].D, q[i].opt);
    if (i ^ qtot) {
      ans += 1LL * solve(1) * (q[i + 1].pos - q[i].pos);
    }
  }
  printf("%lld\n", ans / 2);
  return 0;
}
