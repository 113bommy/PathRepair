#include <bits/stdc++.h>
using namespace std;
const int INF = ~(1 << 31);
inline int in() {
  int a;
  scanf("%d", &a);
  return a;
}
template <class T1, class T2>
inline pair<T1, T2> reverse_make_pair(T1 x, T2 y) {
  return pair<T1, T2>(y, x);
}
template <class T>
ostream& operator<<(ostream& out, const vector<T> a) {
  for (int i = 0; i < (int)a.size(); i++) out << a[i] << ' ';
  return out;
}
template <class T>
ostream& operator<<(ostream& out, const set<T> a) {
  int i = 0;
  while (a.begin() + i != a.end()) {
    cout << *(a.begin() + i) << ' ';
    ++i;
  }
  return out;
}
double din() {
  double a;
  scanf("%lf", &a);
  return a;
}
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
const double eps = 1e-6;
int logbin(int a) {
  a--;
  int res = 1;
  while (a) a >>= 1, res <<= 1;
  return res;
}
int binpow(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res *= a;
    a *= a;
    n >>= 1;
  }
  return res;
}
struct treap {
  treap *l, *r;
  int c, y;
  int size;
  char color;
  treap(char _c) {
    l = r = NULL;
    size = 1;
    color = c;
    y = rand();
    recalc();
  }
  void recalc() {
    size = 1;
    if (l != NULL) {
      size += l->size;
      l->color = color;
    }
    if (r != NULL) {
      size += r->size;
      r->color = color;
    }
  }
};
void recalc(treap*& a) {
  if (a == NULL) return;
  a->recalc();
}
void merge(treap*& t, treap* l, treap* r) {
  if (l == NULL) return (void)(t = r);
  if (r == NULL) return (void)(t = l);
  recalc(r);
  recalc(l);
  if (r->y > l->y) {
    recalc(l);
    recalc(r->l);
    merge(r->l, l, r->l);
    t = r;
  } else {
    recalc(l->r);
    recalc(r);
    merge(l->r, l->r, r);
    t = l;
  }
  recalc(t);
}
void split(treap* v, int x, treap*& l, treap*& r) {
  if (v == NULL) {
    r = l = NULL;
    return;
  }
  recalc(v);
  int cur = 1;
  if (v->l != NULL) cur += v->l->size;
  if (cur <= x) {
    recalc(v->r);
    split(v->r, x - cur, v->r, r);
    l = v;
  } else {
    recalc(v->l);
    split(v->l, x, l, v->l);
    r = v;
  }
  recalc(v);
}
void dfs(treap* v) {
  if (v->l != NULL) dfs(v->l);
  cout << v->c << ' ';
  if (v->r != NULL) dfs(v->r);
}
int main() {
  int a = in(), b = in(), r = in();
  int c = (a / (2 * r)) * (b / (2 * r));
  if (c % 2 == 1)
    cout << "First";
  else
    cout << "Second";
  return 0;
}
