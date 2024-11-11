#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-8;
const long long INF = (long long)(1e18);
const long long mod = (int)(1e+9 + 7);
const int N = (int)(1e5);
int days_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
  long long n, k;
  cin >> n >> k;
  if ((k - 1) * k / 2 + 1 < n) return cout << -1, 0;
  ;
  long long c = 2 * n - 2 - k * (k - 1);
  long long x = (1 + sqrt(1.0 * (1 - 4 * c))) / 2.;
  cout << k - x;
  return 0;
}
