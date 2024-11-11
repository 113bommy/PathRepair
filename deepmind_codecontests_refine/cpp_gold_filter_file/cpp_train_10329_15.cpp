#include <bits/stdc++.h>
using namespace std;
long long f[250009];
int main() {
  long long n, m;
  cin >> n >> m;
  f[0] = 1;
  for (long long i = 1; i <= n; i++) f[i] = f[i - 1] * i % m;
  long long ans = 0;
  for (long long k = 1; k <= n; k++) {
    ans += (n - k + 1) * (n - k + 1) % m * (f[k] * f[n - k] % m);
    ans = ans % m;
  }
  cout << ans << endl;
}
