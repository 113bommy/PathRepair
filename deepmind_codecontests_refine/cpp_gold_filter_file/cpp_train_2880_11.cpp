#include <bits/stdc++.h>
using namespace std;
int n;
double p[101];
double r;
double pos[110][10000];
double neg[110][10000];
int main() {
  cin >> n;
  for (int i = 0; i <= n; ++i) cin >> p[i];
  for (int i = 0; i < 110; ++i)
    for (int h = 0; h < 10000; ++h) {
      pos[i][h] = -10e100;
      neg[i][h] = -10e100;
    }
  pos[0][0] = 0;
  for (int k = 1; k < 110; ++k) {
    double *z = pos[k - 1];
    double *x = pos[k];
    for (int h = 10000 - 1; h > 0; h--)
      for (int a = n, i = 0; a > 0; a -= 2, i++)
        if (h >= a && z[h - a] >= 0)
          if (x[h] < z[h - a] + p[i]) x[h] = z[h - a] + p[i];
  }
  neg[0][0] = 0;
  for (int k = 1; k < 110; ++k) {
    double *z = neg[k - 1];
    double *x = neg[k];
    for (int h = 10000 - 1; h > 0; h--)
      for (int a = n, i = n; a > 0; a -= 2, i--)
        if (h >= a && z[h - a] >= 0)
          if (x[h] < z[h - a] + p[i]) {
            x[h] = z[h - a] + p[i];
          }
  }
  if (n % 2 == 0) r = p[n / 2];
  for (int i = 1; i < 110; ++i) {
    double *x = pos[i];
    for (int h = 10000 - 2; h >= 0; h--) x[h] = max(x[h + 1], x[h]);
    for (int j = 0; j < 110; ++j) {
      double *z = neg[j];
      for (int h = 0; h < 10000; ++h)
        if (x[h] >= 0 && (z[h] + x[h]) / (i + j) > r) {
          r = (z[h] + x[h]) / (i + j);
        }
    }
  }
  cout.precision(15);
  cout << r << endl;
}
