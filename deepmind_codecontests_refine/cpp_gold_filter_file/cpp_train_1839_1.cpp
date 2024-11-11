#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int E = 40;
int n, m;
struct NODE {
  int ls, rs, val;
} nd[N * E];
int root[N], cnt, ans;
void chkMax(int &x, int y) {
  if (x < y) x = y;
}
int new_node() {
  nd[++cnt] = (NODE){0, 0, 0};
  return cnt;
}
void Insert(int &now, int l, int r, int k, int val) {
  if (now == 0) now = new_node();
  chkMax(nd[now].val, val);
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (k <= mid)
    Insert(nd[now].ls, l, mid, k, val);
  else
    Insert(nd[now].rs, mid + 1, r, k, val);
}
int Query(int now, int l, int r, int k) {
  if (now == 0 || k < l) return 0;
  if (l == r || k > r) return nd[now].val;
  int mid = (l + r) >> 1, ret = 0;
  chkMax(ret, Query(nd[now].ls, l, mid, k));
  chkMax(ret, Query(nd[now].rs, mid + 1, r, k));
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  cnt = 0;
  for (int i = 1; i <= n; ++i) Insert(root[i], 0, N - 1, 0, 0);
  ans = 0;
  for (int i = 1; i <= m; ++i) {
    int a, b, w, f;
    scanf("%d%d%d", &a, &b, &w);
    f = Query(root[a], 0, N - 1, w);
    ans = max(ans, f + 1);
    Insert(root[b], 0, N - 1, w, f + 1);
  }
  printf("%d\n", ans);
  return 0;
}
