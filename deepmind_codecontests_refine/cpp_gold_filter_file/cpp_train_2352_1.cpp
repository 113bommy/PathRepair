#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> ar;
  int n, m, k, aux1, mig, luc, aux, aMig, aLuc;
  bool band = false;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> aux;
    if (i < m) {
      if ((aux <= k) && (aux != 0)) {
        mig = i + 1;
      }
    } else {
      if ((aux <= k) && (band == false) && (aux != 0)) {
        luc = i + 1;
        band = true;
      }
    }
  }
  aMig = abs(mig - m);
  aLuc = abs(luc - m);
  aux1 = min(aMig, aLuc);
  cout << aux1 * 10;
  return 0;
}
