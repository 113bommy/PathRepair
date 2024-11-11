#include <bits/stdc++.h>
using namespace std;
const long long INF = numeric_limits<long long>::max();
const long long LINF = numeric_limits<long long>::max();
const double EPS = 1e-9;
const long long MOD = 1e9 + 7;
const long long MAXN = 1e3 + 3;
double bin_pow(double a, int n) {
  if (n == 0) return 1;
  if (n % 2 == 1)
    return bin_pow(a, n - 1) * a;
  else {
    double m = bin_pow(a, n / 2);
    return m * m;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  double n, t;
  cin >> n >> t;
  double pr = bin_pow(1.000000011, t);
  cout << fixed << setprecision(12) << n + n * pr;
  return 0;
}
