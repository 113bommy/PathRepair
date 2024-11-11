#include <bits/stdc++.h>
using namespace std;
int x, os[100][100], kv[100], otv[100];
;
int prov(int ii) {
  int z = 0;
  for (int i = 1; i < x; i++) {
    for (int iii = 0; iii < kv[i]; iii++) {
      if (os[i][iii] == os[0][ii]) z++;
    }
  }
  return z;
}
int main() {
  cin >> x;
  for (int i = 0; i < x; i++) {
    cin >> kv[i];
    for (int ii = 0; ii < kv[i]; ii++) {
      cin >> os[i][ii];
    }
  }
  for (int ii = 0; ii < kv[0]; ii++) {
    if (prov(ii) == x - 1) otv[ii] = os[0][ii];
  }
  for (int ii = 0; ii < kv[0]; ii++) {
    if (otv[ii] > 0) cout << otv[ii];
  }
}
