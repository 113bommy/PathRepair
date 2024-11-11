#include <bits/stdc++.h>
const int limitN = 50;
using Array = double[limitN + 1][limitN + 1];
struct Matrix {
  double val[limitN + 1][limitN + 1];
};
void multiply(const Matrix &m, const double v[], double dest[]) {
  for (int i = 0; i <= limitN; ++i)
    for (int j = 0; j <= limitN; ++j) dest[j] += m.val[i][j] * v[i];
}
Matrix operator*(const Matrix &l, const Matrix &r) {
  Matrix ret{};
  for (int i = 0; i <= limitN; ++i)
    for (int j = 0; j <= limitN; ++j)
      for (int k = 0; k <= limitN; ++k)
        ret.val[i][k] += l.val[j][k] * r.val[i][j];
  return ret;
}
inline Matrix quickPow(Matrix a, unsigned int e) {
  Matrix ret{};
  for (int i = 0; i <= limitN; ++i) ret.val[i][i] = 1;
  for (; e; e >>= 1) {
    if (e & 0x01) ret = ret * a;
    a = a * a;
  }
  return ret;
}
Array exact, exactInit2, expect;
void dpProbability(const double p) {
  static Array prob, probInit2;
  prob[1][1] = p;
  prob[1][2] = probInit2[1][2] = 1 - p;
  for (int i = 2; i <= limitN; ++i) {
    prob[i][1] = p;
    prob[i][2] = 1 - p + p * p;
    probInit2[i][2] = 1 - p;
    for (int j = 3; j <= i + 1; ++j) {
      prob[i][j] = prob[i - 1][j - 1] * prob[i][j - 1];
      probInit2[i][j] = probInit2[i - 1][j - 1] * probInit2[i][j - 1];
    }
  }
  for (int i = 1; i <= limitN; ++i)
    for (int j = 1; j <= i + 1; ++j) {
      exact[i][j] = prob[i][j] * (1 - prob[i - 1][j]);
      exactInit2[i][j] = probInit2[i][j] * (1 - prob[i - 1][j]);
    }
}
void dpExpect() {
  for (int i = 1; i <= limitN; ++i) expect[1][i] = i;
  for (int i = 2; i <= limitN; ++i) {
    {
      double acc = 0;
      for (int j = 2; j <= limitN; ++j) {
        expect[i][1] += expect[i - 1][j] * exactInit2[i - 1][j];
        acc += exactInit2[i - 1][j];
      }
      expect[i][1] = 1 + expect[i][1] / acc;
    }
    {
      double accVal = expect[i - 1][1] * exact[i - 1][1],
             accProb = exact[i - 1][1];
      for (int j = 2; j <= limitN; ++j) {
        expect[i][j] = j + accVal / accProb;
        accVal += expect[i - 1][j] * exact[i - 1][j];
        accProb += exact[i - 1][j];
      }
    }
  }
}
Matrix buildMatrix() {
  Matrix ret{};
  ret.val[0][0] = 1;
  for (int i = 1; i <= limitN; ++i) ret.val[0][i] = i;
  {
    const double *const exact = exactInit2[limitN];
    const double acc =
        std::accumulate(exact + 2, exact + limitN + 1, double(0));
    for (int j = 2; j <= limitN; ++j) ret.val[j][1] = exact[j] / acc;
  }
  {
    const double *const cExact = exact[limitN];
    double acc = cExact[1];
    for (int i = 2; i <= limitN; ++i) {
      for (int j = 1; j < i; ++j) ret.val[j][i] = cExact[j] / acc;
      acc += cExact[i];
    }
  }
  return ret;
}
double sumExpect(const double *const exact, const double exp[]) {
  double ret = 0;
  for (int i = 0; i <= limitN; ++i) ret += exact[i] * exp[i];
  return ret;
}
int main() {
  std::ios::sync_with_stdio(false);
  int n, p;
  std::cin >> n >> p;
  const double prob = p / 1e9;
  dpProbability(prob);
  dpExpect();
  std::cout.setf(std::ios::fixed);
  std::cout.precision(12);
  if (n <= limitN)
    std::cout << sumExpect(exact[n], expect[n]) << "\n";
  else {
    static double dest[limitN + 10];
    expect[limitN][0] = 1;
    multiply(quickPow(buildMatrix(), n - limitN), expect[limitN], dest);
    std::cout << sumExpect(exact[limitN], dest) << "\n";
  }
  return 0;
}
