#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int maxN = 1e6 + 5;
int A[maxN], B[maxN];
int main() {
  long long n;
  cin >> n;
  A[0] = 1;
  for (long long i = 1; i <= n; ++i) A[i] = (A[i - 1] * (n - i + 1)) % mod;
  B[0] = 1;
  for (long long i = 1; i <= n; ++i) B[i] = (B[i - 1] * i) % mod;
  long long ans = 1;
  for (long long i = 0; i <= n; ++i) {
    ans += (A[i] * (B[n - i] - 1)) % mod;
    ans %= mod;
  }
  cout << ans << "\n";
}
