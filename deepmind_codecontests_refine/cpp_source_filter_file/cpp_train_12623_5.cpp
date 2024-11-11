#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
const int n1 = 1 << 8;
template <typename _T>
void read(_T &x) {
  _T f = 1;
  x = 0;
  char s = getchar();
  while ('0' > s || '9' < s) {
    if (s == '-') f = -1;
    s = getchar();
  }
  while ('0' <= s && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    s = getchar();
  }
  x *= f;
}
int n, q, tot, a[(1 << 12) + 5], b[(1 << 12) + 5], t[(1 << 12) + 5],
    ans[(1 << 18) + 5];
pair<int, int> answ[(1 << 22) + 5];
int merge(int x, int y) {
  if (!x || !y) return x + y;
  answ[tot] = make_pair(x, y);
  return ++tot;
}
struct Tree {
  vector<int> val;
  vector<vector<int> > id;
  Tree() {}
  Tree(int x) {
    init(1);
    val[0] = b[x];
    id[0][0] = b[x] + 1;
  }
  void init(int x) {
    val.resize(x);
    id.resize(x);
    for (int i = 0; i < x; i++) id[i].resize(x - i);
  }
  int ask(int l, int r) const {
    if (r < val.front() || l > val.back()) return 0;
    l = lower_bound(val.begin(), val.end(), l) - val.begin();
    r = upper_bound(val.begin(), val.end(), r) - val.begin() - 1;
    return l > r ? 0 : id[l][r - l];
  }
  Tree update(const Tree &x, const Tree &y) {
    init(x.val.size() + y.val.size());
    merge(x.val.begin(), x.val.end(), y.val.begin(), y.val.end(), val.begin());
    int siz = val.size();
    for (int i = 0; i < siz; i++)
      for (int j = i; j < siz; j++)
        id[i][j - i] = merge(x.ask(val[i], val[j]), y.ask(val[i], val[j]));
    return *this;
  }
} T[(1 << 12) + 5 / n1];
Tree solve(int l, int r) {
  if (l == r) return Tree(l);
  int mid = l + r >> 1;
  Tree res;
  return res.update(solve(l, mid), solve(mid + 1, r));
}
signed main() {
  read(n);
  read(q);
  tot = n--;
  for (int i = 0; i <= n; i++) read(a[i]), b[a[i]] = i;
  for (int i = 0; i <= n / n1; i++)
    T[i] = solve(i * n1, min(n, (i + 1) * n1 - 1));
  for (int i = 1; i <= q; i++) {
    int l, r;
    read(l);
    read(r);
    l--;
    r--;
    for (int j = 0; j <= n / n1; j++) ans[i] = merge(ans[i], T[j].ask(l, r));
  }
  printf("%d\n", tot);
  for (int i = n + 1; i < tot; i++)
    printf("%d %d\n", answ[i].first, answ[i].second);
  for (int i = 1; i <= q; i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
