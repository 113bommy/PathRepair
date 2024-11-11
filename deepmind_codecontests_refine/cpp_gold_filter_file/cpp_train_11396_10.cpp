#include <bits/stdc++.h>
using namespace std;
typedef int Elem;
typedef int Alt;
const Elem neutro = 0;
const Alt neutro2 = 0;
struct RMQ {
  int sz;
  Elem t[4 * 100010];
  Alt dirty[4 * 100010];
  Elem &operator[](int p) { return t[sz + p]; }
  void init(int n) {
    sz = 1 << (32 - __builtin_clz(n));
    for (int i = (sz); i < (2 * sz); i++) t[i] = neutro;
    for (int i = (0); i < (2 * sz); i++) dirty[i] = neutro2;
  }
  void push(int n, int a, int b) {
    if (dirty[n] != 0) {
      t[n] |= dirty[n];
      if (n < sz) {
        dirty[2 * n] |= dirty[n];
        dirty[2 * n + 1] |= dirty[n];
      }
      dirty[n] = 0;
    }
  }
  void prop() {
    for (int i = (0); i < (2 * sz); i++) push(i, 0, 0);
  }
  Elem get(int i, int j, int n, int a, int b) {
    push(n, a, b);
    if (j <= a || i >= b) return neutro;
    if (i <= a && b <= j) return t[n];
    int c = (a + b) / 2;
    return (get(i, j, 2 * n, a, c) | get(i, j, 2 * n + 1, c, b));
  }
  Elem get(int i, int j) { return get(i, j, 1, 0, sz); }
  void alterar(Alt val, int i, int j, int n, int a, int b) {
    push(n, a, b);
    if (j <= a || i >= b) return;
    if (i <= a && b <= j) {
      dirty[n] |= val;
      push(n, a, b);
      return;
    }
    int c = (a + b) / 2;
    alterar(val, i, j, 2 * n, a, c), alterar(val, i, j, 2 * n + 1, c, b);
    t[n] = (t[2 * n] | t[2 * n + 1]);
  }
  void alterar(Alt val, int i, int j) { alterar(val, i, j, 1, 0, sz); }
} rmq;
struct RMQ3 {
  int vec[18][1 << (18 + 1)];
  int &operator[](int p) { return vec[0][p]; }
  int get(int i, int j) {
    int p = 31 - __builtin_clz(j - i);
    return vec[p][i] & vec[p][j - (1 << p)];
  }
  void build(int n) {
    int mp = 31 - __builtin_clz(n);
    for (int p = (0); p < (mp); p++)
      for (int x = (0); x < (n - (1 << p)); x++)
        vec[p + 1][x] = vec[p][x] & vec[p][x + (1 << p)];
  }
};
int op[100010][3];
struct RMQ a;
struct RMQ3 b;
int v[100010];
int m, n;
int main() {
  while (cin >> n >> m) {
    a.init(n);
    for (int i = (0); i < (m); i++) {
      cin >> op[i][0] >> op[i][1] >> op[i][2];
      a.alterar(op[i][2], op[i][0] - 1, op[i][1]);
    }
    a.prop();
    for (int i = (0); i < (n); i++) {
      b[i] = a[i];
    }
    b.build(n);
    bool found = true;
    for (int i = (0); i < (m); i++) {
      if (b.get(op[i][0] - 1, op[i][1]) != op[i][2]) {
        found = false;
        break;
      }
    }
    if (found) {
      cout << "YES\n";
      for (int i = (0); i < (n - 1); i++) cout << a[i] << " ";
      cout << a[n - 1] << endl;
    } else
      cout << "NO\n";
  }
  return 0;
}
