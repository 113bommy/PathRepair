#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, p, N, mod = 10, ans, m;
  cin >> n >> p;
  ans = N = n;
  while (n > mod && N - n <= p) {
    m = n % mod;
    mod *= 10;
    if (m == mod / 10 - 1) continue;
    n -= m + 1;
    if (N - n <= p) ans = n;
  }
  cout << ans << "\n";
}
