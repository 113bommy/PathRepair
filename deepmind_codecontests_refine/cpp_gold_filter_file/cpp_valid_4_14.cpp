#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, b, p, k, pj;
  int a[2000], q;
  cin >> t;
  for (int i = 0; i < t; i++) {
    q = 2;
    pj = 0;
    cin >> p;
    for (int j = 2; j < p; j++) {
      pj = 0;
      k = p % j;
      for (int l = 2; l < q; l++) {
        if (k == a[l]) {
          cout << l << ' ' << j << endl;
          pj = 1;
          break;
        }
      }
      if (pj == 1) break;
      a[q++] = k;
    }
  }
  return 0;
}
