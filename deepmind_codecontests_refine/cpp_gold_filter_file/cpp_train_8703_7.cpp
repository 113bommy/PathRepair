#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6 + 5;
const int inf = (int)1e9 * 2;
const int mod = (int)1e9 + 7;
long long cnt, x, y, l, r, k;
double a, b, res;
int main() {
  ios::sync_with_stdio(false);
  cin >> l >> r >> x >> y >> k;
  for (int i = x; i <= y; i++) {
    if (l <= i * k && i * k <= r) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
