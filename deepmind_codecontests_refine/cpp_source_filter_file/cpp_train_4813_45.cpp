#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long a, b, c, t, A, B, C, res;
  cin >> t;
  while (t--) {
    long long ans = 1000000;
    cin >> a >> b >> c;
    for (long long i = 1; i <= 10000; i++) {
      for (long long j = i; j <= 10000; j += i) {
        for (long long k = j; k <= 10000; k += j) {
          res = abs(a - i) + abs(b - j) + abs(c - k);
          if (res < ans) {
            ans = res;
            A = i;
            B = j;
            C = k;
          }
        }
      }
    }
    cout << ans << "\n" << A << " " << B << " " << C << "\n";
  }
}
