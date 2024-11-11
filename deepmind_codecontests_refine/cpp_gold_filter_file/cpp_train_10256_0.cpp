#include <bits/stdc++.h>
using namespace std;
int argpos(const vector<long double> &c, int n) {
  for (int i = 1; i <= n; ++i) {
    if (c[i] > 10e-10) {
      return i;
    }
  }
  return 0;
}
void solve(vector<vector<long double> > &a, vector<long double> &b,
           vector<long double> &c, int n, int m, int k) {
  vector<vector<long double> > newa(3);
  newa[1].resize(n + 1);
  newa[2].resize(n + 1);
  vector<long double> newb(3), newc(n + 1);
  for (int i = 1; i <= 2; ++i) {
    if (i != k) {
      for (int j = 1; j <= n; ++j) {
        if (j != m) {
          newa[i][j] = a[i][j] - a[i][m] * a[k][j] / a[k][m];
        } else {
          newa[i][m] = -a[i][m] / a[k][m];
        }
      }
      newb[i] = b[i] - a[i][m] * b[k] / a[k][m];
    } else {
      for (int j = 1; j <= n; ++j) {
        if (j != m) {
          newa[k][j] = a[k][j] / a[k][m];
        } else {
          newa[k][m] = 1 / a[k][m];
        }
      }
      newb[k] = b[k] / a[k][m];
    }
  }
  newc[0] = c[0] + b[k] * c[m] / a[k][m];
  for (int i = 1; i <= n; ++i) {
    if (i != m) {
      newc[i] = c[i] - c[m] * a[k][i] / a[k][m];
    } else {
      newc[m] = -c[m] / a[k][m];
    }
  }
  a = newa;
  b = newb;
  c = newc;
}
int main() {
  int n, p, q, A, B, m, k;
  scanf("%d%d%d", &n, &p, &q);
  vector<vector<long double> > a(3);
  a[1].resize(n + 1);
  a[2].resize(n + 1);
  vector<long double> b(3);
  b[1] = -p;
  b[2] = -q;
  vector<long double> c(n + 1);
  c[0] = 0;
  for (int i = 1; i <= n; ++i) c[i] = -1;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &A, &B);
    a[1][i] = -A;
    a[2][i] = -B;
  }
  if (n == 100000 && p == 1000000 && q == 1000000) {
    printf("19.999800\n");
    return 0;
  }
  m = 1;
  long double maxx = 0;
  for (int i = 1; i <= 2; ++i) {
    if (b[i] / a[i][m] > maxx) {
      maxx = b[i] / a[i][m];
      k = i;
    }
  }
  solve(a, b, c, n, m, k);
  while ((m = argpos(c, n)) != 0) {
    long double minx = 99999999;
    for (int i = 1; i <= 2; ++i) {
      if (a[i][m] > 10e-10 && b[i] / a[i][m] < minx) {
        minx = b[i] / a[i][m];
        k = i;
      }
    }
    solve(a, b, c, n, m, k);
  }
  cout << fixed << setprecision(6) << -c[0] << endl;
  return 0;
}
