#include <bits/stdc++.h>
using namespace std;
struct Treap {
  int val, rnd, ls, rs, size;
  Treap() {
    val = ls = rs = 0;
    size = 0;
    rnd = rand();
  }
} t[1000005];
void update(int x) { t[x].size = t[t[x].ls].size + t[t[x].rs].size + 1; }
int merge(int x, int y) {
  if (!x || !y) return x + y;
  int root;
  if (t[x].rnd <= t[y].rnd) {
    root = x;
    t[x].rs = merge(t[x].rs, y);
  } else {
    root = y;
    t[y].ls = merge(x, t[y].ls);
  }
  update(root);
  return root;
}
void split(int root, int &L, int &R, int rank) {
  if (!root) {
    L = R = 0;
    return;
  }
  if (t[root].size < rank) exit(1);
  if (t[t[root].ls].size >= rank) {
    R = root;
    split(t[root].ls, L, t[root].ls, rank);
  } else {
    L = root;
    split(t[root].rs, t[root].rs, R, rank - t[t[root].ls].size - 1);
  }
  update(root);
}
int n, m, root = 1;
int num[1000005], pos[1000005], ans[1000005], tot, nxt = 1;
bool cnt[1000005], mark[1000005];
void getans(int x) {
  if (!x) return;
  getans(t[x].ls);
  ans[++tot] = t[x].val;
  cnt[t[x].val] = 1;
  getans(t[x].rs);
}
int main() {
  srand(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) t[i].size = 1;
  for (int i = 2; i <= n; i++) root = merge(root, i);
  int l, mid, r;
  for (int i = 1; i <= m; i++) scanf("%d%d", &num[i], &pos[i]);
  for (int i = m; i >= 1; i--) {
    split(root, l, mid, 1);
    split(mid, mid, r, pos[i] - 1);
    if ((t[l].val || mark[num[i]]) && t[l].val != num[i]) {
      cout << -1;
      return 0;
    }
    t[l].val = num[i];
    mark[num[i]] = 1;
    root = merge(merge(mid, l), r);
  }
  getans(root);
  for (int i = 1; i <= n; i++)
    if (!ans[i]) {
      while (cnt[nxt]) nxt++;
      ans[i] = nxt;
      cnt[nxt] = 1;
    }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
