#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 50;
const int INF = int(1e9) + 100;
long long mul(long long a, long long b, long long m) {
  return ((a % m) * (b % m)) % m;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long d, m;
    cin >> d >> m;
    long long x = log2(d);
    long long st = pow(2, x);
    long long c = 1, i, ans = 1;
    for (i = 0; i <= x; i++) {
      if (i == x) {
        ans = mul(ans, (d - st + 2), m);
      } else {
        ans = mul(ans, (c + 1), m);
        c = c * 2;
      }
    }
    ans = (ans % m - 1 % m + m) % m;
    cout << ans << endl;
  }
  return 0;
}
