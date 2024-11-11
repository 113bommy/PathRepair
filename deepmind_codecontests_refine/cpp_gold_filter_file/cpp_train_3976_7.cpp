#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, p;
    cin >> a >> b >> p;
    if (a + p <= b)
      cout << 0 << endl;
    else {
      cout << min(a + p - (a + p + b) / 2, p + 1) << endl;
    }
  }
  return 0;
}
