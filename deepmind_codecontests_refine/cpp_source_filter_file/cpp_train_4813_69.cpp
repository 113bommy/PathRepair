#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long INF = (-1) * 1e18;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, cnt = 0;
    cin >> a >> b >> c;
    long long ans = INT_MAX, x, y, z;
    for (long long i = 1; i < 1e4; i++) {
      for (long long j = i; j <= 1e4; j += i) {
        for (long long k = j; k <= 1e4; k += j) {
          long long res = abs(i - a) + abs(j - b) + abs(k - c);
          if (res < ans) {
            x = i;
            y = j;
            z = k;
            ans = res;
          }
        }
      }
    }
    cout << ans << "\n" << x << " " << y << " " << z << "\n";
  }
}
