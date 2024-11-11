#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int inf = (int)1e9;
const int MAX_N = 600;
int main() {
  long long n, x, y;
  cin >> n >> x >> y;
  int ans = (n * y) / 100;
  if ((n * y) % 100) ans++;
  ans -= x;
  cout << ans << endl;
  return 0;
}
