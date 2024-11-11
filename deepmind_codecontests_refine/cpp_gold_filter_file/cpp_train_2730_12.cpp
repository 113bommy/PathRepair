#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int N = 1000006;
int trie[N][30];
bool good[N];
int ans[N];
int st[4 * N], lazy[4 * N];
void prop(int p, int l, int r) {
  if (lazy[p]) {
    st[p] += lazy[p];
    if (l != r) {
      lazy[2 * p] += lazy[p];
      lazy[2 * p + 1] += lazy[p];
    }
    lazy[p] = 0;
  }
}
void upd(int p, int l, int r, int ql, int qr, int val) {
  prop(p, l, r);
  if (l > qr || r < ql) return;
  if (l >= ql && r <= qr) {
    lazy[p] += val;
    prop(p, l, r);
    return;
  }
  int mid = (l + r) / 2;
  upd(2 * p, l, mid, ql, qr, val);
  upd(2 * p + 1, mid + 1, r, ql, qr, val);
  st[p] = min(st[2 * p], st[2 * p + 1]);
}
void upd2(int p, int l, int r, int ql, int qr, int val) {
  prop(p, l, r);
  if (l > qr || r < ql) return;
  if (l == ql && r == qr) {
    st[p] = val;
    return;
  }
  int mid = (l + r) / 2;
  upd2(2 * p, l, mid, ql, qr, val);
  upd2(2 * p + 1, mid + 1, r, ql, qr, val);
  st[p] = min(st[2 * p], st[2 * p + 1]);
}
int qry(int p, int l, int r, int ql, int qr) {
  prop(p, l, r);
  if (l > qr || r < ql) return N;
  if (l >= ql && r <= qr) {
    return st[p];
  }
  int mid = (l + r) / 2;
  return min(qry(2 * p, l, mid, ql, qr), qry(2 * p + 1, mid + 1, r, ql, qr));
}
void upd(int l, int r, int val) { upd(1, 0, N - 1, l, r, val); }
void upd2(int l, int r, int val) { upd2(1, 0, N - 1, l, r, val); }
int qry(int l, int r) { return qry(1, 0, N - 1, l, r); }
void dfs(int x) {
  upd2(x, x, 0);
  if (good[x]) {
    ans[x] = min(ans[x], qry(0, x - 1));
    upd(0, x, 1);
  }
  upd(x, x, ans[x] + 1);
  for (int i = 0; i < 30; i++) {
    if (trie[x][i]) {
      ans[trie[x][i]] = ans[x] + 1;
      dfs(trie[x][i]);
    }
  }
  upd(x, x, N);
}
int main() {
  upd(0, N - 1, N);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    char c;
    scanf("%d %c", &x, &c);
    c -= 'a';
    trie[x][c] = i + 1;
  }
  int k;
  int v[N];
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    scanf("%d", v + i);
    good[v[i]] = 1;
  }
  ans[0] = 0;
  dfs(0);
  for (int i = 0; i < k; i++) {
    printf("%d ", ans[v[i]]);
  }
  printf("\n");
}
