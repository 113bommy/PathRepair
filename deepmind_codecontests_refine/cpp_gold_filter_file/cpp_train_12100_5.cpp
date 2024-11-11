#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((b - a) % (c + d) == 0) {
      cout << (b - a) / (c + d) << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}
