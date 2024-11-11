#include <bits/stdc++.h>
using namespace std;
int main() {
  string d;
  cin >> d;
  int o = 0, z = 0;
  bool res = false;
  for (auto i : d) {
    if (i == '1') {
      o++;
      z = 0;
    } else if (i == '0') {
      z++;
      o = 0;
    }
    if (z == 7 || o == 7) {
      cout << "YES" << endl;
      res = true;
      break;
    }
  }
  if (!res) cout << "NO" << endl;
  return 0;
}
