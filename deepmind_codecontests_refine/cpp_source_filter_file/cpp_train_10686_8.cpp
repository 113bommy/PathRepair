#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, q, i, j, k, ln, rn;
  cin >> n >> q;
  for (i = 0; i < q; i++) {
    cin >> k;
    k--;
    while (true) {
      ln = (k + 1) / 2;
      rn = n - ln;
      if (k % 2 == 0) {
        break;
      }
      k += rn;
    }
    cout << k / 2 + 1 << endl;
  }
}
