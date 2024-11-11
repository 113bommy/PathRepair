#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long INF = 1 << 29;
const long long MAX_N = 1e6 + 7;
long long f[100001];
long long pow(long long a, long long b, long long MOD) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y);
      if (x > MOD) x %= MOD;
    }
    y = (y * y);
    if (y > MOD) y %= MOD;
    b /= 2;
  }
  return x;
}
long long InverseEuler(long long n, long long MOD) {
  return pow(n, MOD - 2, MOD);
}
long long nCr(long long n, long long r, long long MOD) {
  return (f[n] *
          ((InverseEuler(f[r], MOD) * InverseEuler(f[n - r], MOD)) % MOD)) %
         MOD;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, ans = 1;
  cin >> n >> k;
  long long sum = 0;
  vector<int> v(n), ind, diff;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    if (v[i] > n - k) {
      sum += v[i];
      ind.push_back(i);
    }
  }
  for (int i = 1; i <= ind.size() - 1; ++i) {
    diff.push_back(ind[i] - ind[i - 1]);
  }
  for (auto x : diff) {
    ans *= x;
    ans %= MOD;
  }
  cout << sum << " " << ans << "\n";
}
