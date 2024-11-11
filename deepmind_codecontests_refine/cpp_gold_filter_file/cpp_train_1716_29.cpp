#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int main() {
  long long v, a1, b1, a2, b2;
  cin >> v >> a1 >> a2 >> b1 >> b2;
  long long x = max(b1, b2);
  if (x * x >= v) {
    if (b1 < b2) swap(a1, a2), swap(b1, b2);
    long long ans = 0;
    for (int i = 0; i <= v / b1; i++) {
      ans = max(ans, i * a1 + (v - i * b1) / b2 * a2);
    }
    cout << ans << endl;
  } else {
    if (1.0 * a1 / b1 > 1.0 * a2 / b2) {
      swap(a1, a2), swap(b1, b2);
    }
    long long ans = 0;
    for (int i = 0; i < b2; i++) {
      ans = max(ans, i * a1 + (v - i * b1) / b2 * a2);
    }
    cout << ans << endl;
  }
  return 0;
}
