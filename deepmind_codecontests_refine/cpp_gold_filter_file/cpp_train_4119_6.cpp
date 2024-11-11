#include <bits/stdc++.h>
using namespace std;
void multiply(double a[128][128], double b[128][128]) {
  double c[128][128];
  double sum = 0;
  for (int i = 0; i < 128; i++) {
    for (int k = 0; k < 128; k++) {
      for (int j = 0; j < 128; j++) {
        sum = sum + (a[i][j] * b[j][k]);
      }
      c[i][k] = sum;
      sum = 0;
    }
  }
  for (int i = 0; i < 128; i++) {
    for (int j = 0; j < 128; j++) {
      a[i][j] = c[i][j];
    }
  }
}
void power(double f[128][128], double m[128][128], long long int n) {
  if (n == 0 || n == 1) {
    return;
  }
  power(f, m, n / 2);
  multiply(f, f);
  if (n % 2 != 0) {
    multiply(f, m);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  int k;
  cin >> n >> k;
  double d[128];
  for (int i = 0; i < 128; i++) {
    d[128] = 0;
  }
  for (int i = 0; i <= k; i++) {
    double h;
    cin >> h;
    d[i] = h;
  }
  double f[128][128], m[128][128];
  for (int i = 0; i < 128; i++) {
    for (int j = 0; j < 128; j++) {
      f[i][j] = m[i][j] = 0;
    }
  }
  for (int i = 0; i < 128; i++) {
    for (int j = 0; j < 128; j++) {
      f[i][j] = m[i][j] = d[i ^ j];
    }
  }
  power(f, m, n);
  cout << setprecision(14) << 1 - f[0][0];
}
