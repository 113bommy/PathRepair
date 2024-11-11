#include <bits/stdc++.h>
using namespace std;
long long GCD(long long x, long long y) {
  if (y == 0) return x;
  return GCD(y, x % y);
}
long long LCM(long long x, long long y) { return (x * y) / (GCD(x, y)); }
long long LOGK(long long x, long long k) {
  if (x >= k) return 1 + LOGK(x / k, k);
  return 0;
}
long long MPOW(long long a, long long b, long long m) {
  if (b == 0) return 1;
  long long x = MPOW(a, b / 2, m);
  x = (x * x) % m;
  if (b % 2 == 1) x = (x * a) % m;
  return x;
}
long long MINV(long long a, long long m) { return MPOW(a, m - 2, m); }
class pnc {
  long long FACT_MAX, MODU;
  vector<long long> fact;

 public:
  pnc(long long n, long long m) {
    FACT_MAX = n;
    fact.resize(FACT_MAX);
    MODU = m;
    MFACT_INIT(MODU);
  }
  void MFACT_INIT(long long m) {
    fact[0] = 1;
    for (long long i = 1; i < FACT_MAX; ++i) fact[i] = (i * fact[i - 1]) % MODU;
  }
  long long MFACT(long long n) { return fact[n]; }
  long long PERM(long long n, long long r) {
    return (fact[n] * ::MINV(fact[n - r], MODU)) % MODU;
  }
  long long COMB(long long n, long long r) {
    return (PERM(n, r) * ::MINV(fact[r], MODU)) % MODU;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  while (test--) {
    string str;
    cin >> str;
    long long k;
    cin >> k;
    if (k == 1) {
      cout << str.length();
      continue;
    }
    k--;
    pnc p(1005, 1000000007);
    long long dp[1005] = {0};
    long long cnt[1005] = {1};
    for (long long i = 2; i <= 1000; i++) {
      long long j = __builtin_popcountll(i);
      cnt[i] = j;
      dp[i] = 1 + dp[j];
    }
    long long ans = 0;
    long long n = str.length();
    long long noo = 0;
    for (long long i = 0; i < n; i++) {
      if (str[i] == '0') continue;
      for (long long j = 1; j < n; j++) {
        if (dp[j] == k) {
          if (j - noo <= n - i - 1 && j - noo >= 0) {
            ans += (p.COMB(n - i - 1, j - noo));
            ans %= 1000000007;
          }
        }
      }
      noo++;
    }
    long long no = 0;
    for (long long i = 0; i < n; i++)
      if (str[i] == '1') no++;
    if (dp[no] == k && k != 0) ans++;
    if (k == -1 && n >= 1) ans++;
    ans %= 1000000007;
    cout << ans;
  }
}
