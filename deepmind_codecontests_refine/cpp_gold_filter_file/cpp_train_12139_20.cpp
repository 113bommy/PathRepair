#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr int N = 2e5 + 5;
struct Node {
  int sum;
  Node *l, *r;
  Node(int s = 0, Node* l = nullptr, Node* r = nullptr) : sum(s), l(l), r(r){};
};
using pN = Node*;
Node buff[N << 5];
int st = 0;
pN newN(int v, pN l = nullptr, pN r = nullptr) {
  buff[st] = Node(v, l, r);
  return &buff[st++];
}
int get_sum(pN v) { return v == nullptr ? 0 : v->sum; }
pN combine(pN l, pN r) { return newN(get_sum(l) + get_sum(r), l, r); }
struct SegTree {
  pN root = nullptr;
  pN ver[N];
  pN upd(int pos, int val, pN v, int l, int r) {
    if (l + 1 == r) return newN(val);
    int mid = (l + r) >> 1;
    pN le = v == nullptr ? nullptr : v->l;
    pN ri = v == nullptr ? nullptr : v->r;
    if (pos < mid)
      le = upd(pos, val, le, l, mid);
    else
      ri = upd(pos, val, ri, mid, r);
    return combine(le, ri);
  }
  int get(int l, int r, pN v, int cl, int cr) {
    if (l >= r || get_sum(v) == 0) return 0;
    if (l == cl && r == cr) return get_sum(v);
    int mid = (cl + cr) >> 1;
    return get(l, min(mid, r), v->l, cl, mid) +
           get(max(l, mid), r, v->r, mid, cr);
  }
} tr;
int n, k, q, x, y, last = 0;
queue<int> val[N];
int vec[N];
void Solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> vec[i];
  for (int i = n - 1; i >= 0; i--) {
    if (val[vec[i]].size() == k) {
      tr.root = tr.upd(val[vec[i]].front(), 0, tr.root, 0, n);
      val[vec[i]].pop();
    }
    tr.root = tr.upd(i, 1, tr.root, 0, n);
    val[vec[i]].push(i);
    tr.ver[i] = tr.root;
  }
  cin >> q;
  while (q--) {
    cin >> x >> y;
    x = (x + last) % n + 1;
    y = (y + last) % n + 1;
    if (x > y) swap(x, y);
    x--;
    last = tr.get(x, y, tr.ver[x], 0, n);
    cout << last << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  Solve();
  return 0;
}
