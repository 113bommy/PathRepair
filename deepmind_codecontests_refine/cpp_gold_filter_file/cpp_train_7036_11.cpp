#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    long double sum = 0;
    long double v = 0;
    for (int i = 0; i < 250; i++) {
      int t;
      cin >> t;
      sum += t;
      v += t * t;
    }
    long double mean = sum / 250.0;
    long double var = (v / 250.0) - mean * mean;
    ((fabs(mean - var) / mean) > 0.40) ? cout << "uniform\n"
                                       : cout << "poisson\n";
  }
  return 0;
}
