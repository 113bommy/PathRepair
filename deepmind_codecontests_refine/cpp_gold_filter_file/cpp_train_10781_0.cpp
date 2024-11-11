#include <bits/stdc++.h>
using namespace std;
const int n_max = 300010;
struct node {
  int h, l, r;
} T[n_max * 5];
long long A[n_max];
int n, m;
void absorb(int x, int k, int l, int mid, int r) {
  T[x].l = T[k].l;
  T[x].r = T[k + 1].r;
  T[x].h = max(T[k].h, T[k + 1].h);
  if (A[mid] > 0 || (A[mid] < 0 && A[mid + 1] < 0)) {
    if (T[x].l == mid - l + 1) T[x].l += T[k + 1].l;
    if (T[x].r == r - mid) T[x].r += T[k].r;
    T[x].h = max(T[x].h, T[k].r + T[k + 1].l);
  }
}
void build_tree(int x, int l, int r) {
  if (l == r) {
    T[x].h = 1;
    T[x].l = T[x].r = (A[l] != 0);
    return;
  }
  int k = x * 2, mid = l + (r - l) / 2;
  build_tree(k, l, mid);
  build_tree(k + 1, mid + 1, r);
  absorb(x, k, l, mid, r);
}
void upd(int u, int v, int x = 1, int l = 1, int r = n) {
  if (l == r) {
    m -= (A[l] == 0);
    A[l] += v;
    T[x].l = T[x].r = (A[l] != 0);
    m += (A[l] == 0);
    return;
  }
  int k = x * 2, mid = l + (r - l) / 2;
  if (u <= mid)
    upd(u, v, k, l, mid);
  else
    upd(u, v, k + 1, mid + 1, r);
  absorb(x, k, l, mid, r);
}
void enter() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> A[i];
  m = 1;
  for (int i = n; i > 1; --i) A[i] -= A[i - 1], m += (A[i] == 0);
  A[1] = 0;
  build_tree(1, 1, n);
}
void solve() {
  int q, l, r, d;
  cin >> q;
  while (q--) {
    cin >> l >> r >> d;
    if (l > 1) upd(l, d);
    if (r < n) upd(r + 1, -d);
    cout << (m == n ? 1 : T[1].h + 1) << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  if (ifstream("test.inp")) cin.rdbuf((new ifstream("test.inp"))->rdbuf());
  enter();
  solve();
}
