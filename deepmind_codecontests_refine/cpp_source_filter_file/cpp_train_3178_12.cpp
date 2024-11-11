#include <bits/stdc++.h>
using namespace std;
long long n, b, p, ans;
int main() {
  cin >> n >> b >> p;
  long long m = n;
  while (true) {
    long long p = 2;
    while (p <= m) {
      p *= 2;
    }
    p = p / 2;
    m = p / 2 + m - p;
    ans += (2 * b + 1) * p / 2;
    if (m <= 1) break;
  }
  cout << ans << " " << n * p;
  return 0;
}
