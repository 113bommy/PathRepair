#include <bits/stdc++.h>
using namespace std;
const int mo = 1e9 + 7;
int main() {
  long long a, b, n;
  while (cin >> a >> b) {
    n = b - 1;
    long long ans = 0;
    for (int k = 1; k <= a; ++k) {
      ans = (ans + (((((k * b) % mo) * ((n * (n + 1) / 2) % mo)) % mo +
                     (n * (n + 1) / 2) % mo)) %
                       mo) %
            mo;
    }
    cout << ans % mo << endl;
  }
}
