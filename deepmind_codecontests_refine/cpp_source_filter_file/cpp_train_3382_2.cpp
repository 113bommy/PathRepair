#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
template <class T>
void read(T &x) {
  char c, mi = 0;
  while (c = getchar(), c <= 32)
    ;
  if (c == '-')
    mi = 1, x = 0;
  else if (c < 48 || c > 57)
    return void(x = c);
  else
    x = c - 48;
  while (c = getchar(), c > 32) x = 10 * x + c - 48;
  if (mi == 1) x = -x;
}
template <class T>
void read(T &x, T &y) {
  read(x);
  read(y);
}
template <class T>
void read(T &x, T &y, T &z) {
  read(x, y);
  read(z);
}
template <class T>
void reada(T *a, int n) {
  for (int i = 0; i < n; ++i) read(a[i]);
}
template <class T>
void write(T x) {
  static char s[20];
  char pt = 0, mi = (x < 0);
  if (mi == 1) x = -x;
  while (!pt || x > 0) {
    s[++pt] = (char)(x % 10 + '0');
    x /= 10;
  }
  if (mi == 1) putchar('-');
  while (pt > 0) putchar(s[pt--]);
}
template <class T>
void write(T x, T y) {
  write(x);
  putchar(' ');
  write(y);
}
template <class T>
void write(T x, T y, T z) {
  write(x, y);
  putchar(' ');
  write(z);
}
template <class T>
void writeln(T x) {
  write(x);
  puts("");
}
template <class T>
void writea(T *a, int n) {
  for (int i = 0; i < n; ++i) {
    write(a[i]);
    putchar(i + 1 == n ? '\n' : ' ');
  }
}
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
T qpom(T a, T b, T mod = 1000000007) {
  T r = 1;
  while (b > 0) {
    if (b & 1) r = r * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return r;
}
template <class T>
T qpow(T a, T b) {
  T r = 1;
  while (b > 0) {
    if (b & 1) r *= a;
    a *= a;
    b /= 2;
  }
  return r;
}
template <class T>
T imin(T a, T b) {
  return a < b ? a : b;
}
template <class T>
T imax(T a, T b) {
  return a > b ? a : b;
}
template <class T>
inline void rmin(T &a, const T &b) {
  if (a > b) a = b;
}
template <class T>
inline void rmax(T &a, const T &b) {
  if (a < b) a = b;
}
template <class T>
T sqr(const T &a) {
  return a * a;
}
struct Node {
  Node *l, *r;
  int ans, add;
  Node() : ans(0), add(0), l(NULL), r(NULL) {}
};
void Upd(Node *&v, int L, int R, int l, int r, int val) {
  if (R < l || L > r || l > r) {
    return;
  }
  if (v == NULL) {
    v = new Node();
  }
  if (l <= L && R <= r) {
    ++v->add;
    ++v->ans;
    return;
  }
  int M = (L + R) / 2;
  if (v->l == NULL) {
    v->l = new Node();
  }
  Upd(v->l, L, M, l, r, val);
  if (v->r == NULL) {
    v->r = new Node();
  }
  Upd(v->r, M + 1, R, l, r, val);
  v->ans =
      v->add + imax(v->l != NULL ? v->l->ans : 0, v->r != NULL ? v->r->ans : 0);
}
int Get(Node *&v, int L, int R, int l, int r) {
  if (R < l || L > r || l > r) {
    return 0;
  }
  if (l <= L && R <= r) {
    return v->ans;
  }
  int M = (L + R) / 2;
  return v->add + imax(v->l != NULL ? Get(v->l, L, M, l, r) : 0,
                       v->r != NULL ? Get(v->r, M + 1, R, l, r) : 0);
}
void Set(Node *&v, int l, int r, int p, int a) {
  if (l == r) {
    v->ans = a;
    return;
  }
  int m = (l + r) / 2;
  if (p <= m) {
    if (v->l == NULL) {
      v->l = new Node();
    }
    Set(v->l, l, m, p, a);
  } else {
    if (v->r == NULL) {
      v->r = new Node();
    }
    Set(v->r, m + 1, r, p, a);
  }
  v->ans =
      v->add + imax(v->l != NULL ? v->l->ans : 0, v->r != NULL ? v->r->ans : 0);
}
int main() {
  Node *root = new Node();
  set<pair<int, int> > s;
  int last = -1, n, r;
  read(n, r);
  for (int i = 0, b, e; i < n; ++i) {
    read(b, e);
    if (e >= 0) {
      rmax(b, 0);
      s.insert(make_pair(b, -2));
      s.insert(make_pair(e, b));
    }
  }
  while (!s.empty()) {
    int b = s.begin()->second, e = s.begin()->first;
    s.erase(s.begin());
    if (b >= 0) {
      Upd(root, 0, -1U / 4, b, e, 1);
      continue;
    }
    if (e == last) {
      continue;
    }
    int d = Get(root, 0, -1U / 4, 0, e - r);
    if (b == -2 || b == -1 && d > Get(root, 0, -1U / 4, last, last)) {
      Set(root, 0, -1U / 4, e, d);
      if (e + r < -1U / 4) {
        s.insert(make_pair(e + r, -1));
      }
      last = e;
    }
  }
  writeln(root->ans);
  getchar();
  getchar();
  return 0;
}
