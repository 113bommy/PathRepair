#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int reminder;
    int s;
    if (r / 2 > l && r > 1) {
      s = r / 2;
      reminder = r % (s + 1);
    } else {
      s = l;
      reminder = r % s;
    }
    cout << reminder << endl;
  }
  return 0;
}
