#include <bits/stdc++.h>
using namespace std;
const long long Inf = 2E9;
template <class T>
struct Tree {
  Tree* izq;
  Tree* der;
  T dato;
  long long i;
  long long d;
  long long lz;
  long long ac;
  Tree(long long i, long long d)
      : i(i), d(d), dato(), lz(0), ac(0), izq(0), der(0) {}
  void propagate() {
    if (ac) {
      dato = lz;
      if (izq) {
        izq->lz = lz;
        der->lz = lz;
        izq->ac = 1;
        der->ac = 1;
      }
      ac = 0;
    }
  }
  T build() {
    if (i == d) return dato = Inf;
    long long mi = (i + d) >> 1;
    izq = new Tree(i, mi + 0);
    der = new Tree(mi + 1, d);
    return dato = izq->build() + der->build();
  }
  T update(long long a, long long b, T x) {
    propagate();
    if (b < i || a > d) return T();
    if (a <= i && d <= b) {
      if (izq) {
        izq->lz = x;
        der->lz = x;
        izq->ac = 1;
        der->ac = 1;
      }
      return dato = x;
    }
    return dato = izq->update(a, b, x) + der->update(a, b, x);
  }
  T query(long long a, long long b) {
    propagate();
    if (b < i || a > d) return T();
    if (a <= i && d <= b) return dato;
    return izq->query(a, b) + der->query(a, b);
  }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  long long a, x;
  long long u, v;
  cin >> n;
  cin >> m;
  vector<long long> one(n + 1);
  for (long long i = 1; i <= n; i++) cin >> one[i];
  vector<long long> two(n + 1);
  for (long long i = 1; i <= n; i++) cin >> two[i];
  Tree<long long> tree(1, n);
  tree.build();
  while (m--) {
    cin >> a >> x;
    if (a == 1) {
      cin >> u >> v;
      tree.update(u, u + v, x - u);
    }
    if (a == 2) {
      long long pos = tree.query(x, x);
      cout << (pos == Inf ? two[x] : one[x + pos]) << '\n';
    }
  }
  return 0;
}
