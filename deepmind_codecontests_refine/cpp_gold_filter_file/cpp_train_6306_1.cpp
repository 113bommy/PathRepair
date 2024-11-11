#include <bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
const int N = (int)1e5 + 9, K = 10, F = (int)1e4 + 7;
struct node {
  node *l, *r;
  int val, prio, sz;
  node(int v) : l(NULL), r(NULL), val(v), prio(rd()), sz(1) {}
} * root[F], *ll, *mm, *rr;
int sz(node* u) { return u ? u->sz : 0; }
void pull(node* u) {
  if (u) u->sz = sz(u->l) + sz(u->r) + 1;
}
void split(node* u, node*& l, node*& r, int key) {
  if (!u) return void(l = r = NULL);
  if (key <= u->val) {
    split(u->l, l, u->l, key);
    r = u;
  } else {
    split(u->r, u->r, r, key);
    l = u;
  }
  pull(u);
}
void merge(node*& u, node* l, node* r) {
  if (!l || !r)
    u = l ? l : r;
  else if (l->prio > r->prio) {
    merge(l->r, l->r, r);
    u = l;
  } else {
    merge(r->l, l, r->l);
    u = r;
  }
  pull(u);
}
int get(node*& u, int l, int r) {
  split(u, ll, rr, r + 1);
  split(ll, ll, mm, l);
  int ans = sz(mm);
  merge(u, ll, mm);
  merge(u, u, rr);
  return ans;
}
void add(node*& u, int x) {
  split(u, ll, rr, x);
  mm = new node(x);
  merge(u, ll, mm);
  merge(u, u, rr);
}
struct radio {
  int x, r, f;
  bool operator<(const radio& other) const { return r > other.r; }
} a[N];
int n, k;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].r >> a[i].f;
  sort(a + 1, a + n + 1);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = max(0, a[i].f - k), ma = min(F, a[i].f + k + 1); j < ma; ++j)
      ans += get(root[j], a[i].x - a[i].r, a[i].x + a[i].r);
    add(root[a[i].f], a[i].x);
  }
  cout << ans;
}
