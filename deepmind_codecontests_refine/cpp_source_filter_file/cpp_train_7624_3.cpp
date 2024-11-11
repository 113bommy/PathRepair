#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, t, r = 0;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    r = min(max((a + a), b), max((b + b), a));
    cout << r << endl;
  }
  return 0;
}
