#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, b, p = 0, q = 0, ans = 0;
  cin >> m >> b;
  for (long long p = 0; p <= b * m; p += m) {
    long long q = ((p * -1) / m) + b;
    long long temp =
        ((p * (p + 1) / 2) * (q + 1)) + ((q * (q + 1) / 2) * (p + 1));
    ans = max(ans, temp);
  }
  cout << ans << endl;
}
