#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string x;
  cin >> x;
  string b;
  cin >> b;
  string nw;
  for (int i = 0; i < x.size(); i++) {
    if (i == 0) {
      nw += x[i];
    } else {
      if (x[i] <= x[i - 1]) {
        nw += x[i];
      } else {
        break;
      }
    }
  }
  nw += b[0];
  cout << nw;
  return 0;
}
