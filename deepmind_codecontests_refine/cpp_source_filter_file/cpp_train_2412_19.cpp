#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 5;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long r;
  cin >> r;
  for (long long i = 1; i * i <= r; i++) {
    long long y = r - i * i - i - 1;
    if (y > 0 && y % (2 * i) == 0) {
      cout << i << " " << y / (2 * i) << '\n';
      return 0;
    }
  }
  cout << "No" << '\n';
  return 0;
}
