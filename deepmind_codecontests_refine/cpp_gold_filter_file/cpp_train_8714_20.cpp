#include <bits/stdc++.h>
using namespace std;
const int inf = (1e9) + 5;
using namespace std;
int main() {
  int n, m, k, l;
  cin >> n;
  string s[9], q[9], z[9];
  s[0] = "purple";
  z[0] = "Power";
  s[1] = "green";
  z[1] = "Time";
  s[2] = "blue";
  z[2] = "Space";
  s[3] = "orange";
  z[3] = "Soul";
  s[4] = "red";
  z[4] = "Reality";
  s[5] = "yellow";
  z[5] = "Mind";
  cout << 6 - n << endl;
  for (int i = 0; i < n; i++) {
    cin >> q[i];
  }
  for (int j = 0; j < 6; j++) {
    int err = 0;
    for (int i = 0; i < n; i++)
      if (q[i] == s[j]) {
        err = 1;
        break;
      }
    if (err == 0) cout << z[j] << endl;
  }
}
