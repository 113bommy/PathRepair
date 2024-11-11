#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, n, mod = 1e9 + 7;
  cin >> n;
  a = 1;
  b = 1;
  for (int i = 1; i <= n * 3; i++) a = (a * 3) % mod;
  for (int i = 1; i <= n; i++) b = (b * 7) % mod;
  cout << (a - b + mod) % mod;
  return 0;
}
