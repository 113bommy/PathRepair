#include <bits/stdc++.h>
using namespace std;
const int Mod = 1000000007;
long long ksm(long long a, long long b, long long c) {
  long long ans = 1;
  for (; b; b >>= 1, a = a * a % c)
    if (b & 1) ans = ans * a % c;
  return ans;
}
int c(int m, int n) {
  long long s = 1, t = 1;
  for (int i = m; i >= (m - n + 1); i--) s = s * i % Mod;
  for (int i = 1; i <= n; i++) t = t * i % Mod;
  s = s * ksm(t, Mod - 2, Mod) % Mod;
  return s;
}
int main() {
  int n;
  cin >> n;
  cout << (2ll * c(2 * n - 1, n) - n + Mod) % Mod;
  return 0;
}
