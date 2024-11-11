#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 5;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, x;
    cin >> n >> x;
    long long o = 0, e = 0;
    for (long long i = 0; i < n; i++) {
      long long a;
      cin >> a;
      if (a % 2 == 0)
        e++;
      else
        o++;
    }
    long long f = 0;
    for (long long i = 1; i <= min(o, x); i += 2) {
      if (e >= (x - i)) {
        f = 1;
        break;
      }
    }
    if (f)
      cout << "Yes"
           << "\n";
    else
      cout << "No"
           << "\n";
  }
}
