#include <bits/stdc++.h>
using namespace std;
signed main() {
  int n;
  cin >> n;
  for (int x; n--;) {
    cin >> x;
    cout << x - !(x & 1);
  }
  return false;
}
