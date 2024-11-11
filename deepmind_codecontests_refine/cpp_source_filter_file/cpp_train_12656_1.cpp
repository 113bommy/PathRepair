#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1e5 + 5;
int cnts[LIM_N];
const int inf = 1e9;
struct Node {
  Node *l = 0, *r = 0;
  int lo, hi, mset = inf, madd = 0, val = -inf;
  Node(int lo, int hi) : lo(lo), hi(hi) {}
  Node(vector<int>& v, int lo, int hi) : lo(lo), hi(hi) {
    if (lo + 1 < hi) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(v, lo, mid);
      r = new Node(v, mid, hi);
      val = max(l->val, r->val);
    } else
      val = v[lo];
  }
  int query(int L, int R) {
    if (R <= lo || hi <= L) return -inf;
    if (L <= lo && hi <= R) return val;
    push();
    return max(l->query(L, R), r->query(L, R));
  }
  void set(int L, int R, int x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R)
      mset = val = x, madd = 0;
    else {
      push(), l->set(L, R, x), r->set(L, R, x);
      val = max(l->val, r->val);
    }
  }
  void add(int L, int R, int x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R) {
      if (mset != inf)
        mset += x;
      else
        madd += x;
      val += x;
    } else {
      push(), l->add(L, R, x), r->add(L, R, x);
      val = max(l->val, r->val);
    }
  }
  void push() {
    if (!l) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(lo, mid);
      r = new Node(mid, hi);
    }
    if (mset != inf)
      l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
    else if (madd)
      l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
  }
};
int N;
int vals[LIM_N];
int ps[LIM_N], ts[LIM_N], xs[LIM_N];
Node* st;
int getNm() {
  int ini = 0, fin = N;
  while (ini < fin) {
    int piv = (ini + fin) / 2 + 1;
    if (st->query(piv, piv + 1) <= 0)
      fin = piv - 1;
    else
      ini = piv;
  }
  return ini == 0 ? -1 : vals[ini];
}
int main() {
  vector<int> _vk;
  scanf("%d", &N);
  _vk.resize(N + 1, 0);
  st = new Node(_vk, 0, N + 1);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &ps[i], &ts[i]);
    if (ts[i]) {
      scanf("%d", &xs[i]);
      vals[ps[i]] = xs[i];
    }
    st->add(0, ps[i] + 1, ts[i] ? 1 : -1);
  }
  for (int i = N - 1; i >= 0; i--) {
    xs[i] = getNm();
    st->add(0, ps[i] + 1, ts[i] ? -1 : 1);
  }
  for (int i = 0; i < N; i++) printf("%d\n", xs[i]);
}
