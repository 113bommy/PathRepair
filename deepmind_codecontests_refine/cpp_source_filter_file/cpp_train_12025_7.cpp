#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, h, k, a, z = 0, x = 0, p = 100000000000000000;
  cin >> n;
  for (a = 1; a <= n; a++) {
    cin >> h >> k;
    if (k < p) {
      z = k;
    }
    x = x + h * z;
  }
  cout << x;
  return 0;
}
