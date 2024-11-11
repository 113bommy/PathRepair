#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long low = 1;
  long long high = n * m;
  while (low <= high) {
    long long med = floor((low + high) / 2);
    long long numBelow = 0;
    long long upTo = min(med, n);
    long long myself = 0;
    for (int y = 1; y <= upTo; y++) {
      if (floor(med / y) > m) {
        numBelow += m;
      } else {
        numBelow += floor(med / y);
      }
      if (med % y == 0 && floor(med / y) < m) {
        ++myself;
      }
    }
    if (k > (numBelow - myself) && k <= numBelow) {
      cout << (int)med << endl;
      return 0;
    }
    if (k > (numBelow)) {
      low = med + 1;
    } else {
      high = med - 1;
    }
  }
  cout << low << endl;
}
