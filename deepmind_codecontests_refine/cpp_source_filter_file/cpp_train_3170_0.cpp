#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, s = 0, ss = 0;
  cin >> x;
  string z, zz, zzz;
  cin >> z;
  zz = z;
  s++;
  for (int i = 1; i < x; i++) {
    cin >> z;
    if (z == zz)
      s++;
    else if (z != zz) {
      ss++;
      zzz = z;
    }
  }
  if (s - ss == 1)
    cout << zz;
  else
    cout << zzz;
}
