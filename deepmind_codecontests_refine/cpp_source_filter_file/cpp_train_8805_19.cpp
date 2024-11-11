#include <bits/stdc++.h>
using namespace std;
namespace simplex {
long double inf = 1e+18;
long double eps = 1e-9;
inline int sgn(const long double &x) { return (x > +eps) - (x < -eps); }
const int MAXN = 3200;
const int MAXM = 250;
int n, m;
long double A[MAXM + 1][MAXN + 1], X[MAXN];
int basis[MAXM + 1], out[MAXN + 1];
void init(int _n) {
  n = _n;
  m = 0;
}
void setobj(long double *cf) {
  for (int i = (0); i < (n); i++) A[0][i] = cf[i];
  A[0][n] = 0;
}
void addeq(long double *cf, long double vl) {
  m++;
  for (int i = (0); i < (n); i++) A[m][i] = cf[i];
  A[m][n] = vl;
}
void pivot(int a, int b) {
  for (int i = (0); i <= (m); ++i)
    if (i != a && sgn(A[i][b]))
      for (int j = (0); j <= (n); ++j)
        if (j != b) A[i][j] -= A[a][j] * A[i][b] / A[a][b];
  for (int j = (0); j <= (n); ++j)
    if (j != b) A[a][j] /= A[a][b];
  for (int i = (0); i <= (m); ++i)
    if (i != a) A[i][b] /= -A[a][b];
  A[a][b] = 1 / A[a][b];
  swap(basis[a], out[b]);
}
long double simplex() {
  for (int j = (0); j < (n); j++) A[0][j] = -A[0][j];
  for (int i = (0); i <= (m); ++i) basis[i] = -i;
  for (int j = (0); j <= (n); ++j) out[j] = j;
  for (;;) {
    int ii = 1, jj = 0;
    for (int i = (1); i <= (m); ++i)
      if (make_pair(A[i][n], basis[i]) < make_pair(A[ii][n], basis[ii])) ii = i;
    if (A[ii][n] > -eps) break;
    for (int j = (0); j < (n); j++)
      if (A[ii][j] < A[ii][jj]) jj = j;
    if (A[ii][jj] > -eps) return -inf;
    pivot(ii, jj);
  }
  for (;;) {
    int ii = 1, jj = 0;
    for (int j = (0); j < (n); j++)
      if (make_pair(A[0][j], out[j]) < make_pair(A[0][jj], out[jj])) jj = j;
    if (A[0][jj] > -eps) break;
    for (int i = (1); i <= (m); ++i)
      if (A[i][jj] > eps &&
          (A[ii][jj] < eps || make_pair(A[i][n] / A[i][jj], basis[i]) <
                                  make_pair(A[ii][n] / A[ii][jj], basis[ii])))
        ii = i;
    if (A[ii][jj] < eps) return +inf;
    pivot(ii, jj);
  }
  for (int j = (0); j < (n); j++) X[j] = 0;
  for (int i = (1); i <= (m); ++i)
    if (basis[i] >= 0) X[basis[i]] = A[i][n];
  return A[0][n];
}
};  // namespace simplex
int n, k;
int ty[123], cc[123];
int sn[123], sc, fr[123];
int var[123][123], vut;
long double cst[123 * 123];
int ans;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = (0); i < (n); i++) scanf("%d", ty + i), ty[i]--;
  for (int i = (0); i < (n); i++) scanf("%d", cc + i);
  simplex::init(n * (n - 1) / 2);
  for (int i = (0); i < (n); i++) {
    if (!sn[ty[i]]) {
      sn[ty[i]] = 1;
      sc++;
      if (sc <= k) fr[i] = 1, ans += cc[ty[i]];
    }
  }
  for (int i = (0); i < (n); i++)
    for (int j = (i + 1); j < (n); j++) {
      var[i][j] = vut++;
    }
  for (int i = (0); i < (n); i++) {
    int flin = !fr[i];
    for (int j = (0); j < (vut); j++) cst[j] = 0;
    for (int j = (0); j < (i); j++) cst[var[j][i]] = -1;
    simplex::addeq(cst, -flin + 1e-9);
    for (int j = (0); j < (vut); j++) cst[j] = 0;
    for (int j = (i + 1); j < (n); j++) cst[var[i][j]] = 1;
    simplex::addeq(cst, 1 + 1e-9);
  }
  for (int j = (0); j < (vut); j++) cst[j] = 0;
  for (int i = (0); i < (n); i++)
    for (int j = (i + 1); j < (n); j++)
      if (ty[i] != ty[j]) cst[var[i][j]] = -cc[ty[j]];
  simplex::setobj(cst);
  printf("%d\n", ans - int(simplex::simplex() - 0.1));
  return 0;
}
