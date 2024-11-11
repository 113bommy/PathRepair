#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b;
  cin >> t;
  while (t--) {
    cin >> a;
    cin >> b;
    if (a > b - a) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
