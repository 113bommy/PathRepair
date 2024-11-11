#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, b, r;
  cin >> n >> m;
  b = 3;
  r = 1;
  while (n > 0) {
    if (n % 2 != 0) r = (r * b) % m;
    b = (b * b) % m;
    n = n / 2;
  }
  cout << (r - 1) % m;
  return 0;
}
