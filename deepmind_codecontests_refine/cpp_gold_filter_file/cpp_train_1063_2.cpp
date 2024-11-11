#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int k1 = (n - m) / (m + 1), k2 = (n - m) % (m + 1);
    cout << 1ll * n * (n + 1) / 2 - 1ll * (m + 1) * k1 * (k1 + 1) / 2 -
                1ll * k2 * (k1 + 1)
         << endl;
  }
  return 0;
}
