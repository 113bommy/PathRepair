#include <bits/stdc++.h>
using namespace std;
const int MAXP = 50, LOG = 13;
const long long MOD = 1e9 + 7;
int K;
int ZZ, MZ;
int Z[MAXP];
bool D;
long long N, H;
long long S[MAXP];
long long P[MAXP];
long long R[2][MAXP][MAXP];
void brute(int id, long long now) {
  if (id == ZZ) {
    H += now;
    if (H >= MOD) H -= MOD;
    return;
  }
  for (int i = 0; i <= Z[id]; i++) {
    brute(id + 1, now * R[D][Z[id]][i] % MOD);
    now = now * P[id] % MOD;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> K;
  for (long long i = 2; i * i <= N; i++) {
    if (N % i == 0) {
      P[ZZ] = i;
      while (N % i == 0) {
        N /= i;
        Z[ZZ]++;
      }
      MZ = max(MZ, Z[ZZ]);
      ZZ++;
    }
  }
  if (N > 1) {
    P[ZZ] = N % MOD;
    Z[ZZ] = 1;
    MZ = max(MZ, Z[ZZ]);
    ZZ++;
  }
  S[0] = 1;
  R[0][0][0] = 1;
  for (int i = 1; i <= MZ; i++) {
    S[i] = (MOD - MOD / (i + 1)) * S[MOD % (i + 1) - 1] % MOD;
    R[0][i][i] = 1;
  }
  for (int i = LOG; i >= 0; i--) {
    if (K >> (i + 1)) {
      for (int j = 0; j <= MZ; j++) {
        for (int k = 0; k <= j; k++) {
          R[!D][j][k] = 0;
          for (int l = k; l <= j; l++) {
            R[!D][j][k] += R[D][j][l] * R[D][l][k];
            R[!D][j][k] %= MOD;
          }
        }
      }
      D = !D;
    }
    if ((K >> i) & 1) {
      for (int j = 0; j <= MZ; j++) {
        for (int k = 0; k <= j; k++) {
          R[!D][j][k] = 0;
          for (int l = k; l <= j; l++) {
            R[!D][j][k] += R[D][j][l] * S[l];
            R[!D][j][k] %= MOD;
          }
        }
      }
      D = !D;
    }
  }
  brute(0, 1);
  cout << H << '\n';
  return 0;
}
