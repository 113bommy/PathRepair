#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  double n, m, x, y;
  cin >> n >> m;
  printf("%.7lf\n", abs((1.0 * n * n - m * m) / (2.0 * n)));
  return 0;
}
