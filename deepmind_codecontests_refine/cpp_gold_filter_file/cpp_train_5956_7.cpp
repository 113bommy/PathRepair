#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int MAXN = 2e5 + 100;
long long stab(long long a) { return ((a % MOD + MOD) % MOD); }
array<long long, MAXN> fact;
long long pw(long long a, long long b) {
  if (b == 0) {
    return 1;
  } else if (b % 2 == 0) {
    return pw(stab(a * a), b / 2);
  } else {
    return stab(a * pw(a, b - 1));
  }
}
long long obr(long long a) { return pw(a, MOD - 2); }
long long c_n_k(long long n, long long k) {
  if (k > n) {
    return 0;
  }
  return stab(stab(fact[n] * obr(fact[k])) * obr(fact[n - k]));
}
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  fact[0] = 1;
  for (long long i = 1; i < MAXN; ++i) {
    fact[i] = stab(fact[i - 1] * i);
  }
  long long n, k;
  cin >> n >> k;
  vector<long long> vec(n);
  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
  }
  long long c1 = 0;
  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    if (vec[i] != vec[j]) {
      c1++;
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= c1; ++i) {
    long long cur = 0;
    if (i % 2 == 1) {
      cur = pw(2, i) * obr(2);
    } else {
      cur = pw(2, i) - c_n_k(i, (i / 2));
      cur %= MOD;
      cur += MOD;
      cur %= MOD;
      cur *= obr(2);
    }
    cur %= MOD;
    cur *= pw(k, n - c1);
    cur %= MOD;
    cur *= pw(k - 2, c1 - i);
    cur %= MOD;
    cur *= c_n_k(c1, i);
    cur %= MOD;
    ans += cur;
  }
  ans %= MOD;
  cout << ans << endl;
  return 0;
}
