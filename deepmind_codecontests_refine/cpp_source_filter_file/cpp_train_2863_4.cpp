#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int mod = 1e9 + 3;
int f[maxn], a[maxn], h[maxn];
char s[maxn];
void Init() {
  f[0] = 1;
  for (int i = 1; i <= maxn - 1; i++) f[i] = 1ll * f[i - 1] * 10 % mod;
  h[1] = 1;
  for (int i = 1; i <= maxn - 1; i++) h[i] = (h[i - 1] * 10ll + 1) % mod;
}
class Nd {
 public:
  int l, r, v;
  long long sum;
  Nd() {}
  Nd(int l, int r, int v, int s) : l(l), r(r), v(v), sum(s) {}
};
Nd nd[maxn * 4];
class Tree {
 public:
  void Build(int o, int l, int r) {
    if (l == r) {
      nd[o] = Nd(l, r, a[l], a[l]);
      return;
    }
    int mid = (l + r) >> 1;
    Build(o << 1, l, mid);
    Build((o << 1) | 1, mid + 1, r);
    nd[o] =
        Nd(l, r, -1,
           (nd[o << 1].sum * f[r - mid] % mod + nd[(o << 1) | 1].sum) % mod);
  }
  void Pushdown(int o) {
    if (nd[o].v != -1) {
      nd[o << 1].v = nd[o << 1 | 1].v = nd[o].v;
      int mid = (nd[o].l + nd[o].r) >> 1;
      nd[o << 1].sum = 1ll * nd[o].v * h[mid - nd[o].l + 1] % mod;
      nd[o << 1 | 1].sum = 1ll * nd[o].v * h[nd[o].r - mid] % mod;
      nd[o].v = -1;
    }
  }
  void Update(int o, int l, int r, int v) {
    if (nd[o].l >= l && nd[o].r <= r) {
      nd[o].v = v;
      nd[o].sum = (1ll * v * h[nd[o].r - nd[o].l + 1]) % mod;
      return;
    }
    int mid = (nd[o].l + nd[o].r) >> 1;
    Pushdown(o);
    if (l <= mid) Update(o << 1, l, r, v);
    if (r > mid) Update(o << 1 | 1, l, r, v);
    nd[o].v = -1,
    nd[o].sum =
        (nd[o << 1].sum * f[(nd[o].r - mid)] % mod + nd[o << 1 | 1].sum) % mod;
  }
  int Query(int o, int l, int r) {
    if (nd[o].l >= l && nd[o].r <= r) return nd[o].sum * f[r - nd[o].r] % mod;
    int mid = (nd[o].l + nd[o].r) >> 1;
    Pushdown(o);
    int ans = 0;
    if (l <= mid) ans = (ans + Query(o << 1, l, r)) % mod;
    if (r > mid) ans = (ans + Query(o << 1 | 1, l, r)) % mod;
    return ans;
  }
};
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  scanf("%s", s);
  for (int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
  int o = m + k, c, l, r, d;
  Init();
  Tree tree;
  tree.Build(1, 1, n);
  while (o--) {
    scanf("%d%d%d%d", &c, &l, &r, &d);
    if (c == 1) {
      tree.Update(1, l, r, d);
    } else {
      printf(
          "%s\n",
          (tree.Query(1, l, r - d) == tree.Query(1, l + d, r) ? "YES" : "NO"));
    }
  }
  return 0;
}
