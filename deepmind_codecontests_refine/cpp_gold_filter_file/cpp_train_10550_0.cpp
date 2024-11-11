#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  bool con = false;
  for (int i = 1; i < 32000; i++) {
    double M = 2 * n - i * (i + 1);
    double k = (-1.0 + sqrtl(1 + 4 * M)) / 2.0;
    if (k <= 0) break;
    if (abs((long long int)k - k) <= 1e-9) {
      con = true;
      break;
    }
  }
  if (con)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
