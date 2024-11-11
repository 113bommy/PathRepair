#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
struct node {
  long long t[35][35];
  long long tot[35];
  int shift;
};
long long N;
int K;
node merge(node L, node R, int shift) {
  node ans = {};
  ans.shift = L.shift;
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < K; j++) {
      long long tot[35] = {0};
      int en = (j - shift - L.shift + K * 2) % K;
      tot[0] = R.t[(K - shift) % K][en];
      for (int k = 1; k < K; k++) {
        tot[k] = (tot[k - 1] + R.t[(K + k - shift) % K][en]) % MOD;
      }
      for (int k = 0; k < K; k++) {
        ans.t[i][j] =
            (ans.t[i][j] + L.t[i][k] * tot[(k - L.shift + K) % K]) % MOD;
      }
    }
  }
  for (int i = 0; i < K; i++) {
    ans.tot[i] = L.tot[i];
    for (int k = 0; k < K; k++) {
      for (int l = 0; l < K; l++) {
        if ((k - L.shift + K) % K < (l + shift) % K) continue;
        ans.tot[i] = (ans.tot[i] + L.t[i][k] * R.tot[l]) % MOD;
      }
    }
  }
  return ans;
}
int main() {
  scanf("%lld%d", &N, &K);
  node mul = {}, ans = {};
  mul.shift = 0;
  for (int i = 0; i < K; i++) {
    mul.tot[i] = 1 << K - i - 1;
    for (int j = i; j < K; j++) {
      if (i == j)
        mul.t[i][j] = 1;
      else
        mul.t[i][j] = 1 << j - i - 1;
    }
  }
  for (int i = 0; i < N % K; i++) {
    ans.tot[i] = 1 << (N % K - i - 1);
    for (int j = i; j < N % K; j++) {
      if (i == j)
        ans.t[i][j] = 1;
      else
        ans.t[i][j] = 1 << j - i - 1;
    }
  }
  int nw = 1;
  N /= K;
  while (N) {
    node tmp = mul;
    for (int i = 0; i < N % K; i++) ans = merge(tmp, ans, nw % K);
    for (int i = 1; i < K; i++) {
      mul = merge(mul, tmp, nw % K);
      mul.shift = (mul.shift + tmp.shift + nw) % K;
    }
    N /= K;
    nw++;
  }
  long long tot = 1;
  for (int i = 0; i < K; i++) tot += ans.tot[i];
  printf("%lld\n", tot % MOD);
  return 0;
}
