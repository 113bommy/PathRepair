#include <bits/stdc++.h>
using namespace std;
const int maxn = 200020;
int n, m, q;
long long A[maxn], B[maxn], C[maxn];
struct edge {
  int a, b;
  long long w;
  bool operator<(const edge &x) const { return a < x.a; }
} e[maxn];
long long tr[maxn << 2], lz[maxn << 2];
void push_up(int o) { tr[o] = min(tr[o << 1], tr[o << 1 | 1]); }
void push_down(int o) {
  if (lz[o]) {
    tr[o << 1] += lz[o];
    tr[o << 1 | 1] += lz[o];
    lz[o << 1] += lz[o];
    lz[o << 1 | 1] += lz[o];
    lz[o] = 0;
  }
}
void build(int o, int l, int r) {
  lz[o] = 0;
  if (l == r) {
    tr[o] = C[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(o << 1, l, mid);
  build(o << 1 | 1, mid + 1, r);
  push_up(o);
}
void update(int o, int l, int r, int kl, int kr, long long x) {
  if (kl == l && kr == r) {
    tr[o] += x;
    lz[o] += x;
    return;
  }
  push_down(o);
  int mid = (l + r) >> 1;
  if (kr <= mid)
    update(o << 1, l, mid, kl, kr, x);
  else if (kl > mid)
    update(o << 1 | 1, mid + 1, r, kl, kr, x);
  else {
    update(o << 1, l, mid, kl, mid, x);
    update(o << 1 | 1, mid + 1, r, mid + 1, kr, x);
  }
  push_up(o);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i < n; i++) cin >> A[i] >> B[i], C[i] = B[i];
  for (int i = 1; i <= m; i++) cin >> e[i].a >> e[i].b >> e[i].w;
  sort(e + 1, e + 1 + m);
  build(1, 0, n - 1);
  for (int i = 1, j = 1; i <= n; i++) {
    while (j <= m && e[j].a <= i)
      update(1, 0, n - 1, 0, e[j].b - 1, e[j].w), j++;
    C[i] = A[i] + tr[1];
  }
  build(1, 1, n);
  cout << tr[1] << "\n";
  while (q--) {
    int g, h;
    cin >> g >> h;
    update(1, 1, n, g, g, h);
    A[g] = h;
    cout << tr[1] << "\n";
  }
}
