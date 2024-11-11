#include <bits/stdc++.h>
using namespace std;
ifstream f("wow.in");
int ind[506], V[506], pos[506];
double ai[506][506];
double fr[506][506], Pi[506];
double ai2[506][506], P[506], card[106];
double P2[106];
struct MAT {
  double e[106][106];
} aux, _mat, ML;
MAT mul(MAT A, MAT B, int n) {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      aux.e[i][j] = 0;
      for (int t = 1; t <= n; ++t) aux.e[i][j] += A.e[i][t] * B.e[t][j];
    }
  return aux;
}
void sub(double i1[], double i2[], int n, double coef) {
  for (int i = 1; i <= n; ++i) i1[i] += i2[i] * coef;
}
void gauss(double A[][506], int n, int nrb) {
  int i, j;
  for (i = 1; i <= n; ++i) {
    fr[i][i]++;
    A[i][i] = (i <= nrb ? 1 : card[i]);
  }
  for (i = 1; i <= n; ++i) {
    for (j = i; j <= n; ++j)
      if (A[j][i] < -0.0000000000001 || A[j][i] > 0.0000000000001) {
        swap(A[i], A[j]);
        swap(fr[i], fr[j]);
        break;
      }
    for (j = i + 1; j <= n; ++j)
      if (A[j][i] < -0.0000000000001 || A[j][i] > 0.0000000000001) {
        double cf = -A[j][i] / A[i][i];
        sub(A[j], A[i], n, cf);
        sub(fr[j], fr[i], n, cf);
      }
  }
  for (i = n; i > 0; --i) {
    for (j = 1; j < i; ++j) {
      double cf = -A[j][i] / A[i][i];
      sub(A[j], A[i], n, cf);
      sub(fr[j], fr[i], n, cf);
    }
  }
}
int main() {
  cout << fixed;
  cout << setprecision(5);
  int n, m, i, j, nrb = 0, nra = 0, K;
  cin >> n >> m >> K;
  for (i = 1; i <= n; ++i) {
    cin >> V[i];
    if (V[i]) pos[i] = (++nrb);
  }
  for (i = 1; i <= n; ++i)
    if (V[i] == 0) pos[i] = nrb + (++nra);
  for (i = 1; i <= m; ++i) {
    int xx, yy;
    cin >> xx >> yy;
    if (pos[xx] > nrb) ai[pos[xx]][pos[yy]]--;
    if (pos[yy] > nrb) ai[pos[yy]][pos[xx]]--;
    ai2[pos[xx]][pos[yy]]++, ai2[pos[yy]][pos[xx]]++;
    card[pos[yy]]++, card[pos[xx]]++;
  }
  gauss(ai, n, nrb);
  for (i = 1; i <= nrb; ++i) {
    for (j = 1; j <= nrb; ++j) P[j] = 0;
    for (j = nrb + 1; j <= n; ++j) P[j] = fr[j][i] / ai[j][j];
    P[i] = 1;
    Pi[i] = P[pos[1]];
    for (j = 1; j <= nrb; ++j) {
      P2[j] = 0;
      for (int k = 1; k <= n; ++k) P2[j] += ai2[j][k] * P[k];
      ML.e[j][i] = (P2[j] /= card[j]);
    }
    for (j = 1; j <= nrb; ++j) P[j] = P2[j];
  }
  for (i = 1; i <= n; ++i) _mat.e[i][i] = 1;
  K -= 2;
  for (i = 30; i >= 0; --i) {
    _mat = mul(_mat, _mat, nrb);
    if (K & (1 << i)) _mat = mul(_mat, ML, nrb);
  }
  double result = 0;
  for (i = 1; i <= n; ++i) result += _mat.e[i][pos[n]] * Pi[i];
  cout << result << '\n';
  return 0;
}
