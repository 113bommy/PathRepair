#include <bits/stdc++.h>
using namespace std;
const long long M = 998244353;
const long long MN = 2020;
inline long long mul(long long a, long long b) { return a * b % M; }
long long bp(long long b, long long p) {
  long long ac = 1;
  while (p) {
    if (p & 1) {
      ac = mul(ac, b);
    }
    b = mul(b, b);
    p >>= 1;
  }
  return ac;
}
inline long long norm(long long b) { return ((b % M) + M) % M; }
long long inv(long long b) { return bp(b, M - 2); }
long long dp[MN][MN];
long long ch(long long n, long long k) {
  if (k < 0 || k > n) return 0;
  if ((k == 0) || (k == n)) return 1;
  if (dp[n][k] != -1) return dp[n][k];
  long long res = ch(n - 1, k - 1) + ch(n - 1, k);
  if (res >= M) {
    res -= M;
  }
  return dp[n][k] = res;
}
long long dq[MN];
long long calc(long long p) {
  if (dq[p] != -1) return dq[p];
  long long res = 0;
  long long sn = 1;
  for (int i = 0; i <= p; i++) {
    res += (ch(p, i) * sn) % M * inv(p + i + 1) % M;
    sn = M - sn;
  }
  res = mul(norm(res), bp(2, p));
  return dq[p] = res;
}
long long get(long long n, long long k) {
  long long res = 0;
  long long sn = 1;
  for (int i = k; i <= n; i++) {
    res += (ch(n - k, i - k) * sn) % M * calc(i) % M;
    sn = M - sn;
  }
  return norm(res);
}
int main() {
  long long n, k, l;
  cin >> n >> k >> l;
  memset(dq, -1, sizeof(dq));
  memset(dp, -1, sizeof(dp));
  long long res = 0;
  for (int i = k; i <= n; i++) {
    res += mul(get(n, i), ch(n, i));
  }
  res = mul(res, norm(l));
  cout << norm(res) << '\n';
}
