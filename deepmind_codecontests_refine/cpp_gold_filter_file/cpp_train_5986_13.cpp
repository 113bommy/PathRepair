#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int D = 60;
int X[maxn], Y[maxn];
int n;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline int norm(int a) { return a < n ? a : a - n; }
int boundary(int a, int b) {
  a = norm(a);
  b = norm(b);
  int x = X[b] - X[a], y = Y[b] - Y[a];
  return gcd(abs(x), abs(y)) - 1;
}
long double area(int a, int b, int c) {
  a = norm(a);
  b = norm(b);
  c = norm(c);
  int x0 = X[c] - X[a], y0 = Y[c] - Y[a];
  int x1 = X[b] - X[a], y1 = Y[b] - Y[a];
  return 0.5 * llabs(1ll * x0 * y1 - 1ll * x1 * y0);
}
void solve() {
  cin >> n;
  for (int i = 0; i < (n); ++i) cin >> X[i] >> Y[i];
  long double P = 0, B = boundary(0, 1);
  for (int i = 2; i < n; ++i) {
    P += area(0, i - 1, i);
    B += boundary(i - 1, i);
  }
  B += boundary(n - 1, 0) + n;
  long double res = P - 0.5 * B + 1.0;
  int d = min(D, n - 1);
  long double tmp_nom = 0, tmp_den = 0;
  if (n < D) {
    tmp_nom = 1.0 / (1ll << n);
    tmp_den = tmp_nom * (1ll + 1ll * n + 1ll * n * (n - 1) / 2ll);
  }
  for (int i = 0; i < (n); ++i) {
    P = 0;
    B = boundary(i, i + 1) + 2;
    long double bb = 0;
    for (int j = 2; j < d; ++j) {
      P += area(i, i + j - 1, i + j);
      B += boundary(i + j - 1, i + j) - bb;
      bb = boundary(i, i + j);
      B += bb + 1;
      long double w = P - 0.5 * B + 1.0;
      w += bb;
      long double nom = 1.0 / (1ll << (j + 1));
      long double den = 1.0;
      if (n < D) {
        nom -= tmp_nom;
        den -= tmp_den;
      }
      w = w * nom / den;
      res -= w;
    }
  }
  cout << setprecision(10) << res << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) solve();
  return 0;
}
