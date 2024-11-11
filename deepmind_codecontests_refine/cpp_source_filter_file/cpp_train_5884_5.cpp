#include <bits/stdc++.h>
using namespace std;
const int maxn = 0;
int main() {
  unsigned long long int n, m, t, ans = 0;
  cin >> n >> m;
  int i = 0;
  while (pow(2, i) < m) i++;
  for (int j = i; j >= 0; j--) {
    t = pow(2, j);
    for (int v = 0; v < j - 1; v++) {
      unsigned long long int y = pow(2, v);
      if (t - 1 - y >= n && t - 1 - y <= m && t - 1 - y != 1) ans++;
    }
  }
  cout << ans;
}
