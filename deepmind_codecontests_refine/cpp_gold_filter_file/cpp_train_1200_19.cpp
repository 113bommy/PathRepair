#include <bits/stdc++.h>
using namespace std;
vector<int> sieve(long long int n) {
  vector<int> primes;
  vector<bool> is(n + 1, true);
  for (int i = 2; i <= n; ++i) {
    if (is[i]) primes.push_back(i);
    for (int p : primes) {
      int d = i * p;
      if (d > n) break;
      is[d] = false;
      if (i % p == 0) break;
    }
  }
  return primes;
}
const int M = 320000;
const vector<int> primes = sieve(M);
long long int r, ndr, nv, n;
long long int check(long long int v) {
  return v >= ndr ? (n / v - 1) : (nv - v);
}
vector<long long int> S;
vector<long long int> V;
long long int pi_0(long long int n) {
  r = (long long int)sqrt(n);
  ndr = n / r;
  nv = r + ndr - 1;
  S.resize(nv + 1);
  V.resize(nv + 1);
  for (long long int i = 0; i < r; i++) {
    V[i] = n / (i + 1);
  }
  for (long long int i = r; i < nv; i++) {
    V[i] = V[i - 1] - 1;
  }
  for (long long int i = 0; i < nv; i++) {
    S[i] = V[i] - 1;
  }
  for (long long int p = 2; p <= r; p++) {
    if (S[nv - p] > S[nv - p + 1]) {
      long long int sp = S[nv - p + 1];
      long long int p2 = p * p;
      for (long long int i = 0; i < nv; i++) {
        if (V[i] >= p2) {
          S[i] -= 1LL * (S[check(V[i] / p)] - sp);
        } else
          break;
      }
    }
  }
  long long int ans = S[0];
  return ans;
}
int main() {
  ;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  pi_0(n);
  long long int res = 0;
  long long int l = (int)floor(cbrtl(n));
  res += S[check(l)];
  for (auto p : primes) {
    if (1LL * p * p > n) break;
    res += (S[check(n / p)] - S[check(p)]);
  }
  cout << res << "\n";
  return 0;
}
