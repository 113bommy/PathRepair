#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int n, k, q;
int a[maxn];
int lg2[maxn];
int mn[maxn][20];
void RMQ_init() {
  lg2[1] = 0;
  for (int i = 2; i <= n; i++) {
    if ((i & (i - 1)) == 0)
      lg2[i] = lg2[i - 1] + 1;
    else
      lg2[i] = lg2[i - 1];
  }
  for (int i = 1; i <= n; i++) mn[i][0] = a[i];
  for (int i = 1; i <= lg2[n]; i++) {
    for (int j = 1; j + (1 << i) - 1 <= n; j++) {
      mn[j][i] = min(mn[j][i - 1], mn[j + (1 << (i - 1))][i - 1]);
    }
  }
}
int ask(int l, int r) {
  int k = lg2[r - l + 1];
  return min(mn[l][k], mn[r - (1 << k) + 1][k]);
}
int ls[maxn * 40], rs[maxn * 40], v[maxn * 40], cnt, root;
int lazy[maxn * 40];
int getmn(int l, int r) {
  if (r - l + 1 >= n) return ask(1, n);
  l = (l - 1) % n + 1;
  r = (r - 1) % n + 1;
  if (l <= r) return ask(l, r);
  return min(ask(1, r), ask(l, n));
}
int newnode(int l, int r) {
  ++cnt;
  ls[cnt] = rs[cnt] = 0;
  lazy[cnt] = -1;
  v[cnt] = getmn(l, r);
  return cnt;
}
void push_down(int x) {
  if (!ls[x]) ls[x] = newnode(1, 1);
  if (!rs[x]) rs[x] = newnode(1, 1);
  v[ls[x]] = v[rs[x]] = lazy[x];
  lazy[ls[x]] = lazy[rs[x]] = lazy[x];
  lazy[x] = -1;
}
void modify(int &x, int L, int R, int l, int r, int c) {
  if (!x) x = newnode(L, R);
  if (l <= L && R <= r) {
    lazy[x] = v[x] = c;
    return;
  }
  if (lazy[x] != -1) {
    push_down(x);
  }
  int mid = (L + R) >> 1;
  if (l <= mid) modify(ls[x], L, mid, l, r, c);
  if (r > mid) modify(rs[x], mid + 1, R, l, r, c);
  v[x] = inf;
  if (ls[x])
    v[x] = min(v[x], v[ls[x]]);
  else
    v[x] = min(v[x], getmn(L, mid));
  if (rs[x])
    v[x] = min(v[x], v[rs[x]]);
  else
    v[x] = min(v[x], getmn(mid + 1, R));
}
int qry(int &x, int L, int R, int l, int r) {
  if (!x) x = newnode(L, R);
  if (l <= L && R <= r) return v[x];
  if (lazy[x] != -1) push_down(x);
  int mid = (L + R) >> 1;
  int ans = inf;
  if (l <= mid) ans = min(ans, qry(ls[x], L, mid, l, r));
  if (r > mid) ans = min(ans, qry(rs[x], mid + 1, R, l, r));
  return ans;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  root = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  RMQ_init();
  cin >> q;
  while (q--) {
    int op, l, r, x;
    cin >> op >> l >> r;
    if (op == 1) {
      cin >> x;
      modify(root, 1, k * n, l, r, x);
    } else {
      cout << qry(root, 1, k * n, l, r) << endl;
    }
  }
  return 0;
}
