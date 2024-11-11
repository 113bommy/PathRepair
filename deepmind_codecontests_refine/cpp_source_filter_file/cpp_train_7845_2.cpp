#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a;
  cin >> t;
  while (t--) {
    cin >> a;
    int x = abs((-360) / (a - 180));
    if (x >= 3) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
