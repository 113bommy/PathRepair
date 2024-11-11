#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, k;
  cin >> n >> k;
  if (n * (n - 1) / 2 > k) {
    for (long long i = 1; i <= n; i++) cout << 0 << " " << i << "\n";
  } else
    cout << "no solution";
  return 0;
}
