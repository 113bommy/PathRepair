#include <bits/stdc++.h>
using namespace std;
int main() {
  int al, ar;
  int bl, br;
  cin >> al >> ar >> bl >> br;
  if (al - 1 <= br && (br / 2 + br % 2 - 1) <= al) {
    cout << "YES";
  } else if (ar - 1 <= bl && (bl / 2 + bl % 2 - 1) <= ar) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
