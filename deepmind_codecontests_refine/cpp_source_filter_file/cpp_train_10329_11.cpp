#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 6;
const long long inf = 1e18;
long long mod, fac[MAX];
int main() {
  long long a, n, q, x;
  cin >> n >> mod;
  fac[0] = 1;
  for (int i = 1; i < n + 1; i++) fac[i] = (fac[i - 1] * i) % mod;
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    ans += ((((fac[i + 1] * (n - i)) % mod) * fac[n - i]) % mod);
    ans = ans % mod;
  }
  cout << (ans + (n * fac[n]) % mod) << endl;
}
