#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
const int maxn = 600;
int n, m, N, S, T;
double A[maxn];
int E[maxn][maxn], D[maxn];
inline int dblc(double x) { return (x > eps) - (x < -eps); }
struct Tgauss {
  int n, m;
  double A[maxn][maxn];
  void solve() {
    int i, j, k;
    for (i = 0; i < n; ++i) {
      for (j = i; j < n; ++j)
        if (dblc(A[i][j])) break;
      swap(A[i], A[j]);
      for (k = m; k >= i; --k) A[i][k] /= A[i][i];
      for (j = 0; j < n; ++j)
        if (i != j)
          for (k = m; k >= i; --k) A[j][k] -= A[i][k] * A[j][i];
    }
  }
  void print() {
    int i, j;
    for (i = 0; i < n; ++i) {
      for (j = 0; j < m; ++j) fprintf(stderr, "%.3lf ", A[i][j]);
      cerr << endl;
    }
  }
} Ax;
namespace Ninit {
void init() {
  int i, ai, bi;
  scanf("%d%d%d%d", &n, &m, &S, &T), --S, --T;
  for (i = 0; i < m; ++i) {
    scanf("%d%d", &ai, &bi), --ai, --bi;
    E[ai][bi] = E[bi][ai] = true;
    ++D[ai], ++D[bi];
  }
  for (i = 0; i < n; ++i) E[i][i] = true;
  N = n * n;
  for (i = 0; i < n; ++i) scanf("%lf", A + i);
}
}  // namespace Ninit
namespace Nsolve {
inline double Fp(int a, int b) { return a == b ? A[a] : (1 - A[a]) / D[a]; }
void solve() {
  int i, j, p, q, x;
  Ax.n = N, Ax.m = N + n;
  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j) {
      x = i * n + j;
      Ax.A[x][x] = 1;
      if (i == j) {
        Ax.A[x][N + i] = 1;
        continue;
      }
      for (p = 0; p < n; ++p)
        if (E[i][p])
          for (q = 0; q < n; ++q)
            if (E[j][q]) {
              Ax.A[x][p * n + q] -= Fp(i, p) * Fp(j, q);
            }
    }
  Ax.solve();
  for (i = 0; i < n; ++i) printf("%.8lf ", Ax.A[S * n + T][N + i]);
  printf("\n");
}
}  // namespace Nsolve
int main() {
  Ninit::init();
  Nsolve::solve();
  return 0;
}
