#include <bits/stdc++.h>
const long long inf = 1e9 + 7;
using namespace std;
using pii = pair<long long, long long>;
struct Node {
  long long key, prior = 0;
  long long max1 = -inf;
  long long size = 1;
  long long index = 0;
  Node *l = 0, *r = 0;
  Node(long long a, long long i) {
    key = a;
    max1 = a;
    index = i;
    prior = rand();
  }
};
long long sz(Node* v) {
  if (!v) return 0;
  return v->size;
}
long long max1(Node* v) {
  if (!v) return -inf;
  return v->max1;
}
void upd(Node* v) {
  if (!v) return;
  v->size = 1 + sz(v->l) + sz(v->r);
  v->max1 = max(v->key, max(max1(v->l), max1(v->r)));
}
Node* merge(Node* l, Node* r) {
  if (!l) return r;
  if (!r) return l;
  if (l->prior > r->prior) {
    l->r = merge(l->r, r);
    upd(l);
    return l;
  } else {
    r->l = merge(l, r->l);
    upd(r);
    return r;
  }
}
using Pair = pair<Node*, Node*>;
Pair split(Node* p, long long k) {
  if (!p) return {0, 0};
  if (1 + sz(p->l) <= k) {
    Pair q = split(p->r, k - sz(p->l) - 1);
    p->r = q.first;
    upd(p);
    return {p, q.second};
  } else {
    Pair q = split(p->l, k);
    p->l = q.second;
    upd(p);
    return {q.first, p};
  }
}
long long find_pos(Node* p, long long x) {
  if (!p) return 0;
  if (max1(p->r) > x) {
    return sz(p->l) + 1 + find_pos(p->r, x);
  }
  if (p->key > x) {
    return sz(p->l);
  }
  return find_pos(p->l, x);
}
int32_t main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  long long n;
  cin >> n;
  Node* root = 0;
  for (long long i = 0; i < n; ++i) {
    long long a, c;
    cin >> a >> c;
    Node* t = new Node(a, i);
    if (!root) {
      root = t;
      continue;
    }
    long long szleft = max(0LL, sz(root) - c);
    Pair q = split(root, szleft);
    if (max1(q.second) < a) {
      root = merge(q.first, merge(t, q.second));
      continue;
    }
    long long ps = find_pos(q.second, a);
    Pair q1 = split(q.second, ps + 1);
    root = merge(q.first, merge(q1.first, merge(t, q1.second)));
  }
  for (long long i = 0; i < n; ++i) {
    Pair q = split(root, 1);
    cout << q.first->index + 1 << ' ';
    root = q.second;
  }
}
