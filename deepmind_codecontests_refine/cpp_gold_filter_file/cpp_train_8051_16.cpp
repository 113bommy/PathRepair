#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double a, b = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    b = b + a / 100;
  }
  cout << setprecision(10) << 100 * b / n;
  return 0;
}
