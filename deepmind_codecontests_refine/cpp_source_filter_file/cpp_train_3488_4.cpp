#include <bits/stdc++.h>
using namespace std;
long long x, pocz, kon, k;
long long ile(long long x) {
  if (x == -1) return 0;
  return (x / k) + 1;
}
int main() {
  cin >> k >> pocz >> kon;
  if (pocz >= 0 && kon >= 0) cout << ile(kon) - ile(pocz - 1);
  if (pocz < 0 && kon > 0) cout << ile(kon) + ile(-pocz) - 1;
  if (pocz < 0 && kon < 0) cout << ile(-pocz) - ile(-kon);
  return 0;
}
