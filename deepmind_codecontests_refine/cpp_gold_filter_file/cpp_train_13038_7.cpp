#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    double n, m;
    cin >> n >> m;
    if (n * m == 1.0)
      cout << 1 << endl;
    else {
      cout << int(ceil((n * m) / 2.0)) << endl;
    }
  }
}
