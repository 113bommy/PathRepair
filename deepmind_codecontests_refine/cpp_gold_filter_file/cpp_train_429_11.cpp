#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
void add(int& a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
int mul(int a, int b) { return ll(a) * b % MOD; }
int modinv(int a, int m = MOD) {
  return a == 1 ? a : m - modinv(m % a, a) * ll(m) / a;
}
const int MAXV = 4242;
int p2[MAXV], invp2[MAXV];
int p2m1[MAXV], invp2m1[MAXV];
void precomp() {
  p2[0] = 1;
  for (int i = 1; i < MAXV; i++) {
    p2[i] = mul(2, p2[i - 1]);
  }
  for (int i = 0; i < MAXV; i++) {
    invp2[i] = modinv(p2[i]);
  }
  for (int i = 0; i < MAXV; i++) {
    p2m1[i] = p2[i] - 1;
  }
  for (int i = 1; i < MAXV; i++) {
    invp2m1[i] = modinv(p2m1[i]);
  }
}
const int MAXN = 3010;
int N, C;
int A[MAXN];
int main() {
  precomp();
  scanf("%d %d", &N, &C);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    A[i]--;
  }
  vector<vector<int>> dp(N + 1);
  dp[0] = {{1}};
  if (C > 10) {
    for (int i = 0; i < N; i++) {
      vector<int> freq(C);
      int prod = 1;
      int cnt_bad = C - 1;
      for (int j = i; j >= 0; j--) {
        if (A[i] != A[j]) {
          if (!freq[A[j]]) {
            cnt_bad--;
          } else {
            prod = mul(prod, invp2m1[freq[A[j]]]);
          }
          freq[A[j]]++;
          prod = mul(prod, p2m1[freq[A[j]]]);
        }
        if (cnt_bad == 0) {
          if (dp[i + 1].size() < dp[j].size() + 1) {
            dp[i + 1].resize(dp[j].size() + 1);
          }
          for (int l = 0; l < int(dp[j].size()); l++) {
            add(dp[i + 1][l + 1], mul(prod, dp[j][l]));
          }
        }
      }
    }
  } else {
    vector<vector<int>> dp2(1 << C);
    dp2[0] = {{1}};
    for (int i = 0; i < N; i++) {
      for (int m = (1 << C) - 1; m >= 0; m--) {
        if (dp2[m | (1 << A[i])].size() < dp2[m].size()) {
          dp2[m | (1 << A[i])].resize(dp2[m].size());
        }
        for (int l = 0; l < int(dp2[m].size()); l++) {
          add(dp2[m | (1 << A[i])][l], dp2[m][l]);
        }
      }
      swap(dp[i + 1], dp2[(1 << C) - 1]);
      dp[i + 1].insert(dp[i + 1].begin(), 0);
      if (dp2[0].size() < dp[i + 1].size()) {
        dp2[0].resize(dp[i + 1].size());
      }
      for (int l = 0; l < int(dp[i + 1].size()); l++) {
        add(dp2[0][l], dp[i + 1][l]);
      }
    }
  }
  vector<int> ans(N + 1);
  for (int i = 0; i <= N; i++) {
    for (int l = 0; l < int(dp[i].size()); l++) {
      add(ans[l], mul(p2[N - i], dp[i][l]));
    }
  }
  ans[0]--;
  for (int i = 0; i < N; i++) {
    add(ans[i], MOD - ans[i + 1]);
  }
  for (int i = 0; i <= N; i++) {
    printf("%d%c", ans[i], " \n"[i == N]);
  }
  return 0;
}
