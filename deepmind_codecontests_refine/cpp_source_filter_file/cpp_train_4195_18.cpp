#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b * c >= a)
      cout << -1 << endl;
    else {
      long long k = a / (d * b);
      cout << max(a * (k + 1ll) - d * b * k * (k + 1ll) / 2ll, a) << endl;
    }
  }
  return 0;
}
