#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, h;
  cin >> n >> h;
  double h1;
  h1 = h / sqrt(n);
  for (long long i = 1; i <= n - 1; i++) {
    h = sqrt(i) * h1;
    cout << fixed << setprecision(10) << h << " ";
  }
  return 0;
}
