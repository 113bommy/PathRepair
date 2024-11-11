#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long exp(long long b, long long e) {
  long long ans = 1;
  while (e) {
    if (e & 1) {
      ans = (ans * b) % mod;
    }
    b = (b * b) % mod;
    e >>= 1;
  }
  return ans;
}
vector<long long> combinatoric(long long n, long long k) {
  vector<long long> ans(k + 1);
  ans[0] = 1;
  for (long long i = 0; i < k; i++) {
    ans[i + 1] = (ans[i] * (n + i + 1)) % mod;
    ans[i + 1] = (ans[i + 1] * exp(i + 1, mod - 2)) % mod;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long ans = (exp(2, n + 1) - 1 + mod) % mod;
  vector<long long> combi = combinatoric(n, n);
  long long nodes = exp(2, n);
  for (int i = 0; i < n; i++) {
    nodes = (nodes * 2) % mod;
    nodes = (nodes - 2 * combi[i] + mod) % mod;
    ans = (ans + nodes) % mod;
  }
  cout << ans << '\n';
  return 0;
}
