#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 7;
long long n, k;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  long long mx = n * (n - 1) / 2;
  if (k >= mx) return cout << "no solution", 0;
  long long y = 0;
  for (long long i = 1; i < n; i++, y += 2) cout << 0 << " " << y << "\n";
  cout << 0 << " " << y - 1;
  return 0;
}
