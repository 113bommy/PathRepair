#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  bool az = true, bz = true;
  if (a.size() == b.size()) {
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == '1') az = false;
      if (b[i] == '1') bz = false;
    }
    if (az && bz)
      cout << "YES" << endl;
    else if (!az && !bz)
      cout << "YES" << endl;
    else {
      cout << "NP" << endl;
    }
  } else {
    cout << "NO" << endl;
  }
}
