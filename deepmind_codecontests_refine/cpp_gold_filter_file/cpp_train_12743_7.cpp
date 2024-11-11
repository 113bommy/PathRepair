#include <bits/stdc++.h>
using namespace std;
const int MAX = 2005;
double min(double a, double b) { return a < b ? a : b; }
int main() {
  double a, low, s;
  int n, m;
  cin >> n;
  m = s = 0;
  for (int i = 0; i < n * 2; i++) {
    cin >> a;
    low = a - (int)a;
    if (low != 0) {
      m++;
      s += low;
    }
  }
  cout.precision(3);
  double result = fabs(s - n);
  for (int i = 1; i <= n * 2 - m; i++) result = min(result, fabs(s - n + i));
  cout << fixed << result;
  return 0;
}
