#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, p, tot = 0;
  cin >> n >> p;
  for (int e = 0; e < n; e++) {
    int k;
    cin >> k;
    tot += k;
  }
  for (int e = 1; e <= 1000000; e++) {
    if (tot + e * p <= p * (e + n)) {
      if (2 * (tot + e * p) >= 2 * p * (e + n) - (e + n)) {
        cout << e;
        break;
      }
    } else {
      cout << e;
      break;
    }
  }
}
