#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int n, times;
int x[100];
double p[2][100][100];
double f1[101][100];
double g1[101][100];
double f2[100][101];
double g2[100][102];
double f3[100][101];
double g3[100][102];
int c2(int n) { return n * (n + 1) / 2; }
void run() {
  scanf("%d%d", &n, &times);
  for (int i = (0); i < (n); ++i) scanf("%d", &x[i]);
  if (times > 2000) times = 2000;
  int at = 0;
  for (int i = (0); i < (n); ++i)
    for (int j = (i + 1); j < (n); ++j) p[at][i][j] = 0;
  double den = .5 * n * (n + 1);
  for (int t = (0); t < (times); ++t) {
    int to = 1 - at;
    for (int j = (0); j < (n); ++j) {
      f1[0][j] = 0;
      for (int i = (0); i < (n); ++i) f1[i + 1][j] = f1[i][j] + p[at][i][j];
    }
    for (int j = (0); j < (n); ++j) {
      g1[0][j] = 0;
      for (int i = (0); i < (n); ++i) g1[i + 1][j] = g1[i][j] + f1[i][j];
    }
    for (int i = (0); i < (n); ++i) {
      f2[i][0] = 0;
      for (int j = (0); j < (n); ++j) f2[i][j + 1] = f2[i][j] + p[at][i][j];
    }
    for (int i = (0); i < (n); ++i) {
      g2[i][0] = 0;
      for (int j = (0); j <= (n); ++j) g2[i][j + 1] = g2[i][j] + f2[i][j];
    }
    for (int k = (0); k < (n); ++k) {
      f3[k][0] = 0;
      for (int l = (0); l < (n - k); ++l)
        f3[k][l + 1] = f3[k][l] + 1 - p[at][l][k + l];
    }
    for (int k = (0); k < (n); ++k) {
      g3[k][0] = 0;
      for (int l = (0); l <= (n - k); ++l) g3[k][l + 1] = g3[k][l] + f3[k][l];
    }
    for (int i = (0); i < (n); ++i)
      for (int j = (i + 1); j < (n); ++j) {
        p[to][i][j] = 0;
        p[to][i][j] += p[at][i][j] * c2(i);
        p[to][i][j] +=
            (g1[j + 1][j] - g1[i + 1][j]) - (g1[j - i][j] - g1[0][j]);
        p[to][i][j] += (g3[j - i][n - j + i + 1] - g3[j - i][i + 1]) -
                       (g3[j - i][n - j] - g3[j - i][0]);
        p[to][i][j] += p[at][i][j] * c2(j - i - 1);
        p[to][i][j] += (g2[i][n + 1] - g2[i][j + 1]) -
                       (g2[i][i + n - j + 1] - g2[i][i + 1]);
        p[to][i][j] += p[at][i][j] * c2(n - j - 1);
        p[to][i][j] /= den;
      }
    at = to;
  }
  double ret = 0;
  for (int i = (0); i < (n); ++i)
    for (int j = (i + 1); j < (n); ++j) {
      if (x[i] > x[j])
        ret += 1 - p[at][i][j];
      else
        ret += p[at][i][j];
    }
  printf("%.9lf\n", ret);
}
int main() {
  run();
  return 0;
}
