#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 100;
const int base = 1e9 + 9;
pair<int, int> lz[maxn << 2];
int st[maxn << 2];
int a[maxn], f[maxn], n;
void add(int &x, int v) {
  x += v;
  if (x >= base) x -= base;
}
int Fibo(int x, int a = 1, int b = 1) {
  return (1ll * f[x - 2] * a + 1ll * f[x - 1] * b) % base;
}
int sumFibo(int x, int a = 1, int b = 1) {
  return (Fibo(x + 2, a, b) - b + base) % base;
}
void down(int id, int l, int r) {
  if (lz[id] == make_pair(0, 0)) return;
  int &a = lz[id].first, &b = lz[id].second;
  int mid = (l + r) >> 1;
  add(lz[id << 1].first, a);
  add(lz[id << 1].second, b);
  add(st[id << 1], sumFibo(mid - l + 1, a, b));
  int aa = Fibo(mid + 1 - l + 1, a, b), bb = Fibo(mid + 1 - l + 2, a, b);
  add(lz[id << 1 | 1].first, aa);
  add(lz[id << 1 | 1].second, bb);
  add(st[id << 1 | 1], sumFibo(r - mid, aa, bb));
  a = b = 0;
}
void Update(int id, int l, int r, int u, int v) {
  if (l > v || r < u) return;
  if (u <= l && r <= v) {
    add(lz[id].first, f[l - u + 1]);
    add(lz[id].second, f[l - u + 2]);
    st[id] += sumFibo(r - u + 1) - sumFibo(l - u);
    st[id] %= base;
    if (st[id] < 0) st[id] += base;
    return;
  }
  down(id, l, r);
  int mid = (l + r) >> 1;
  Update(id << 1, l, mid, u, v);
  Update(id << 1 | 1, mid + 1, r, u, v);
  st[id] = (st[id << 1] + st[id << 1 | 1]) % base;
}
int Get(int id, int l, int r, int u, int v) {
  if (l > v || r < u) return 0;
  if (u <= l && r <= v) return st[id];
  down(id, l, r);
  int mid = (l + r) >> 1;
  return (Get(id << 1, l, mid, u, v) + Get(id << 1 | 1, mid + 1, r, u, v)) %
         base;
}
void build(int id, int l, int r) {
  if (l == r) {
    st[id] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid + 1, r);
  st[id] = (st[id << 1] + st[id << 1 | 1]) % base;
}
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  int m;
  cin >> n >> m;
  for (int i = (1); i <= (n); ++i) cin >> a[i];
  f[1] = f[2] = 1;
  for (int i = (3); i <= (n + 10); ++i) {
    f[i] = f[i - 1];
    add(f[i], f[i - 2]);
  }
  build(1, 1, n);
  for (int i = (1); i <= (m); ++i) {
    int typ, l, r;
    cin >> typ >> l >> r;
    if (typ == 1) {
      Update(1, 1, n, l, r);
    } else
      cout << Get(1, 1, n, l, r) << '\n';
  }
  return 0;
}
