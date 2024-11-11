#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int MAX = 100005;
const int MAX1 = 2007;
const int MAX2 = 4007;
const int LEN = 21;
const int BASE = 1000000000;
const double EPS = 1e-7;
const int MOD = 1234567891;
int sp[MAX], curr[MAX], n, p;
bool solve(double m) {
  double sum = 0;
  for (int i = (0); i < (n); ++i) {
    sum += max(0.0, sp[i] * m - curr[i]) / m;
  }
  return sum <= p;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ifstream in("");
  ofstream out("");
  cin >> n >> p;
  int suma = 0;
  for (int i = (0); i < (n); ++i) {
    cin >> sp[i] >> curr[i];
    suma += sp[i];
  }
  if (suma <= p) {
    cout << -1 << endl;
    return 0;
  }
  double lo = 0, hi = 1e11, mid;
  while (lo + 1e-4 < hi) {
    mid = (lo + hi) / 2;
    if (solve(mid))
      lo = mid;
    else
      hi = mid - 1e-5;
  }
  cout << fixed << setprecision(15) << mid << endl;
  return 0;
}
