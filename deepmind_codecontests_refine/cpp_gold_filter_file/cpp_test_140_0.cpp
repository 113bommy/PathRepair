#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x = (int)(floor(sqrt(n)));
    int y = (int)(floor(cbrt(n)));
    int z = (int)(floor(pow(n, (1.0 / 6.0)) + 0.00000000005));
    cout << x + y - z << "\n";
  }
  return 0;
}
