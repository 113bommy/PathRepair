#include <bits/stdc++.h>
inline int inc(int x, int v, int mod) {
  x += v;
  return x >= mod ? x - mod : x;
}
inline int dec(int x, int v, int mod) {
  x -= v;
  return x < 0 ? x + mod : x;
}
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
int _, __, ___;
using namespace std;
template <typename T>
inline void read(T& ret) {
  ret = 0;
  T f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    ret = (ret << 3) + (ret << 1) + (c ^ 48);
    c = getchar();
  }
  ret = ret * f;
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
  read(t);
  read(args...);
}
long long read() {
  long long ret = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    ret = (ret << 3) + (ret << 1) + (c ^ 48);
    c = getchar();
  }
  return ret * f;
}
const int MAXN = 4e6 + 10;
int lowbit(int x) { return x & -x; }
struct bit {
  struct tree {
    int N;
    long long a[MAXN];
    void add(int x, long long v) {
      while (x <= N) a[x] += v, x += lowbit(x);
    }
    long long sum(int x) {
      long long sum = 0;
      while (x) sum += a[x], x -= lowbit(x);
      return sum;
    }
  } T1, T2;
  void add(int x, long long v) {
    T1.add(x, v);
    T2.add(x, x * v);
  }
  void update(int L, int R, long long v) {
    add(L, v);
    add(R + 1, -v);
  }
  long long sum(int x) { return (x + 1) * T1.sum(x) - T2.sum(x); }
  long long query(int L, int R) { return sum(R) - sum(L - 1); }
} tx, ty;
int main() {
  int n, m, w;
  read(n, m, w);
  int op;
  int x1, x2, y1, y2;
  long long v;
  tx.T1.N = tx.T2.N = n;
  ty.T1.N = ty.T2.N = m;
  long long tot = 0;
  while (w--) {
    read(op, x1, y1, x2, y2);
    if (op) {
      long long ans = tx.query(x1, x2) + ty.query(y1, y2);
      printf("%lld\n", ans - tot);
    } else {
      scanf("%lld", &v);
      tot += (x2 - x1 + 1) * (y2 - y1 + 1) * v;
      tx.update(x1, x2, v * (y2 - y1 + 1));
      ty.update(y1, y2, v * (x2 - x1 + 1));
    }
  }
  return 0;
}
