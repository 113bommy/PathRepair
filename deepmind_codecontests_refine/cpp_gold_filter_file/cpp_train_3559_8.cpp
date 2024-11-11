#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1 << 62;
const int iINF = 1 << 30;
const long long MOD = 1e9 + 7;
const double PI = 3.14159265359;
int main() {
  long n, p;
  cin >> n >> p;
  for (int m = 0; m <= 31; m++) {
    long x = n - m * p;
    if (x < m) continue;
    int setbit = 0;
    for (int bit = 0; bit <= 31; bit++) {
      if ((x & (1 << bit)) != 0) setbit++;
    }
    if (setbit <= m) {
      cout << m << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
  return 0;
}
