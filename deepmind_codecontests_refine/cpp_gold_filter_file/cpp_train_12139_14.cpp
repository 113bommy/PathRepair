#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int n, k, q, ans = 0;
vector<int> pos[N];
int tot = 0, rt[N], ls[N * 50], rs[N * 50], sum[N * 50];
void insert(int &o, int l, int r, int x, int p, int v) {
  o = ++tot;
  ls[o] = ls[x];
  rs[o] = rs[x];
  sum[o] = sum[x] + v;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (p <= mid)
    insert(ls[o], l, mid, ls[x], p, v);
  else
    insert(rs[o], mid + 1, r, rs[x], p, v);
}
int query(int s, int t, int l, int r, int L, int R) {
  if (L <= l && r <= R) return sum[t] - sum[s];
  int mid = (l + r) >> 1, ret = 0;
  if (L <= mid) ret += query(ls[s], ls[t], l, mid, L, R);
  if (R > mid) ret += query(rs[s], rs[t], mid + 1, r, L, R);
  return ret;
}
int main() {
  cin >> n >> k;
  for (int i = 1, x; i <= n; i++) {
    x = gi();
    pos[x].push_back(i);
    if ((int)pos[x].size() - k > 0)
      insert(rt[i], 0, n, rt[i - 1], pos[x][pos[x].size() - k - 1], 1);
    else
      insert(rt[i], 0, n, rt[i - 1], 0, 1);
  }
  cin >> q;
  while (q--) {
    int l = (gi() + ans) % n + 1, r = (gi() + ans) % n + 1;
    if (l > r) swap(l, r);
    printf("%d\n", ans = query(rt[l - 1], rt[r], 0, n, 0, l - 1));
  }
  return 0;
}
