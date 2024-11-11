#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, b;
  cin >> m >> b;
  long long ans = -1;
  for (long long y = 0; y <= b; y++) {
    long long x = m * (b - y);
    if ((double)y / m <= (double)(b - x)) {
      ans = max(ans, (x + 1) * y * (y + 1) / 2 + (y + 1) * x * (x + 1) / 2);
    }
  }
  cout << ans;
}
