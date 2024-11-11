#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int SIZE = 1e6 + 10;
long long mypow(long long x, long long y) {
  x %= MOD;
  long long res = 1 % MOD;
  while (y) {
    if (y & 1) res = res * x % MOD;
    y >>= 1;
    x = x * x % MOD;
  }
  return res;
}
long long Rand() {
  return rand() * (1ll << 48) + rand() * (1ll << 32) + rand() * (1ll << 16) +
         rand();
}
long long mul(long long a, long long b, long long m) {
  long long i, res = 0;
  for (i = 1; i <= b; i *= 2, (a *= 2) %= m)
    if (b & i) (res += a) %= m;
  return res;
}
long long pow(long long n, long long k, long long m) {
  if (k == 0) return 1;
  if (k % 2 == 1) return mul(n, pow(n, k - 1, m), m);
  n = pow(n, k / 2, m);
  return mul(n, n, m);
}
bool witness(long long a, long long n) {
  long long x, y, u, t;
  for (u = n - 1, t = 0; u % 2 == 0; u /= 2, t++)
    ;
  x = pow(a, u, n);
  while (t--) {
    y = x;
    x = pow(x, 2, n);
    if (x == 1 && y != 1 && y != n - 1) return 1;
  }
  return x != 1;
}
bool mr(long long n, int s = 25) {
  if (n - 1 >= 2 && witness(2, n)) return 0;
  if (n - 1 >= 3 && witness(3, n)) return 0;
  if (n - 1 >= 5 && witness(5, n)) return 0;
  if (n - 1 >= 179 && witness(179, n)) return 0;
  if (n - 1 >= 9137 && witness(9137, n)) return 0;
  if (n - 1 >= 28087 && witness(28087, n)) return 0;
  return 1;
}
bitset<1000000> p;
pair<long long, long long> pp[200000], ker[200000];
int pn, kn;
int main() {
  long long A;
  cin >> A;
  for (int i = 2; i < 1000000; i++) {
    if (!p[i]) {
      for (long long j = (long long)i * i; j < 1000000; j += i) p[j] = 1;
      long long now = i;
      while (now < 1000000000000LL) {
        pp[pn++] = make_pair(now, i);
        now *= i;
      }
    }
  }
  sort(pp, pp + pn);
  for (long long i = 1; i * i <= A; i++) {
    if (A % i == 0) {
      if (i != 1) {
        int it = lower_bound(pp, pp + pn, make_pair(i - 1LL, 0LL)) - pp;
        if (pp[it].first + 1 == i) ker[kn++] = make_pair(pp[it].second, i);
      }
      if (A / i != i) {
        int it = lower_bound(pp, pp + pn, make_pair(A / i - 1LL, 0LL)) - pp;
        if (pp[it].first + 1 == A / i)
          ker[kn++] = make_pair(pp[it].second, A / i);
        else {
          if (A / i > 1000000) {
            if (mr(A / i - 1)) {
              ker[kn++] = make_pair(A / i - 1, A / i);
            }
          }
        }
      }
    }
  }
  sort(ker, ker + kn);
  map<long long, long long> dp[2];
  int lv = 0;
  dp[lv][1LL] = 1;
  for (int i = 0, j; i < kn; i = j) {
    dp[lv ^ 1].clear();
    for (map<long long, long long>::iterator it = dp[lv].begin();
         it != dp[lv].end(); it++) {
      dp[lv ^ 1][it->first] += it->second;
      for (j = i; j < kn && ker[j].first == ker[i].first; j++) {
        if ((A / it->first) % ker[i].second) continue;
        dp[lv ^ 1][it->first * ker[i].second] += it->second;
      }
    }
    lv ^= 1;
  }
  long long an = 0;
  for (map<long long, long long>::iterator it = dp[lv].begin();
       it != dp[lv].end(); it++) {
    if (it->first == A) an += it->second;
  }
  cout << an << endl;
  return 0;
}
