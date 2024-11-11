#include <bits/stdc++.h>
using namespace std;
const int N = 2055, mod = (int)1e9 + 7;
template <class o>
void qr(o &x) {
  char c = getchar();
  x = 0;
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
}
int n, m, L, last[N], ys[N], tot, vis[N], col[N];
struct P {
  int x, y, c, i;
} a[N];
bool cmpx(P a, P b) { return a.x < b.x; }
bool cmpy(P a, P b) { return a.y < b.y; }
struct Q {
  int l[N], r[N];
  void del(int x) {
    l[r[x]] = l[x];
    r[l[x]] = r[x];
  }
} q, nq;
struct node {
  int mn, mx, s, tag;
  node(int a = 0, int b = 0, int c = 0, int d = 0) {
    mn = a;
    mx = b;
    s = c;
    tag = d;
  }
  node operator+(node b) const {
    return node(min(mn, b.mn), max(mx, b.mx), (s + b.s) % mod, 0);
  }
} tr[N * 2];
int f[N];
void bt(int x, int l, int r) {
  if (l == r) {
    tr[x] = node(f[l], f[l], 1LL * (ys[r] - ys[l - 1]) * f[l], 0);
    return;
  }
  int mid = (l + r) / 2;
  bt((x << 1), l, mid);
  bt((x << 1 | 1), mid + 1, r);
  tr[x] = tr[(x << 1)] + tr[(x << 1 | 1)];
}
void upd(int x, int l, int r, long long t) {
  tr[x] = node(t, t, t * (ys[r] - ys[l - 1]) % mod, t);
}
void change(int x, int l, int r, int L, long long t) {
  if (tr[x].mn >= t) return;
  if (tr[x].mx <= t && l == L) {
    upd(x, l, r, t);
    return;
  }
  int mid = (l + r) / 2;
  if (tr[x].tag) {
    upd((x << 1), l, mid, tr[x].tag);
    upd((x << 1 | 1), mid + 1, r, tr[x].tag);
    tr[x].tag = 0;
  }
  if (L <= mid) change((x << 1), l, mid, L, t);
  change((x << 1 | 1), mid + 1, r, max(mid + 1, L), t);
  tr[x] = tr[(x << 1)] + tr[(x << 1 | 1)];
}
int main() {
  qr(n);
  qr(m);
  qr(L);
  for (int i = 1; i <= n; i++) qr(a[i].x), qr(a[i].y), qr(a[i].c);
  sort(a + 1, a + n + 1, cmpy);
  a[0].x = a[0].y = -1;
  a[n + 1].x = a[n + 1].y = L;
  for (int i = 0; i <= n + 1; i++) ys[i] = a[i].y, a[i].i = i;
  for (int i = 1; i <= n; i++) {
    int l = nq.l[i] = last[a[i].c];
    last[a[i].c] = i;
    nq.r[i] = n + 1;
    nq.r[l] = i;
  }
  sort(a + 1, a + n + 1, cmpx);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].x ^ a[i - 1].x) {
      q = nq;
      for (int j = 1; j < i; j++) col[a[j].i] = 0;
      for (int j = i; j <= n; j++) col[a[j].i] = a[j].c;
      for (int l = 1, r = 1; l <= n; l++) {
        for (; r <= n && tot < m; r++)
          if (col[r] && !vis[col[r]]++) tot++;
        f[l] = (tot < m) ? L : ys[r - 1];
        if (col[l] && !--vis[col[l]]) tot--;
      }
      bt(1, 1, n);
      for (int j = n; j >= i; j--) {
        ans += (1LL * (ys[n] + 1) * L - tr[1].s) % mod * (a[i].x - a[i - 1].x) %
               mod * (a[j + 1].x - a[j].x) % mod;
        int id = a[j].i, L = q.l[id], R = q.r[id];
        change(1, 1, n, L + 1, ys[R]);
        q.del(id);
      }
      ans %= mod;
    }
    nq.del(a[i].i);
  }
  cout << ans << endl;
  return 0;
}
