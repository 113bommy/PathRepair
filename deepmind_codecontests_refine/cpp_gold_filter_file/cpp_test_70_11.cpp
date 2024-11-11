#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long binpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = ans * a % MOD;
    }
    b /= 2;
    a = a * a % MOD;
  }
  return ans;
}
long long inv(long long a) { return binpow(a, MOD - 2); }
long long get_sum(long long n) { return (n * (n + 1) / 2) % MOD; }
long long get_sum2(long long n) {
  return n * (n + 1) % MOD * (2 * n + 1) % MOD * inv(6) % MOD;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  mt19937 rnd(239);
  int n, q;
  cin >> n >> q;
  vector<long long> a(2 * n);
  vector<long long> sum(2 * n, 0), sum2(2 * n, 0);
  long long val = rnd() % MOD;
  for (int i = 0; i < 2 * n; i++) {
    if (i < n) {
      long long first;
      cin >> first;
      first = (first + val) % MOD;
      a[i] = first;
    } else {
      a[i] = a[i - n];
    }
    if (i) {
      sum[i] = sum[i - 1];
      sum2[i] = sum2[i - 1];
    }
    sum[i] = (sum[i] + a[i]) % MOD;
    sum2[i] = (sum2[i] + a[i] * a[i]) % MOD;
  }
  while (q--) {
    int l, r;
    long long d;
    cin >> l >> r >> d;
    if (r < l) {
      r += n;
    }
    l--;
    r--;
    long long sm = sum[r];
    if (l) {
      sm = (sm - sum[l - 1] + MOD) % MOD;
    }
    long long sm2 = sum2[r];
    if (l) {
      sm2 = (sm2 - sum2[l - 1] + MOD) % MOD;
    }
    long long len = r - l + 1;
    long long a =
        (sm + MOD - len * (len - 1) / 2 % MOD * d % MOD) * inv(len) % MOD;
    long long sm22 = len * a % MOD * a % MOD +
                     d * d % MOD * get_sum2(len - 1) % MOD +
                     2LL * a % MOD * d % MOD * get_sum(len - 1) % MOD;
    sm22 %= MOD;
    cout << (sm22 == sm2 ? "Yes\n" : "No\n");
  }
  return 0;
}
