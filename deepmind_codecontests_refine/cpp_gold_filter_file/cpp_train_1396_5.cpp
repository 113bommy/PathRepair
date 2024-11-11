#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-3;
const int INF = (long double)(1e9);
const long long mod = (int)(1e+9 + 7);
const int N = (int)(1e7 + 100);
int days_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
  long long a, b;
  cin >> a >> b;
  long long k = 0;
  while (a > 0 && b > 0) {
    if (a > b) {
      k += a / b;
      a %= b;
    } else {
      k += b / a;
      b %= a;
    }
  }
  cout << k;
  return 0;
}
