#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
double error = 1e-8;
inline long long int MOD(long long int x) {
  long long int y = x % mod;
  if (y < 0) y += mod;
  return y;
}
const int nmax = 1e5 + 10;
struct node {
  int mn, mx;
  node(int x = 0) { mn = mx = x; }
  node(int x, int y) {
    mn = x;
    mx = y;
  }
  node operator+(node other) {
    node ret;
    ret.mn = min(mn, other.mn);
    ret.mx = max(mx, other.mx);
    return ret;
  }
  node operator+(int n) {
    node ret = *this;
    ret.mn += n;
    ret.mx += n;
    return ret;
  }
} I(1e8, -1e8);
int arr[nmax];
node tree[4 * nmax];
int lazy[4 * nmax];
void build(int id, int l, int r) {
  lazy[id] = 0;
  if (l == r) {
    tree[id] = node(arr[l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(2 * id, l, mid);
  build(2 * id + 1, mid + 1, r);
  tree[id] = tree[2 * id] + tree[2 * id + 1];
  return;
}
inline void propagate(int id, int l, int r) {
  if (l != r) {
    lazy[2 * id] = lazy[2 * id] + lazy[id];
    lazy[2 * id + 1] = lazy[2 * id + 1] + lazy[id];
  }
  tree[id] = tree[id] + lazy[id];
  lazy[id] = 0;
}
node query(int id, int l, int r, int L, int R) {
  propagate(id, l, r);
  if (r < L || R < l) return I;
  if (L <= l && r <= R) return tree[id];
  int mid = (l + r) >> 1;
  node p = query(2 * id, l, mid, L, R);
  node q = query(2 * id + 1, mid + 1, r, L, R);
  return p + q;
}
void update(int id, int l, int r, int L, int R, int x) {
  propagate(id, l, r);
  if (r < L || R < l) return;
  if (L <= l && r <= R) {
    lazy[id] = lazy[id] + x;
    propagate(id, l, r);
    return;
  }
  int mid = (l + r) >> 1;
  update(2 * id, l, mid, L, R, x);
  update(2 * id + 1, mid + 1, r, L, R, x);
  tree[id] = tree[2 * id] + tree[2 * id + 1];
  return;
}
bool use[500];
int q[nmax][2];
vector<int> on[nmax], off[nmax];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &q[i][0], &q[i][1]);
    off[q[i][0]].push_back(i);
    on[q[i][1]].push_back(i);
  }
  int ans = 0, id = 0;
  build(1, 1, n);
  for (int i = 1; i <= m; i++) update(1, 1, n, q[i][0], q[i][1], -1);
  for (int i = 1; i <= n; i++) {
    for (auto j : off[i]) update(1, 1, n, q[j][0], q[j][1], +1);
    node tmp = query(1, 1, n, 1, n);
    if (ans <= tmp.mx - tmp.mn) {
      ans = tmp.mx - tmp.mn;
      id = i;
    }
    for (auto j : on[i]) update(1, 1, n, q[j][0], q[j][1], -1);
  }
  printf("%d\n", ans);
  vector<int> used;
  for (int i = 1; i <= m; i++)
    if (q[i][0] > id || id > q[i][1]) used.push_back(i);
  printf("%d\n", int(used.size()));
  for (auto i : used) printf("%d ", i);
}
