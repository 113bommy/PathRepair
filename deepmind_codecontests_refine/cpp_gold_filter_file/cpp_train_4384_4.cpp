#include <bits/stdc++.h>
using namespace std;
string s;
long long n, m, t, k, q, x, y, l, r, a, b, res;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < k; ++i) {
    res += 2 * (n + m - 2);
    n -= 4;
    m -= 4;
  }
  cout << res;
  return 0;
}
