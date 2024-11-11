#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b % 2 == 0) return (power((a * a) % 998244353, b / 2)) % 998244353;
  return (a * (power((a * a) % 998244353, b / 2)) % 998244353) % 998244353;
}
long long int modInv(long long int n) { return power(n, 1000000007 - 2); }
long long int nCr(long long int n, long long int r,
                  long long int p = 1000000007) {
  if (r == 0) return 1;
  long long int Fact[n + 1];
  Fact[0] = 1;
  for (long long int i = 1; i <= n; i++) {
    Fact[i] = (Fact[i - 1] * i) % p;
  }
  return (((Fact[n] * modInv(Fact[r])) % 1000000007) *
          (modInv(Fact[n - r]) % 1000000007)) %
         1000000007;
}
double PI = 3.14159265359;
void solve() {
  long long int n, j, i;
  cin >> n;
  long long int A[n];
  for (i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(A, A + n);
  long long int DP[n][405];
  for (i = 0; i < n; i++)
    for (j = 1; j <= 400; j++) DP[i][j] = 1e9;
  for (i = 0; i <= 400; i++) {
    DP[0][i] = abs(A[0] - i);
    if (i > 0) DP[0][i] = min(DP[0][i], DP[0][i - 1]);
  }
  for (i = 1; i < n; i++) {
    for (j = 2; j <= 400; j++) {
      DP[i][j] = min(DP[i - 1][j - 1] + abs(A[i] - j), DP[i][j]);
      DP[i][j] = min(DP[i][j - 1], DP[i][j]);
    }
  }
  cout << DP[n - 1][400] << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve();
  }
}
