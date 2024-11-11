#include <bits/stdc++.h>
using namespace std;
const int N = 201000;
int c[2][N], fa[N], rev[N];
bool it(int o) { return c[0][fa[o]] != o && c[1][fa[o]] != o; }
void pd(int o) {
  if (rev[o]) {
    swap(c[0][o], c[1][o]);
    rev[c[0][o]] ^= 1;
    rev[c[1][o]] ^= 1;
    rev[o] = 0;
  }
}
void rot(int o) {
  int x = fa[o], k = c[0][x] == o;
  fa[c[!k][x] = c[k][o]] = x;
  fa[o] = fa[x];
  if (!it(x)) c[c[1][fa[x]] == x][fa[x]] = o;
  fa[c[k][o] = x] = o;
}
void down(int o) {
  if (!it(o)) down(fa[o]);
  pd(o);
}
void sy(int o) {
  for (down(o); !it(o); rot(o))
    if (!it(fa[o]))
      rot(c[0][fa[o]] == o ^ c[0][fa[fa[o]]] == fa[o] ? o : fa[o]);
}
void acs(int o) {
  for (int y = 0; o; c[1][o] = y, y = o, o = fa[o]) sy(o);
}
void mt(int o) {
  acs(o);
  sy(o);
  rev[o] ^= 1;
}
int fd(int o) {
  acs(o);
  sy(o);
  for (pd(o); c[0][o]; pd(o = c[0][o]))
    ;
  sy(o);
  return o;
}
void cut(int x, int y) {
  mt(y);
  acs(x);
  sy(x);
  fa[y] = c[0][x] = 0;
}
int mn[N * 4], tag[N * 4], mn_cnt[N * 4];
void bt(int o, int l, int r) {
  mn[o] = tag[o] = 0;
  mn_cnt[o] = r - l + 1;
  if (l == r) return;
  int mid = (l + r) / 2;
  bt(o * 2, l, mid);
  bt(o * 2 + 1, mid + 1, r);
}
int q1, q2;
long long ans;
void query(int o, int l, int r, int tg = 0) {
  if (q1 <= l && r <= q2) {
    if (mn[o] + tg == 0) ans += mn_cnt[o];
    return;
  }
  int mid = (l + r) / 2;
  tg += tag[o];
  if (q1 <= mid) query(o * 2, l, mid, tg);
  if (q2 > mid) query(o * 2 + 1, mid + 1, r, tg);
}
void modify(int o, int l, int r) {
  if (q1 <= l) {
    tag[o] += q2;
    mn[o] += q2;
    return;
  }
  int mid = (l + r) / 2;
  if (q1 <= mid) modify(o * 2, l, mid);
  modify(o * 2 + 1, mid + 1, r);
  mn[o] = min(mn[o * 2], mn[o * 2 + 1]);
  mn_cnt[o] = (mn[o] == mn[o * 2] ? mn_cnt[o * 2] : 0) +
              (mn[o] == mn[o * 2 + 1] ? mn_cnt[o * 2 + 1] : 0);
  mn[o] += tag[o];
}
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}, M = 1234;
int idx[N], idy[N], a[M][M];
int n, m, K, L, R;
bool push(int x, int op) {
  int u = idx[x], v = idy[x], nu = u + dx[op], nv = v + dy[op];
  if (nu < 1 || nu > n || nv < 1 || nv > m || a[nu][nv] < L || a[nu][nv] > R)
    return 1;
  int y = a[nu][nv];
  mt(y);
  if (fd(x) == y) return 0;
  fa[y] = x;
  q1 = max(x, y);
  q2 = -1;
  modify(1, 1, K);
  return 1;
}
void pop(int t) {
  for (int op = 0; op < 4; ++op) {
    int u = idx[R], v = idy[R], nu = u + dx[op], nv = v + dy[op];
    if (nu < 1 || nu > n || nv < 1 || nv > m ||
        (a[nu][nv] < L || (a[nu][nv] == L && op >= t)) || a[nu][nv] > R)
      continue;
    int y = a[nu][nv];
    cut(y, R);
    q1 = max(R, y);
    q2 = 1;
    modify(1, 1, K);
  }
  --R;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  K = n * m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> a[i][j], idx[a[i][j]] = i, idy[a[i][j]] = j;
  bt(1, 1, K);
  for (L = R = K; L; --L) {
    for (int i = 0; i < 4; ++i)
      for (; !push(L, i); pop(i))
        ;
    q1 = L;
    q2 = R;
    query(1, 1, K);
    q1 = L;
    q2 = 1;
    modify(1, 1, K);
  }
  cout << ans << '\n';
  return 0;
}
