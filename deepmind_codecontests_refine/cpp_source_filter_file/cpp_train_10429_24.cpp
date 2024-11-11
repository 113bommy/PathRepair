#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int phi[maxn];
int main() {
  int n, k;
  cin >> n >> k;
  if (k == 3) {
    cout << 3 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) phi[i] = i;
  for (int i = 2; i <= n; i++) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) phi[j] = phi[j] / i * (i - 1);
    }
  }
  sort(phi, phi + n + 1);
  long long ans = 0;
  for (int i = 0; i <= k + 2; i++) ans += phi[i];
  cout << ans << endl;
  return 0;
}
