#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, r;
    cin >> n >> r;
    long long ans = 0;
    if (n <= r)
      cout << (n * (n - 1)) / 2 + 1 << "\n";
    else
      cout << r * (r + 1) / 2 << "\n";
  }
}
