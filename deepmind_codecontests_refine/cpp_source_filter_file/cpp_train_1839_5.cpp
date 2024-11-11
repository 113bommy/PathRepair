#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int die = 0;
const double eps = 1e-9;
long long mod = 1e9 + 7;
const int N = 1e7 + 5;
int n, m;
int tot = 0;
int ans = 0;
int tree[N], Lson[N], Rson[N];
int Root[N];
int qry(int ql, int qr, int l, int r, int p) {
  if (l > qr || ql > r) return 0;
  if (ql <= l && r <= qr) return tree[p];
  return max(qry(ql, qr, l, ((l + ((r - l) / 2))), Lson[p]),
             qry(ql, qr, ((l + ((r - l) / 2))) + 1, r, Rson[p]));
}
void upd(int x, int d, int l, int r, int p) {
  if (l == r) {
    tree[p] = max(tree[p], d);
    return;
  }
  if (x <= ((l + ((r - l) / 2))))
    upd(x, d, l, ((l + ((r - l) / 2))), Lson[p] ? Lson[p] : Lson[p] = ++tot);
  else
    upd(x, d, ((l + ((r - l) / 2))) + 1, r,
        Rson[p] ? Rson[p] : Rson[p] = ++tot);
  tree[p] = max(tree[Lson[p]], tree[Rson[p]]);
}
signed main() {
  n = read(), m = read();
  for (int i = (1); i <= (m); i++) {
    int u, v, w;
    u = read(), v = read(), w = read();
    int ret = 0;
    if (w) ret = qry(0, w - 1, 0, 1e5, Root[u]) + 1;
    Root[v] = Root[v] ? Root[v] : ++tot;
    upd(w, ret, 0, 1e5, Root[v]);
    ans = max(ans, ret);
  }
  cout << ans;
}
