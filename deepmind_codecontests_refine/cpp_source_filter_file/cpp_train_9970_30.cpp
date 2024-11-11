#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int INF = 1e9 + 7;
const double eps = 1e-6;
const int base = 131;
const int MAXN = 1e6 + 7;
int n, res[14] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292, 341, 390};
int main() {
  cin >> n;
  if (n <= 13)
    cout << res[13] << endl;
  else
    cout << 1ll * res[13] + 1ll * 49 * (n - 13) << endl;
  return 0;
}
