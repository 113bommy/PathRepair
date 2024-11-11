#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
long long t[maxn << 2], tag[maxn << 2];
void pushup(int o) { t[o] = min(t[o << 1], t[(o << 1) | 1]); }
void pushdown(int o, int l, int r) {
  if (tag[o]) {
    tag[o << 1] += tag[o];
    tag[o << 1 | 1] += tag[o];
    int m = l + r >> 1;
    t[o << 1] += tag[o];
    t[o << 1 | 1] += tag[o];
    tag[o] = 0;
  }
}
void build(int o, int l, int r) {
  if (l == r) {
    t[o] = 0;
    return;
  }
  int mid = l + r >> 1;
  build(o << 1, mid + 1, r);
  build(o << 1 | 1, l, mid);
  pushup(o);
}
void update(int o, int l, int r, int ql, int qr, int v) {
  if (l >= ql && r <= qr) {
    tag[o] += v;
    t[o] += v;
    return;
  }
  pushdown(o, l, r);
  int mid = l + r >> 1;
  if (ql <= mid) update(o << 1, l, mid, ql, qr, v);
  if (qr >= mid + 1) update(o << 1 | 1, mid + 1, r, ql, qr, v);
  pushup(o);
}
long long query(int o, int l, int r, int ql, int qr) {
  if (l >= ql && r <= qr) return t[o];
  pushdown(o, l, r);
  int mid = l + r >> 1;
  long long ans = 0x3f3f3f3f3f3f3f3f;
  if (ql <= mid) ans = min(ans, query(o << 1, l, mid, ql, qr));
  if (qr >= mid + 1) ans = min(ans, query(o << 1 | 1, mid + 1, r, ql, qr));
  return ans;
}
int n;
int p[maxn], pos[maxn];
long long a[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i], pos[p[i]] = i;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) update(1, 0, n, i, n, a[i]);
  long long ans = query(1, 0, n, 1, n - 1);
  for (int val = 2; val <= n + 1; val++) {
    int pp = pos[val - 1];
    update(1, 0, n, pp, n, -a[pp]);
    update(1, 0, n, 0, pp - 1, a[pp]);
    ans = min(ans, query(1, 0, n, 1, n - 1));
  }
  cout << ans << endl;
}
