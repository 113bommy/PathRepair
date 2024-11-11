#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  if (a == b)
    cout << "0" << endl;
  else {
    if (a > b) {
      int k = a - b;
      if (k % 2 == 0)
        cout << "1" << endl;
      else
        cout << "2" << endl;
    } else if (b > a) {
      int k = b - a;
      if (k % 2 != 0)
        cout << "1" << endl;
      else
        cout << "2" << endl;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
