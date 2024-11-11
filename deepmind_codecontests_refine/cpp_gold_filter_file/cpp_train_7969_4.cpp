#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, fSide, sSide;
  cin >> n;
  if (n < 3) {
    cout << -1 << endl;
  } else if (n % 2 == 0) {
    fSide = (n * n) / 4 - 1;
    sSide = (n * n) / 4 + 1;
    cout << fSide << " ";
    cout << sSide << endl;
  } else {
    sSide = (n * n) / 2;
    fSide = sSide + 1;
    cout << sSide << " ";
    cout << fSide << endl;
  }
  return 0;
}
