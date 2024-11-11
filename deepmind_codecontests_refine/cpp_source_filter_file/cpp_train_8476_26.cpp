#include <bits/stdc++.h>
using namespace std;
const double h = 0.00001;
int main() {
  double n;
  cin >> n;
  for (int j = 1; j <= 10; j++)
    for (int i = 1; i <= 10; i++) {
      double pom1 = (double)i / 2;
      double pom2 = pom1 * pom1 + j * j;
      double pom3 = fabs(n * n * pom2 - pom1 * pom1 * j * j);
      if (pom3 < h) {
        cout << i << " " << j << endl;
        return 0;
      }
    }
  return 0;
}
