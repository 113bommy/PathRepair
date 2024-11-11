#include <bits/stdc++.h>
using namespace std;
struct Tpair {
  long long x, y;
  Tpair(long long _x = 0, long long _y = 0) { x = _x, y = _y; }
  inline bool operator<(const Tpair &b) const {
    return x != b.x ? x < b.x : y < b.y;
  }
};
struct Tcxx {
  long long a, b, c, v;
  Tcxx(long long _a = 0, long long _b = 0, long long _c = 0) {
    a = _a, b = _b, c = _c;
  }
  inline long long operator()() { return v = a * b + a * c + b * c; }
};
long long n, B[50][70];
int N;
Tpair A[50];
long long Sqrt(long long n) {
  long long x = sqrt(n) + 1;
  for (; x * x > n; --x)
    ;
  return x;
}
namespace Ninit {
void init() {
  int i, j;
  n = 1;
  for (cin >> N, i = 0; i < N; ++i) cin >> A[i].x >> A[i].y;
  sort(A, A + N), reverse(A, A + N);
  for (i = 0; i < N; ++i)
    for (B[i][0] = 1, j = 1; j <= A[i].y; ++j) B[i][j] = B[i][j - 1] * A[i].x;
  for (i = 0; i < N; ++i) n *= B[i][A[i].y];
}
}  // namespace Ninit
namespace Nsolve {
Tcxx S, W;
int tot;
void dfs2(int x) {
  if (W.a * W.b * W.b > n) return;
  if (x == N) {
    W.c = n / W.a / W.b;
    if (W() < S.v) S = W;
    return;
  }
  int i;
  long long W_ = W.b;
  for (i = A[x].y; i >= 0; --i) {
    W.b *= B[x][i], dfs2(x + 1), W.b = W_;
  }
}
void dfs1(int x) {
  if (W.a * W.a * W.a > n) return;
  if (x == N) {
    if (W.a * 2 * Sqrt(n / W.a) + n / W.a <= S.v) dfs2(0);
    return;
  }
  int i;
  long long W_ = W.a;
  for (i = A[x].y; i >= 0; --i) {
    A[x].y -= i, W.a *= B[x][i];
    dfs1(x + 1);
    A[x].y += i, W.a = W_;
  }
}
void solve() {
  S = Tcxx(1, 1, n), S(), W = Tcxx(1, 1, 1);
  dfs1(0);
  cout << 2 * S.v << ' ' << S.a << ' ' << S.b << ' ' << S.c << endl;
}
}  // namespace Nsolve
int main() {
  int Q;
  for (cin >> Q; Q; --Q) {
    Ninit::init();
    Nsolve::solve();
  }
  return 0;
}
