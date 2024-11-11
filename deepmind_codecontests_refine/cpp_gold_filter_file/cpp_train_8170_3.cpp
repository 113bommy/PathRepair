#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b;
  cin >> a >> b;
  if (a < b) {
    cout << -1;
    return 0;
  }
  long long tmp = (a + b) / (2 * b);
  double tmp1 = tmp;
  double res = (a + b) / (2 * tmp1);
  printf("%.12f", res);
}
