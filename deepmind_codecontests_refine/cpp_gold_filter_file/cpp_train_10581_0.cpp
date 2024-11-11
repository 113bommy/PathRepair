#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  double mn = 100.0;
  double r;
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    r = x / y;
    if (r < mn) {
      mn = r;
    }
  }
  printf("%.8lf\n", mn * m);
}
