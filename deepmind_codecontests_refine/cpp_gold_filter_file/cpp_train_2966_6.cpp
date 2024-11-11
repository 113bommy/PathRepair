#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int eg[maxn][maxn];
unsigned long long A[maxn][maxn];
int N, M, K;
int gauss(int n) {
  unsigned long long mu = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      while (A[j][i]) {
        unsigned long long t = A[i][i] / A[j][i];
        for (int k = 0; k <= n; k++) {
          A[i][k] -= t * A[j][k];
        }
        swap(A[i], A[j]);
        mu *= -1ull;
      }
    }
    mu *= A[i][i];
  }
  return mu;
}
int ec[maxn][1 << 10];
unsigned long long F[maxn], nCr[maxn][maxn];
int rid[maxn], lis[maxn], ln;
void solve() {
  for (int i = 1; i <= N; i++) {
    for (int s = 1; s < 1 << N; s++) {
      ec[i][s] = ec[i][s ^ (s & (-s))] + eg[i][__builtin_ctz(s) + 1];
    }
  }
  for (int s = 0; s < 1 << N; s++) {
    memset(A, 0, sizeof(A));
    ln = 0;
    memset(rid, 0, sizeof(rid));
    unsigned long long now = 1;
    for (int i = 1; i <= N; i++) {
      if (!(s >> (i - 1) & 1)) {
        lis[++ln] = i;
        rid[i] = ln;
      } else
        now *= ec[i][((1 << N) - 1) ^ s];
    }
    for (int i = 1; i <= ln; i++) {
      int u = lis[i];
      for (int t = 1; t <= N; t++) {
        if (eg[u][t] && rid[t]) {
          A[i][rid[t]]--;
          A[i][i]++;
        }
      }
    }
    F[__builtin_popcount(s)] += now * gauss(ln - 1);
  }
}
int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1; i <= M; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    eg[a][b] = eg[b][a] = 1;
  }
  solve();
  for (int i = 0; i <= N; i++) {
    nCr[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
    }
  }
  for (int i = N; i >= 1; i--) {
    for (int j = i + 1; j <= N; j++) {
      F[i] -= nCr[j][i] * F[j];
    }
  }
  cout << F[K] << '\n';
  return 0;
}
