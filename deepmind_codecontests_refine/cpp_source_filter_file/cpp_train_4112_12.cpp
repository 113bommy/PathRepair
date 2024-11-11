#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, nn, c = 0;
  long long res = 0, nins = 9;
  cin >> n;
  nn = n;
  while (nn) {
    c++, nn /= 10;
    if (nn) res += nins * c, nins *= 10;
  }
  if (c == 1)
    cout << n;
  else {
    res += (n - (int)(pow(10, c - 1) + 1e-9) + 1) * c;
    cout << res;
  }
}
