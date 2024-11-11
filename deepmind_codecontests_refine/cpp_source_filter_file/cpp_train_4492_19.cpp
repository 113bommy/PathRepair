#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const double PI = 3.141592653589793238463;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  bool b = false;
  long long n, x, y, k;
  cin >> n >> x >> y;
  for (int i = 1; i <= (y - (n - 1)); i++) {
    if ((n - 1) + i * i >= x) {
      cout << i << '\n';
      b = true;
      break;
    }
  }
  if (!b)
    cout << -1 << '\n';
  else
    for (int i = 0; i < n - 1; i++) cout << 1 << '\n';
  return 0;
}
