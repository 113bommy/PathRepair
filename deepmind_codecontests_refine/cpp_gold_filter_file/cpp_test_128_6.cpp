#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long MOD = 998244353;
long long gcd(long long a, long long b) {
  while (b != 0) {
    long long c = a % b;
    a = b;
    b = c;
  }
  return a;
}
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (int i = 3; i < n; ++i) {
      if (gcd(n - i, i - 1) == 1) {
        cout << n - i << " " << i - 1 << " " << 1 << '\n';
        break;
      }
    }
  }
  return 0;
}
