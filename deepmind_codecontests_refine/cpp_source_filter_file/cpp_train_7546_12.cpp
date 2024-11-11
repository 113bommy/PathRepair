#include <bits/stdc++.h>
using namespace std;
long long int fac[100007], inv[100007];
long long int bigmod(long long int b, long long int p) {
  long long int ans = 1;
  while (p) {
    if (p & 1) ans = (ans * b) % 1000000007;
    p >>= 1;
    b = (b * b) % 1000000007;
  }
  return ans;
}
void pre() {
  fac[0] = 1;
  inv[0] = 1;
  for (long long int i = 1; i < 100007; i++) {
    fac[i] = (fac[i - 1] * i) % 1000000007;
    inv[i] = (inv[i - 1] * bigmod(i, 1000000007 - 2)) % 1000000007;
  }
}
long long int ncr(long long int n, long long int r) {
  long long int t = ((fac[n] * inv[r]) % 1000000007 * inv[n - r]) % 1000000007;
  return t;
}
int main() {
  pre();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  long long int ans = ncr(2 * n - 1, n - 1) * 2 % 1000000007;
  cout << (ans - n + 1000000007) % 1000000007 << endl;
  return 0;
}
