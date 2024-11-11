#include <bits/stdc++.h>
using namespace std;
int n, fib[200011], coef[200011][2], sum[200011];
inline int mod(long long a, int m = 1000000000) { return (a % m + m) % m; }
struct inter {
  int sum, sumfib0, sumfib1, w;
  inter(int sum = 0, int sumfib0 = 0, int sumfib1 = 0, int w = 0)
      : sum(sum), sumfib0(sumfib0), sumfib1(sumfib1), w(w) {}
};
struct inter M[400010];
inline void sync(int n) {
  M[n].sum = (M[2 * n].sum + M[2 * n + 1].sum) % 1000000000;
  M[n].sumfib0 = (M[2 * n].sumfib0 + M[2 * n + 1].sumfib0) % 1000000000;
  M[n].sumfib1 = (M[2 * n].sumfib1 + M[2 * n + 1].sumfib1) % 1000000000;
}
inline void propagate(int n, int b, int e) {
  M[2 * n].w = (M[2 * n].w + M[n].w) % 1000000000;
  M[2 * n + 1].w = (M[2 * n + 1].w + M[n].w) % 1000000000;
}
inline void fix(int n, int b, int e) {
  if (M[n].w) {
    M[n].sum = mod(M[n].sum + 1ll * M[n].w * (e - b + 1));
    M[n].sumfib0 = mod(M[n].sumfib0 +
                       1ll * M[n].w * (sum[e - 1] - (b > 1 ? sum[b - 2] : 0)));
    M[n].sumfib1 = mod(M[n].sumfib1 + 1ll * M[n].w * (sum[e] - sum[b - 1]));
  }
  if (b != e) propagate(n, b, e);
  M[n].w = 0;
}
inter query(int n, int b, int e, int i, int j) {
  fix(n, b, e);
  if (j < b || i > e) return inter();
  if (i <= b && j >= e) return M[n];
  inter p1 = query(2 * n, b, (b + e) / 2, i, j);
  inter p2 = query(2 * n + 1, (b + e) / 2 + 1, e, i, j);
  return inter((p1.sum + p2.sum) % 1000000000,
               (p1.sumfib0 + p2.sumfib0) % 1000000000,
               (p1.sumfib1 + p2.sumfib1) % 1000000000);
}
void update(int n, int b, int e, int i, int j, int v) {
  if (i <= b && j >= e) {
    M[n].w = (M[n].w + v) % 1000000000;
    fix(n, b, e);
  } else if (j < b || i > e)
    fix(n, b, e);
  else {
    propagate(n, b, e);
    update(2 * n, b, (b + e) / 2, i, j, v);
    update(2 * n + 1, (b + e) / 2 + 1, e, i, j, v);
    M[n].w = 0;
    sync(n);
  }
}
void precalc() {
  int i, j;
  fib[0] = fib[1] = 1;
  for (i = 2; i <= n; i++) fib[i] = mod(fib[i - 1] + fib[i - 2]);
  sum[0] = 1;
  for (i = 1; i <= n; i++) sum[i] = mod(sum[i - 1] + fib[i]);
  coef[0][0] = 1;
  coef[0][1] = 0;
  coef[1][0] = 0;
  coef[1][1] = 1;
  for (i = 2; i <= n; i++)
    for (j = 0; j < 2; j++) coef[i][j] = mod(coef[i - 2][j] - coef[i - 1][j]);
}
int main() {
  int m, a, i, t, x, v, l, r;
  inter q;
  cin >> n >> m;
  precalc();
  for (i = 1; i <= n; i++) {
    cin >> a;
    update(1, 1, n, i, i, a);
  }
  while (m--) {
    cin >> t;
    if (t == 1) {
      cin >> x >> v;
      q = query(1, 1, n, x, x);
      update(1, 1, n, x, x, mod(v - q.sum));
    }
    if (t == 2) {
      cin >> l >> r;
      q = query(1, 1, n, l, r);
      cout << mod(1ll * q.sumfib1 * coef[l][0] + 1ll * q.sumfib0 * coef[l][1])
           << endl;
    }
    if (t == 3) {
      cin >> l >> r >> v;
      update(1, 1, n, l, r, v);
    }
  }
  return 0;
}
