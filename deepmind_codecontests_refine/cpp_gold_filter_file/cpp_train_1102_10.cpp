#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    double a, b;
    cin >> a >> b;
    if (b == 0) {
      cout << "1";
    } else if (a == 0) {
      cout << "0.5";
    } else {
      b *= 4;
      double prob = a * b;
      prob += (double)(min(a, b) * min(a, b)) / 2.0;
      prob += (a > b) ? ((a - b) * b) : 0;
      prob /= (a * 2 * b);
      cout << prob;
    }
    cout << endl;
  }
  return 0;
}
