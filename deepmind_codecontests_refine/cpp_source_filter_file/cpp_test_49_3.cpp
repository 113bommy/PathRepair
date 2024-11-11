#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
struct bian {
  int from, to;
} eg[N << 1];
int front[N], num;
void add(int x, int y) {
  eg[++num].to = y;
  eg[num].from = front[x];
  front[x] = num;
}
int a[N];
int p[N];
int tree[N << 2];
set<int> se[N];
int tot[N], col[N];
void opt1(int o, int l, int r, int i, int w) {
  if (l == r) {
    if (w > 0)
      se[l].insert(w), ++tree[o];
    else
      se[l].erase(-w), --tree[o];
    return;
  }
  int mid = (l + r) >> 1;
  if (mid >= i)
    opt1(o << 1, l, mid, i, w);
  else
    opt1(o << 1 | 1, mid + 1, r, i, w);
  tree[o] = tree[o << 1] + tree[o << 1 | 1];
}
int opt2(int o, int l, int r, int L, int R) {
  if (R < L) return 0;
  if (L <= l && r <= R) return tree[o];
  int mid = (l + r) >> 1, re = 0;
  if (mid >= L) re += opt2(o << 1, l, mid, L, R);
  if (mid < R) re += opt2(o << 1, mid + 1, r, L, R);
  return re;
}
int opt3(int o, int l, int r, int k) {
  if (tree[o] < k) return -1;
  if (l == r) return *se[l].begin();
  int mid = (l + r) >> 1;
  if (tree[o << 1] >= k) return opt3(o << 1, l, mid, k);
  return opt3(o << 1 | 1, mid + 1, r, k - tree[o << 1]);
}
struct QUE {
  int l, k, ids;
};
vector<QUE> que[N];
int ans[N];
int t, n, q;
void dfs(int o) {
  if (tot[col[o]]) opt1(1, 1, n, tot[col[o]], -col[o]);
  ++tot[col[o]];
  opt1(1, 1, n, tot[col[o]], col[o]);
  for (int i = 0; i < que[o].size(); ++i) {
    ans[que[o][i].ids] =
        opt3(1, 1, n, que[o][i].k + opt2(1, 1, n, 1, que[o][i].l - 1));
  }
  for (int i = front[o]; i; i = eg[i].from) {
    int to = eg[i].to;
    dfs(to);
  }
  opt1(1, 1, n, tot[col[o]], -col[o]);
  --tot[col[o]];
  if (tot[col[o]]) opt1(1, 1, n, tot[col[o]], col[o]);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> col[i], front[i] = 0;
    num = 0;
    for (int i = 1; i <= n; ++i) se[i].clear(), que[i].clear();
    for (int i = 1; i <= n << 2; ++i) tree[i] = 0;
    for (int i = 2; i <= n; ++i) {
      int fa;
      cin >> fa;
      add(fa, i);
    }
    for (int i = 1; i <= q; ++i) {
      int v, l, k;
      cin >> v >> l >> k;
      que[v].push_back((QUE){l, k, i});
    }
    dfs(1);
    for (int i = 1; i <= q; ++i) cout << ans[i] << " ";
    cout << "\n";
  }
}
