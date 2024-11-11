#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long l = max(a, b);
    long long w = min(a, b);
    if (l >= 2 * w) {
      cout << l * l << endl;
    } else {
      cout << 4 * w * w << endl;
    }
  }
}
