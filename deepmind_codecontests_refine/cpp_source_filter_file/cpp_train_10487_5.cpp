#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int a, b, c, n;
  cin >> a >> b >> c >> n;
  if ((min(min(a, b), c) >= n) || (n - (a + b - c) < 1) || (min(a, b) >= c))
    return cout << -1, 0;
  cout << n - (a + b - c);
}
