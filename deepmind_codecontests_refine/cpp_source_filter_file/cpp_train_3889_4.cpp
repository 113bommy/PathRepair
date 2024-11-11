#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const long double pi = acos(-1.0);
const long double inf = 1e+9;
#pragma comment(linker, "/STACK:36777216")
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
long long xabs(long long a) { return a > 0 ? a : -a; }
long long c[1000][1000];
long long sx[1000], sy[1000];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < m; k++) {
      cin >> c[i][k];
      sx[i] += c[i][k];
      sy[k] += c[i][k];
    }
  }
  long long xn;
  long long xmin = inf;
  for (int i = 0; i < n + 1; i++) {
    long long t = 0;
    for (int k = 0; k < n; k++) {
      t += sx[k] * ((k - i) * 4 + 2) * ((k - i) * 4 + 2);
    }
    if (t < xmin) {
      xmin = t;
      xn = i;
    }
  }
  long long yn;
  long long ymin = inf;
  for (int i = 0; i < m + 1; i++) {
    long long t = 0;
    for (int k = 0; k < m; k++) {
      t += sy[k] * ((k - i) * 4 + 2) * ((k - i) * 4 + 2);
    }
    if (t < ymin) {
      ymin = t;
      yn = i;
    }
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      res += c[i][j] * (((xn - i - 1) * 4 + 2) * ((xn - i - 1) * 4 + 2) +
                        ((yn - j - 1) * 4 + 2) * ((yn - j - 1) * 4 + 2));
    }
  }
  cout << res << endl << xn << " " << yn << endl;
  return 0;
}
