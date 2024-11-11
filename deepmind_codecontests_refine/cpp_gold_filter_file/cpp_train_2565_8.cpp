#include <bits/stdc++.h>
using namespace std;
long long pw(long long a, long long e, long long mod) {
  if (e <= 0) return 1;
  long long x = pw(a, e / 2, mod);
  x = (x * x) % mod;
  if (e & 1) x = (x * a) % mod;
  return x;
}
unsigned long long MOD = 998244353LL;
unsigned long long pw(unsigned long long a, unsigned long long e) {
  if (e <= 0) return 1;
  unsigned long long x = pw(a, e / 2);
  x = (x * x) % MOD;
  if (e % 2 != 0) x = (x * a) % MOD;
  return x;
}
unsigned long long proot = 3;
vector<vector<unsigned long long> > OM;
vector<unsigned long long> DFT(vector<unsigned long long> &A, int N, int d,
                               int x, int dir) {
  vector<unsigned long long> ret(N, 0);
  if (N == 1) {
    ret[0] = A[x];
    return ret;
  }
  if (N == 2) {
    ret[0] = (A[x] + A[x + d]) % MOD;
    ret[1] = (A[x] + MOD - A[x + d]) % MOD;
    return ret;
  }
  int dep = 0, n = N;
  while (n > 1) {
    n /= 2;
    dep++;
  }
  vector<unsigned long long> DFT0[2];
  DFT0[0] = DFT(A, N / 2, d * 2, x, dir);
  DFT0[1] = DFT(A, N / 2, d * 2, x + d, dir);
  for (int i = 0; i < N / 2; i++) {
    unsigned long long com = OM[dep][(N + (1LL * dir * i) % N) % N];
    ret[i] = (DFT0[0][i] + com * DFT0[1][i]) % MOD;
    ret[i + N / 2] = (DFT0[0][i] + (MOD - com) * DFT0[1][i]) % MOD;
  }
  return ret;
}
int SN = 1 << 20;
vector<unsigned long long> convolution(vector<unsigned long long> A,
                                       vector<unsigned long long> B) {
  int Smin = 1;
  while (Smin < (int)A.size() * 2) Smin *= 2;
  if (OM.empty()) {
    OM.resize(21);
    for (int i = 0; i < 21; i++) {
      unsigned long long root = pw(proot, (MOD - 1) / (1 << i));
      OM[i].resize(1 << i, 1);
      for (int j = 1; j < (1 << i); j++) OM[i][j] = (OM[i][j - 1] * root) % MOD;
      reverse(begin(OM[i]) + 1, end(OM[i]));
    }
  }
  A.resize(Smin, 0);
  B.resize(Smin, 0);
  vector<unsigned long long> FA = DFT(A, A.size(), 1, 0, 1);
  vector<unsigned long long> FB = DFT(B, B.size(), 1, 0, 1);
  vector<unsigned long long> Fret(FA.size(), 0);
  for (unsigned int i = 0; i < FA.size(); i++) Fret[i] = (FA[i] * FB[i]) % MOD;
  vector<unsigned long long> ret = DFT(Fret, Fret.size(), 1, 0, -1);
  for (unsigned int i = 0; i < ret.size(); i++)
    ret[i] = (ret[i] * pw(ret.size(), MOD - 2)) % MOD;
  ret.resize(A.size() * 2 - 1);
  return ret;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  int N;
  long long M, mod = 998244353;
  cin >> N >> M;
  N++;
  vector<unsigned long long> P0(N), fac(N, 1), inv(N, 1);
  for (int i = 0; i < N; i++) {
    cin >> P0[i];
    if (i < N - 1) {
      fac[i + 1] = (i + 1) * fac[i] % mod;
      inv[i + 1] = pw(fac[i + 1], mod - 2, mod);
    }
    P0[i] = P0[i] * fac[i] % mod;
  }
  reverse(begin(P0), end(P0));
  vector<unsigned long long> R0 = convolution(P0, inv);
  R0.resize(N);
  reverse(begin(R0), end(R0));
  for (int i = 0; i < N; i++)
    R0[i] = R0[i] * pw(i + 1, mod - 1 - M % (mod - 1), mod) % mod;
  reverse(begin(R0), end(R0));
  for (int i = 0; i < N; i++)
    if (i & 1) inv[i] = (mod - inv[i]) % mod;
  vector<unsigned long long> P = convolution(R0, inv);
  for (int i = 0; i < N; i++)
    if (i & 1) inv[i] = (mod - inv[i]) % mod;
  P.resize(N);
  reverse(begin(P), end(P));
  for (int i = 0; i < N; i++) P[i] = P[i] * inv[i] % mod;
  for (int i = 0; i < N; i++) cout << P[i] << ((i == N - 1) ? "\n" : " ");
  return 0;
}
