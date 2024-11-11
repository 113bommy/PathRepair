#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e18;
const int maxn = 500010;
int n, root, topt, nt[maxn], sx, sy;
long long ans;
struct da {
  int lc, rc;
} a[4 * maxn];
struct qu {
  int op;
  long long x, y;
} q[maxn];
vector<int> now[4 * maxn];
vector<int> tu[4 * maxn];
bool cmp(int aa, int bb) {
  if ((double)(q[aa].y - sy) * (q[bb].x - sx) ==
      (double)(q[bb].y - sy) * (q[aa].x - sx))
    return abs(q[aa].x - sx) < abs(q[bb].x - sx);
  return (double)(q[aa].y - sy) * (q[bb].x - sx) <
         (double)(q[bb].y - sy) * (q[aa].x - sx);
}
void build_tree(int &n, int l, int r) {
  n = ++topt;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build_tree(a[n].lc, l, mid);
  build_tree(a[n].rc, mid + 1, r);
}
void tree_add(int n, int L, int R, int l, int r, int k) {
  if (L == l && R == r) {
    now[n].push_back(k);
    return;
  }
  int mid = (L + R) >> 1;
  if (r <= mid)
    tree_add(a[n].lc, L, mid, l, r, k);
  else if (l >= mid + 1)
    tree_add(a[n].rc, mid + 1, R, l, r, k);
  else
    tree_add(a[n].lc, L, mid, l, mid, k),
        tree_add(a[n].rc, mid + 1, R, mid + 1, r, k);
}
bool cro(int a, int b, int c) {
  return (double)(q[c].y - q[b].y) * (q[b].x - q[a].x) <
         (double)(q[b].y - q[a].y) * (q[c].x - q[b].x);
}
void work(int n, int l, int r) {
  if (now[n].size()) {
    sy = 1e9 + 10;
    for (auto i : now[n])
      if (q[i].y < sy) {
        sx = q[i].x;
        sy = q[i].y;
      }
    sort(now[n].begin(), now[n].end(), cmp);
    int rr = -1;
    for (auto i : now[n]) {
      while (rr >= 1 && cro(tu[n][rr - 1], tu[n][rr], i))
        tu[n].pop_back(), rr--;
      tu[n].push_back(i);
      rr++;
    }
  }
  if (l == r) return;
  int mid = (l + r) >> 1;
  work(a[n].lc, l, mid);
  work(a[n].rc, mid + 1, r);
}
long long calc(int n, long long kk) { return 1ll * q[n].x * kk + 1ll * q[n].y; }
void qury(int n, int l, int r, int lc, long long mul) {
  if (tu[n].size()) {
    int ll = 0, rr = tu[n].size() - 1;
    while (ll <= rr - 20) {
      int lmid = ll + (rr - ll) / 3;
      int rmid = rr - (rr - ll) / 3;
      if (calc(tu[n][rmid], mul) >= calc(tu[n][lmid], mul)) {
        ll = lmid;
        ans = max(ans, calc(tu[n][rmid], mul));
      } else {
        rr = rmid;
        ans = max(ans, calc(tu[n][lmid], mul));
      }
    }
    for (int i = ll; i <= rr; i++) ans = max(ans, calc(tu[n][i], mul));
  }
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (lc <= mid)
    qury(a[n].lc, l, mid, lc, mul);
  else
    qury(a[n].rc, mid + 1, r, lc, mul);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) nt[i] = n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &q[i].op);
    if (q[i].op == 1)
      scanf("%lld%lld", &q[i].x, &q[i].y);
    else
      scanf("%lld", &q[i].x);
    if (q[i].op == 2) nt[q[i].x] = i;
  }
  build_tree(root, 1, n);
  for (int i = 1; i <= n; i++)
    if (q[i].op == 1) tree_add(root, 1, n, i, nt[i], i);
  work(root, 1, n);
  for (int i = 1; i <= n; i++)
    if (q[i].op == 3) {
      ans = -inf;
      qury(root, 1, n, i, q[i].x);
      if (ans == -inf)
        printf("EMPTY SET\n");
      else
        printf("%lld\n", ans);
    }
  return 0;
}
