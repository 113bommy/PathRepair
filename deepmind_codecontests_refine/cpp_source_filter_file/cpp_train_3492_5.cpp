#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, pow = 1;
  cin >> n;
  if (n % 2 == 1) {
    n--;
    cout << n / 2;
  } else {
    while (pow * 2 < n) {
      pow *= 2;
    }
    n -= pow;
    cout << n / 2;
  }
  return 0;
}
