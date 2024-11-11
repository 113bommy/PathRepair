#include <bits/stdc++.h>
using namespace std;
const long long LLINF = 1e17 + 7;
const long long INF = 1e9 + 7;
const long long EPS = 1e-9 - 7;
const long long MAX = 1e9 + 7;
const long long MOD = 1e9 + 7;
int a, b, c;
int main() {
  cin >> a >> b >> c;
  double delta = b * b - 4 * a * c;
  double x1 = (-1 * b + sqrt(delta)) / 2 * a;
  double x2 = (-1 * b - sqrt(delta)) / 2 * a;
  cout << setprecision(20) << max(x1, x2) << endl << min(x1, x2);
  return 0;
}
