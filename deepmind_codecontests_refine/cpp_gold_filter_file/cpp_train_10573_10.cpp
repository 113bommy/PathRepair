#include <bits/stdc++.h>
using namespace std;
int k2, k3, k5, k6, k = 0, l = 0;
int main() {
  cin >> k2 >> k3 >> k5 >> k6;
  k = 256 * min(k2, min(k5, k6));
  k2 -= min(k2, min(k5, k6));
  ;
  l = 32 * min(k2, k3);
  k += l;
  cout << k;
}
