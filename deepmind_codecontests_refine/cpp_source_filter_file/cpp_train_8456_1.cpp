#include <bits/stdc++.h>
using namespace std;
bool checkint(float k) { return floor(k) == k; }
int main() {
  int test;
  cin >> test;
  int n;
  for (int t = 0; t < test; t++) {
    cin >> n;
    for (int k = 2; k <= n; k++) {
      double sum = n / (pow(2, k) - 1);
      if (checkint(sum)) {
        cout << std::setprecision(0) << fixed << sum << endl;
        break;
      }
    }
  }
}
