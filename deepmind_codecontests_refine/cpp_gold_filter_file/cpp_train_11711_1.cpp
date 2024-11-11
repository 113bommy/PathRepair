#include <bits/stdc++.h>
#pragma GCC optimize(2)
struct Complex {
  double A, B;
  Complex() : A(0), B(0) {}
  Complex(double A_) : A(A_), B(0){};
  Complex(double A_, double B_) : A(A_), B(B_){};
};
inline Complex operator+(const Complex &A, const Complex &B) {
  return Complex(A.A + B.A, A.B + B.B);
}
inline Complex operator-(const Complex &A, const Complex &B) {
  return Complex(A.A - B.A, A.B - B.B);
}
inline Complex operator*(const Complex &A, const Complex &B) {
  return Complex(A.A * B.A - A.B * B.B, A.A * B.B + A.B * B.A);
}
inline Complex &operator/=(Complex &A, const double B) {
  return A.A /= B, A.B /= B, A;
}
int dis[70][70];
int n, m, t, x;
int A[105], B[105], C[105];
std::vector<int> son[105];
double P[105][40050];
double S[105][40050];
double dp[105][40050];
Complex tmp1[200000], tmp2[200000];
const double pi = acosl(-1);
Complex w[200000], wn[200000];
int lim, lims, rev[200000];
void FFTinit(int N) {
  w[0] = 1, lim = 1, lims = -1;
  while (lim < N) lim <<= 1, lims++;
  Complex g(cosl(2 * pi / lim), sinl(2 * pi / lim));
  for (int i = 1; i < lim; i++) w[i] = w[i - 1] * g;
  for (int i = 1; i < lim; i++) rev[i] = rev[i >> 1] >> 1 | (i & 1) << lims;
}
void FFT(Complex *V, int f) {
  for (int i = 0; i < lim; i++)
    if (rev[i] > i) std::swap(V[rev[i]], V[i]);
  for (int i = 1; i < lim; i <<= 1) {
    for (int j = 0, t = lim / i / 2; j < i; j++) wn[j] = w[j * t];
    for (int j = 0; j < lim; j += i + i) {
      for (int k = 0; k < i; k++) {
        Complex X = V[j + k], Y = V[i + j + k] * wn[k];
        V[j + k] = X + Y, V[i + j + k] = X - Y;
      }
    }
  }
  if (!f) {
    std::reverse(V + 1, V + lim);
    for (int k = 0; k < lim; k++) V[k] /= lim;
  }
}
int sum = 0;
void solve(int L, int R) {
  if (L == R) {
    if (L > t)
      for (int i = 1; i <= n; i++) dp[i][L] = dis[i][n] + x;
    else {
      for (int i = 1; i <= n; i++) {
        dp[i][L] = std::numeric_limits<double>::max();
        for (std::vector<int>::iterator it = son[i].begin(); it != son[i].end();
             ++it)
          dp[i][L] = std::min(dp[i][L], S[*it][L] + C[*it]);
      }
      dp[n][L] = 0;
    }
    return;
  }
  int mdl = (L + R) >> 1;
  solve(mdl + 1, R);
  for (int i = 1; i <= m; i++) {
    FFTinit(R - L + 2 + R - mdl + 2);
    sum += lim;
    for (int j = 0; j < lim; j++) tmp1[j] = Complex();
    for (int j = 0; j < lim; j++) tmp2[j] = Complex();
    for (int j = mdl + 1; j <= R; j++) tmp1[j - mdl] = dp[B[i]][j];
    for (int j = 1; j <= R - L + 1; j++) tmp2[R - L - j + 2] = P[i][j];
    FFT(tmp1, 1), FFT(tmp2, 1);
    for (int j = 0; j < lim; j++) tmp1[j] = tmp1[j] * tmp2[j];
    FFT(tmp1, 0);
    for (int j = L; j <= mdl; j++) S[i][j] += tmp1[R - L + 2 - (mdl - j)].A;
  }
  solve(L, mdl);
}
int main() {
  scanf("%d%d%d%d", &n, &m, &t, &x);
  memset(dis, 0x3f, sizeof(dis));
  for (int i = 1; i <= n; i++) dis[i][i] = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &A[i], &B[i], &C[i]);
    son[A[i]].push_back(i);
    dis[A[i]][B[i]] = C[i];
    for (int j = 1; j <= t; j++) scanf("%lf", &P[i][j]), P[i][j] /= 100000;
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
  solve(0, t + t);
  printf("%.8lf\n", dp[1][0]);
}
