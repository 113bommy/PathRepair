#include <bits/stdc++.h>
using namespace std;
const int msc = (int)2e5;
int l[msc], r[msc], f[msc][2], g[msc];
int root, sz[msc], a[msc], b[msc], n, Q, K;
void update(int x) {
  int lk = l[x], rk = r[x];
  f[x][0] = max(g[lk], g[rk]);
  f[x][1] = max((f[lk][0] + 1 + g[rk]) * (lk != 0),
                (f[rk][0] + 1 + g[lk]) * (rk != 0));
  g[x] = max(f[x][1], f[x][0]);
  sz[x] = sz[l[x]] + sz[r[x]] + 1;
}
int build(int L, int R) {
  if (L > R) return 0;
  int x = L;
  for (int i = L; i <= R; i++)
    if (b[i] > b[x]) x = i;
  l[x] = build(L, x - 1);
  r[x] = build(x + 1, R);
  update(x);
  return x;
}
struct kid {
  int x, y;
  kid(int x = 0, int y = 0) : x(x), y(y) {}
} e[msc];
bool cmp(const kid& a, const kid& b) { return a.x < b.x; }
int merge(int x, int y) {
  if (!x || !y) return update(x + y), x + y;
  int t;
  if (b[x] > b[y])
    r[t = x] = merge(r[x], y);
  else
    l[t = y] = merge(x, l[y]);
  return update(t), t;
}
kid split(int x, int k) {
  if (!k) return kid(0, x);
  int cnt = k - sz[l[x]] - 1;
  if (cnt >= 0) {
    kid s = split(r[x], cnt);
    r[x] = s.x;
    update(x);
    return kid(x, s.y);
  } else {
    kid s = split(l[x], k);
    l[x] = s.y;
    update(x);
    return kid(s.x, x);
  }
}
int find(int x) {
  int l = 1, r = n, mid;
  while (l < r) {
    mid = (l + r) >> 1;
    if (a[mid] >= x)
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}
const int mo = (int)1e9 + 9;
int A, B, C, D;
int main() {
  cin >> n >> K;
  for (int i = 1; i <= K; i++) cin >> e[i].x >> e[i].y;
  cin >> A >> B >> C >> D;
  for (int i = K + 1; i <= n; i++)
    e[i].x = (1LL * A * e[i - 1].x + B) % mo,
    e[i].y = (1LL * C * e[i - 1].y + D) % mo;
  sort(e + 1, e + n + 1, cmp);
  for (int i = 1; i <= n; i++) a[i] = e[i].x, b[i] = e[i].y;
  root = build(1, n);
  cin >> Q;
  int L, R;
  for (; Q; Q--) {
    scanf("%d %d", &L, &R);
    int ls = find(L), rs = find(R);
    if (a[rs] > R) rs--;
    if (ls > rs) {
      puts("0");
      continue;
    }
    kid s = split(root, rs);
    kid t = split(s.x, ls - 1);
    printf("%d\n", g[t.y]);
    s.x = merge(t.x, t.y);
    root = merge(s.x, s.y);
  }
  return 0;
}
