#include <bits/stdc++.h>
using namespace std;
int mn[1200005];
void update(int pos, int val, int l, int r, int rt) {
  if (l == r) {
    mn[rt] = val;
    return;
  }
  int m = (l + r) / 2;
  if (pos <= m)
    update(pos, val, l, m, rt << 1);
  else
    update(pos, val, m + 1, r, rt << 1 | 1);
  mn[rt] = min(mn[rt << 1], mn[rt << 1 | 1]);
}
int query(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) return mn[rt];
  int m = (l + r) / 2;
  int ret = 1e9;
  if (L <= m) ret = min(ret, query(L, R, l, m, rt << 1));
  if (m < R) ret = min(ret, query(L, R, m + 1, r, rt << 1 | 1));
  return ret;
}
int a[300005], b[300005], aa[300005], bb[300005];
queue<int> q[300005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], aa[i] = a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i], bb[i] = b[i];
    sort(aa + 1, aa + 1 + n);
    sort(bb + 1, bb + 1 + n);
    int ok1 = 0;
    for (int i = 1; i <= n; ++i)
      if (aa[i] != bb[i]) {
        ok1 = 1;
        break;
      }
    if (ok1) {
      cout << "NO" << endl;
      continue;
    }
    for (int i = 1; i <= n; ++i)
      while (!q[a[i]].empty()) q[a[i]].pop();
    for (int i = 1; i <= n; ++i) update(i, a[i], 1, n, 1);
    for (int i = 1; i <= n; ++i) q[a[i]].push(i);
    int ok = 1;
    for (int i = 1; i <= n; ++i) {
      if (q[b[i]].empty()) {
        ok = 0;
        break;
      }
      int m = query(1, q[b[i]].front(), 1, n, 1);
      if (m != b[i]) {
        ok = 0;
        break;
      }
      update(q[b[i]].front(), 1e9, 1, n, 1);
      q[b[i]].pop();
    }
    if (ok)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
