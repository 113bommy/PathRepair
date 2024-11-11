#include <bits/stdc++.h>
using namespace std;
int o, e, oC, eC, n, en;
int main() {
  cin >> n;
  for (int i = 0; i <= n; i++) {
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
    cout << o + 1;
  else
    cout << e + 1;
}
