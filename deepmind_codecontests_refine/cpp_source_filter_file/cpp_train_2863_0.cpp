#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 2;
const int mod = (int)1e9 + 7;
const long long inf = (long long)2e9;
const int base = 47;
long long pow_base[maxn];
long long pow_4747[maxn];
int n, m, k;
string s;
struct node {
  long long val, lazy, sz;
};
node IT[4 * maxn];
long long comb(node L, node R) {
  return (L.val * pow_base[R.sz] % mod + R.val) % mod;
}
void set_up(int x, int value) {
  IT[x].val = (pow_4747[IT[x].sz] * (value + 1)) % mod;
  IT[x].lazy = value;
}
void lazy_prop(int k) {
  if (IT[k].lazy == -1) return;
  set_up(2 * k, IT[k].lazy);
  set_up(2 * k + 1, IT[k].lazy);
  IT[k].lazy = -1;
}
void build(int k, int l, int r) {
  if (l > r) return;
  IT[k].sz = r - l + 1;
  IT[k].lazy = -1;
  if (l == r) {
    IT[k].val = (s[l - 1] - '0' + 1);
  } else {
    int mid = (l + r) >> 1;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    IT[k].val = comb(IT[2 * k], IT[2 * k + 1]);
  }
}
void update(int k, int l, int r, int x, int y, int value) {
  if (l > y || r < x || l > r) return;
  if (x <= l && r <= y) {
    set_up(k, value);
    return;
  }
  int mid = (l + r) >> 1;
  lazy_prop(k);
  update(2 * k, l, mid, x, y, value);
  update(2 * k + 1, mid + 1, r, x, y, value);
  IT[k].val = comb(IT[2 * k], IT[2 * k + 1]);
}
int get(int k, int l, int r, int x, int y) {
  if (l > y || r < x || l > r) return 0;
  if (x <= l && r <= y) {
    return IT[k].val * pow_base[y - r];
  }
  int mid = (l + r) >> 1;
  lazy_prop(k);
  return (get(2 * k, l, mid, x, y) + get(2 * k + 1, mid + 1, r, x, y)) % mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  cin >> s;
  pow_base[0] = 1;
  for (int i = 1; i <= n; i++) {
    pow_base[i] = (pow_base[i - 1] * base) % mod;
    pow_4747[i] = (pow_4747[i - 1] + pow_base[i - 1]) % mod;
  }
  build(1, 1, n);
  for (int i = 0; i < m + k; i++) {
    int cmd, l, r, d;
    cin >> cmd >> l >> r >> d;
    if (cmd == 1) {
      update(1, 1, n, l, r, d);
    } else {
      if (get(1, 1, n, l, r - d) == get(1, 1, n, l + d, r))
        puts("YES");
      else
        puts("NO");
    }
  }
}
