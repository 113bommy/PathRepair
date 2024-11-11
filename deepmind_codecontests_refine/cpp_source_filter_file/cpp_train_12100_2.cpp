#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a - b) % (c + d) == 0) {
      cout << (a - b) / (c + d) << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}
