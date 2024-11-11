#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
const long long inf = numeric_limits<long long>::max() / 2;
const long double eps = 1e-9;
const long double pi = acos(-1);
long long n;
set<long long> ss;
long long solve() {
  if (n < 50) {
    for (long long i = 0; i <= n; i++) {
      for (long long j = 0; j <= n; j++) {
        for (long long k = 0; k <= n; k++) {
          for (long long m = 0; m <= n; m++) {
            if (i + j + k + m == n) {
              ss.insert(i + 5 * j + 10 * k + 50 * m);
            }
          }
        }
      }
    }
    return (long long)((ss).size());
  } else {
    return 9 * n - 27;
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  cout << solve() << "\n";
  return 0;
}
