#include <bits/stdc++.h>
using namespace std;
int o, e, oC, eC, n, en;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> en;
    if (en % 2 == 0) {
      e = i;
      eC++;
    } else {
      o = i;
      oC++;
    }
  }
  if (oC == 1)
    cout << o;
  else
    cout << e;
}
