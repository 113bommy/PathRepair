#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a == b) {
      cout << 0 << '\n';
    } else if (abs(a - b) <= 10) {
      cout << 1 << '\n';
    } else if (abs(a - b) % 10 != 0) {
      cout << (abs(b - a) / 10) + 1 << '\n';
    } else {
      cout << (abs(a - b) / 10) << '\n';
    }
  }
  return 0;
}
