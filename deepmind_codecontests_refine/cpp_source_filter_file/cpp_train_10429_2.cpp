#include <bits/stdc++.h>
using namespace std;
const int N = 1011110;
int phi[N];
int n, k;
int main() {
  cin >> n >> k;
  if (k == 1) {
    cout << 3 << endl;
    return 0;
  }
  for (int i = 1; i <= n; ++i) phi[i] = i;
  for (int i = 2; i <= n; ++i) {
    if (phi[i] == i) {
      phi[i] = i - 1;
      for (int j = 2 * i; j <= n; j += i) phi[j] = (phi[j] / i) * (i - 1);
    }
  }
  sort(phi + 1, phi + n + 1);
  int ans = 0;
  for (int i = 1; i <= k + 2; ++i) ans += phi[i];
  cout << ans << endl;
}
