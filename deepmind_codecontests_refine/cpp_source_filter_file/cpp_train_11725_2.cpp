#include <bits/stdc++.h>
using namespace std;
int l[200010], r[200010], dfs_clock;
int one[200010 * 4], ql, qr, tag[200010 * 4];
vector<int> G[200010];
void pushdown(int l, int r, int o) {
  int mid = l + (r - l) / 2;
  int lc = o * 2, rc = o * 2 + 1;
  if (tag[o]) {
    tag[o] = 0;
    tag[lc] ^= 1;
    tag[rc] ^= 1;
    one[lc] = mid - l + 1 - one[lc];
    one[rc] = r - mid - one[rc];
  }
}
void update(int l, int r, int o) {
  if (ql <= l && qr >= r) {
    one[o] = r - l + 1 - one[o];
    tag[o] ^= 1;
    return;
  }
  pushdown(l, r, o);
  int mid = l + (r - l) / 2;
  if (ql <= mid) update(l, mid, o * 2);
  if (qr > mid) update(mid + 1, r, o * 2 + 1);
  one[o] = one[o * 2] + one[o * 2 + 1];
}
int query(int l, int r, int o) {
  if (ql <= l && qr >= r) {
    return one[o];
  }
  pushdown(l, r, o);
  int mid = l + (r - l) / 2, sum = 0;
  if (ql <= mid) sum += query(l, mid, o * 2);
  if (qr > mid) sum += query(mid + 1, r, o * 2 + 1);
  return sum;
}
void dfs(int u) {
  l[u] = ++dfs_clock;
  for (int i = 0; i < G[u].size(); i++) {
    dfs(G[u][i]);
  }
  r[u] = dfs_clock;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int fa;
    scanf("%d", &fa);
    G[fa].push_back(i);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      ql = qr = i;
      update(1, n, 1);
    }
  }
  int m;
  scanf("%d", &m);
  while (m--) {
    char s[10];
    int x;
    scanf(" %s %d", s, &x);
    if (s[0] == 'g') {
      ql = l[x], qr = r[x];
      printf("%d\n", query(1, n, 1));
    } else {
      ql = l[x], qr = r[x];
      update(1, n, 1);
    }
  }
  return 0;
}
