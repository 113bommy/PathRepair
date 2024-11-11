#include <bits/stdc++.h>
using namespace std;
long long s, k, m, x, n;
int main() {
  cin >> n;
  s = 2;
  for (long long i = 1; i <= n; i++) {
    long long nx = (i + 1) * i;
    cout << (nx * nx - s) / i << "\n";
    s = nx;
  }
}
