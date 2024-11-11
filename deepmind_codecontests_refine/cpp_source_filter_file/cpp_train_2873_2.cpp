#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, s = 0, mod = 1000000007;
  cin >> n;
  unsigned long long int pow[n + 1], a[n];
  pow[0] = 1;
  for (unsigned long long int i = 0; i < n; i++) {
    cin >> a[i];
    pow[i + 1] = (2 * pow[i]) % mod;
  }
  sort(a, a + n);
  for (unsigned long long int i = 0; i < n; i++) {
    s += ((pow[i] % mod) * (a[i] % mod)) % mod;
    s -= (((pow[n - i - 1]) % mod) * (a[i] % mod)) % mod;
  }
  while (s < 0) s += mod;
  cout << s;
}
