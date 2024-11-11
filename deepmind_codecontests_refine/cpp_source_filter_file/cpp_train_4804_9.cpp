#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const long long INF = 1000000000000000000LL;
const long double PI = 4 * atan((long double)1);
int k;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> k;
  int n = 10;
  while (ceil((k + n) / (n - 1)) > 1e6) ++n;
  cout << n << '\n' << -1;
  int s = k + n;
  for (int i = 1; i < n; ++i) {
    if (s >= 1e6) {
      cout << ' ' << 1000000;
      s -= 1e6;
    } else {
      cout << ' ' << s;
      s = 0;
    }
  }
  cout << '\n';
  return 0;
}
