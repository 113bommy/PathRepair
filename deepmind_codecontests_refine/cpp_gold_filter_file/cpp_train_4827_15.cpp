#include <bits/stdc++.h>
using namespace std;
double f, x3, x2, x1;
int n;
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> f;
    x2 = x2 + ((2 * x1 + 1)) * f;
    x1 = (x1 + 1) * f;
  }
  printf("%.8lf", x2);
}
