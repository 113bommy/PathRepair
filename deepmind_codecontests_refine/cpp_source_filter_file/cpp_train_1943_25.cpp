#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long k;
long long dp[2][1005][1005];
long long recur(long long ok, long long rem, long long near) {
  long long &res = dp[ok][rem][near];
  if (res != -1) return res;
  if (rem == 0) return res = ok;
  res = 0;
  for (long long i = 0; i < ((long long)10); i++) {
    if (i == 4 || i == 7)
      res = (res + recur(ok | near <= k, rem - 1, 1)) % mod;
    else
      res = (res + recur(ok, rem - 1, near + 1)) % mod;
  }
  res %= mod;
  return res;
}
long long cal(string base) {
  long long res = 0, near = k + 1, ok = 0;
  for (long long i = 0; i < ((long long)((long long)base.size())); i++) {
    for (long long j = 0; j < ((long long)base[i] - '0'); j++) {
      if (j == 4 || j == 7)
        res =
            (res + recur(ok | near <= k, ((long long)base.size()) - 1 - i, 1)) %
            mod;
      else
        res =
            (res + recur(ok, ((long long)base.size()) - 1 - i, near + 1)) % mod;
    }
    if (base[i] == '4' || base[i] == '7') {
      if (near <= k) ok = 1;
      near = 1;
    } else {
      near = (near + 1);
    }
  }
  res %= mod;
  return res;
}
long long check(string base) {
  long long res = 0;
  long long before = -k - 1;
  for (long long i = 0; i < ((long long)((long long)base.size())); i++)
    if (base[i] == '4' || base[i] == '7') {
      if (i - before <= k) res = 1;
      before = i;
    }
  return res;
}
int main() {
  for (long long i = 0; i < ((long long)2); i++)
    for (long long j = 0; j < ((long long)1005); j++)
      for (long long k = 0; k < ((long long)1005); k++) dp[i][j][k] = -1;
  long long t;
  cin >> t >> k;
  while (t--) {
    string l;
    cin >> l;
    long long res0 = cal(l);
    cin >> l;
    long long res1 = cal(l);
    cout << (((res1 - res0 + check(l)) % mod + mod) % mod) << endl;
  }
}
