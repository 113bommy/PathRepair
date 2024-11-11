#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, t, r = 0;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    r = pow(min(max((a + a), b), max((b + b), a)), 2);
    cout << r << endl;
  }
  return 0;
}
