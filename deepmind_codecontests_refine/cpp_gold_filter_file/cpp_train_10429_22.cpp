#include <bits/stdc++.h>
using namespace std;
long long n, k, ans = 2;
long long phi[1000005];
void ph(long long n) {
  for (long long i = 2; i <= n; i++) phi[i] = i;
  for (long long i = 2; i <= n; i++) {
    if (phi[i] == i) {
      for (long long j = i; j <= n; j += i) phi[j] = (phi[j] / i) * (i - 1);
    }
  }
}
int main() {
  cin >> n >> k;
  if (k == 1)
    cout << 3 << "\n";
  else {
    ph(n);
    sort(phi + 3, phi + n + 1);
    for (long long i = 3; i <= k + 2; i++) ans += phi[i];
    cout << ans << "\n";
  }
  return 0;
}
