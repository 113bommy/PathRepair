#include <bits/stdc++.h>
using namespace std;
template <class T>
T Maximize(T &v, T nv) {
  if (nv > v) v = nv;
  return v;
}
template <class T>
T Minimize(T &v, T nv) {
  if (nv < v) v = nv;
  return v;
}
template <class T>
T Mod(T &v, T mod) {
  return v = (v % mod + mod) % mod;
}
const long long INFLL = numeric_limits<long long>::max();
const long INF = numeric_limits<long>::max(), N = (long)1e5 + 1;
struct Res {
  long n;
  long long h, sum;
  Res(long n, long long h, long long sum) : n(n), h(h), sum(sum) {}
};
class Treap {
  struct Node {
    long pr, size;
    long long sum;
    long long key;
    Node *l, *r;
    Node(long long key) : size(1), sum(key), key(key), l(0), r(0) {}
    Node(long long key, Node *l, Node *r)
        : size(1), sum(key), key(key), l(l), r(r) {
      pr = (rand() << 15) + rand();
    }
    void Print() {
      printf("%ld", key);
      printf("(%ld) ", size);
    }
  };

 private:
  Node *root;
  void erase(Node *&v, long key) {
    if (v->key == key)
      Merge(v->l, v->r, v);
    else
      erase(key < v->key ? v->l : v->r, key);
    Update(v);
  }

 public:
  Treap() { root = NULL; }
  long SizeOf(Node *v) { return v ? v->size : 0; }
  long long SumOf(Node *v) { return v ? v->sum : 0; }
  void Update(Node *v) {
    if (!v) return;
    v->sum = SumOf(v->l) + SumOf(v->r) + v->key;
    v->size = SizeOf(v->l) + SizeOf(v->r) + 1;
  }
  void Split(Node *v, long long key, Node *&l, Node *&r) {
    if (!v) return void(r = l = 0);
    if (v->key <= key) {
      Split(v->r, key, v->r, r);
      l = v;
    } else {
      Split(v->l, key, l, v->l);
      r = v;
    }
    Update(v);
  }
  void Merge(Node *l, Node *r, Node *&v) {
    if (!l || !r) return void(v = l ? l : r);
    if (l->pr > r->pr) {
      v = l;
      Merge(l->r, r, v->r);
    } else {
      v = r;
      Merge(l, r->l, v->l);
    }
    Update(v);
  }
  void Insert(long long key) {
    Node *l = 0, *r = 0;
    Split(root, key, l, r);
    Node *x = new Node(key);
    Merge(l, x, l);
    Merge(l, r, root);
  }
  void Erase(long long key) { erase(root, key); }
  Res LowerThanSum(double key) {
    Node *v = root;
    long less = 0;
    long long sum = 0;
    while (v) {
      if (key < v->key) {
        v = v->l;
      } else if (key >= v->key) {
        less += SizeOf(v->l) + 1;
        sum += SumOf(v->l) + v->key;
        v = v->r;
      } else {
        break;
      }
    }
    return Res(less, 42, sum);
  }
  void Print(Node *v) {
    if (!v) return;
    Print(v->l);
    v->Print();
    Print(v->r);
  }
  void Print() {
    Print(root);
    printf("\n");
  }
};
long n, a[N];
void solve() {
  srand(time(0));
  long q;
  scanf("%ld %ld", &n, &q);
  Treap *t = new Treap();
  for (long i = 0; i < n; ++i) {
    scanf("%ld", a + i);
    t->Insert(a[i]);
  }
  while (q--) {
    long op;
    scanf("%ld", &op);
    switch (op) {
      case 1:
        long i, x;
        scanf("%ld %ld", &i, &x);
        t->Erase(a[i - 1]);
        t->Insert(x);
        a[i - 1] = x;
        break;
      case 2:
        long long v;
        scanf("%I64d", &v);
        double res, l = .0, r = 1e15 + 1e10, m;
        for (long steps = 0; steps < 65; ++steps) {
          m = (l + r) / 2;
          Res res = t->LowerThanSum(m);
          if (m * res.n - res.sum > v) {
            r = m;
          } else {
            l = m;
          }
        }
        printf("%lf\n", m);
        break;
    }
  }
}
void init() {}
int main() {
  init();
  solve();
  return 0;
}
