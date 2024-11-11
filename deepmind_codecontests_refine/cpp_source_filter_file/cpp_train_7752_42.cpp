#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1E-9;
vector<long double> x, y;
long double x0, goodlife;
int n, k;
long double PE;
long double d[200][200], p[200];
long double dist(int i) {
  return sqrt((x[i] - x0) * (x[i] - x0) +
              (y[i] - goodlife) * (y[i] - goodlife));
}
long double calc(long double R) {
  memset(d, 0, sizeof d);
  d[0][0] = 1;
  long double res = 0;
  for (int i = 0; i < (int)n; i++) {
    if (dist(i) < R + EPS)
      p[i] = 1;
    else
      p[i] = exp(1 - dist(i) * dist(i) / (R * R));
  }
  for (int i = 0; i < (int)n; i++)
    for (int j = 0; j < (int)n; j++) {
      d[i + 1][j] += d[i][j] * (1 - p[i]);
      d[i + 1][j + 1] += d[i][j] * p[i];
    }
  for (int i = (int)k; i < (int)n + 1; i++) res += d[n][i];
  return res;
}
void solve() {
  cout.precision(10);
  cout.setf(ios::fixed);
  int cntZero = 0;
  for (int i = 0; i < (int)n; i++)
    if (abs(x[i] - x0) < EPS && abs(y[i] - goodlife) < EPS) cntZero++;
  if (cntZero >= k) {
    cout << 0.0 << endl;
    return;
  }
  long double L = 1E-7, R = 1E+3;
  for (int step = 0; step < (int)1000; step++) {
    long double mid = (L + R) / 2;
    if (calc(mid) > PE - EPS)
      R = mid;
    else
      L = mid;
  }
  cout << L << endl;
}
bool read() {
  if (!(cin >> n)) return false;
  cin >> k >> PE;
  PE /= 1000;
  PE = 1 - PE;
  cin >> x0 >> goodlife;
  x.resize(n);
  y.resize(n);
  for (int i = 0; i < (int)n; i++) cin >> x[i] >> y[i];
  return true;
}
int main() {
  while (read()) solve();
}
