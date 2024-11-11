#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const double SQRT2 = 1.41421356237;
const double EPS = 1e-9;
const float SQRT2F = (float)SQRT2;
const int INF = 1e9;
const long long INF64 = 1e18;
template <class T>
T sqr(const T &x) {
  return x * x;
}
template <class T>
T min(const T &a, const T &b, const T &c) {
  return min(min(a, b), c);
}
template <class T>
T max(const T &a, const T &b, const T &c) {
  return max(max(a, b), c);
}
inline void yesno(bool y) { cout << (y ? "YES\n" : "NO\n"); }
inline void yes_stop(bool y) {
  if (y) {
    yesno(1);
    exit(0);
  }
}
inline void no_stop(bool y) {
  if (!y) {
    yesno(0);
    exit(0);
  }
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int sgn(int x) { return (x > 0) - (x < 0); }
template <class Container>
void print_container(ostream &os, Container c) {
  for (const auto &x : c) {
    os << x << " ";
  }
}
template <class It>
void print_range(ostream &os, It b, It e) {
  for (; b != e; ++b) {
    os << *b << " ";
  }
}
const int MAXN = 1e6 + 5;
int rand_expanded() {
  int ans = (rand() << 16) | rand();
  return ans;
}
struct DecartTree {
  int y;
  int l, r;
  int sz;
  int v;
};
DecartTree dt[MAXN];
int dt_nodes_i = 1;
int root = 0;
void dt_recount(int T) {
  if (T == 0) {
    return;
  }
  dt[T].sz = dt[dt[T].l].sz + dt[dt[T].r].sz + 1;
}
int dt_node(int a) {
  int i = dt_nodes_i++;
  dt[i].v = a;
  dt[i].y = rand_expanded();
  dt[i].l = dt[i].r = 0;
  dt[i].sz = 1;
  dt_recount(i);
  return i;
}
DecartTree &node(int i) { return dt[i]; }
int dt_merge(int a, int b) {
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }
  if (dt[b].y > dt[a].y) {
    dt[b].l = dt_merge(a, dt[b].l);
    dt_recount(b);
    return b;
  } else {
    dt[a].r = dt_merge(dt[a].r, b);
    dt_recount(a);
    return a;
  }
}
void dt_print(int);
pair<int, int> dt_split(int T, int i) {
  if (T == 0) {
    return pair<int, int>(0, 0);
  }
  if (dt[dt[T].l].sz >= i) {
    pair<int, int> p = dt_split(dt[T].l, i);
    dt[T].l = p.second;
    dt_recount(T);
    return pair<int, int>(p.first, T);
  } else {
    pair<int, int> p = dt_split(dt[T].r, i - dt[dt[T].l].sz - 1);
    dt[T].r = p.first;
    dt_recount(T);
    return pair<int, int>(T, p.second);
  }
}
int dt_add(int T, int x) {
  int r = dt_node(x);
  return dt_merge(T, r);
}
int dt_del(int T, int a) {
  pair<int, int> p1 = dt_split(T, a);
  pair<int, int> p2 = dt_split(p1.second, 1);
  return dt_merge(p1.first, p2.second);
}
void dt_seq(int T) {
  if (T == 0) {
    return;
  }
  dt_seq(dt[T].l);
  cout << dt[T].v;
  dt_seq(dt[T].r);
}
int n, m, a[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  srand(1337);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  for (int z = 0; z < n; ++z) {
    int q;
    cin >> q;
    if (q < 0) {
      for (int i = 0; i < m; ++i) {
        if (a[i] > dt[root].sz) {
          break;
        }
        root = dt_del(root, a[i] - i - 1);
      }
    } else {
      root = dt_add(root, q);
    }
  }
  dt_seq(root);
  if (!root) cout << "Poor stack!";
  cout << "\n";
  return 0;
}
