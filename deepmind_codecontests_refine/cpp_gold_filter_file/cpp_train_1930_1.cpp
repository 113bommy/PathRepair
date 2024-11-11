#include <bits/stdc++.h>
using namespace std;
const int md = 1e9 + 7;
void Add(int &x, int y) {
  x += y;
  if (x >= md) x -= md;
}
int Fast(int x, int k) {
  int res = 1;
  while (k) {
    if (k & 1) res = 1ll * res * x % md;
    x = 1ll * x * x % md;
    k >>= 1;
  }
  return res;
}
int n;
int A[1000005];
int dp[1000005], Inv[1000005], Sum[1000005];
int L[1000005], R[1000005];
int cnt;
void Init() {
  for (int i = (0), i_END_ = (n + 1); i <= i_END_; ++i) {
    if (!A[i]) {
      if (i && A[i - 1]) R[cnt] = i - 1;
      if (A[i + 1]) {
        cnt++;
        L[cnt] = i + 1;
      }
      continue;
    }
  }
}
void Solve() {
  int ans = 0;
  for (int i = (1), i_END_ = (cnt); i <= i_END_; ++i) {
    dp[L[i] - 1] = 1;
    Sum[L[i] - 1] = 0;
    A[L[i] - 1] = 1e9;
    for (int j = (L[i]), i_END_ = (R[i] - 1); j <= i_END_; ++j)
      dp[j] = 1ll * dp[j - 1] * min(A[j - 1], min(A[j], A[j + 1])) % md;
    dp[R[i]] = 1ll * dp[R[i] - 1] * min(A[R[i] - 1], A[R[i]]) % md;
    for (int j = (L[i]), i_END_ = (R[i] - 1); j <= i_END_; ++j) {
      int res = 1ll * dp[j] * Fast(min(A[j - 1], min(A[j], A[j + 1])), md - 2) %
                md * min(A[j], A[j - 1]) % md;
      Add(ans, 1ll * res * Sum[j - 1] % md);
      Add(ans, A[j]);
      Sum[j] =
          (Sum[j - 1] + 1ll * Fast(dp[j], md - 2) * min(A[j], A[j + 1]) % md) %
          md;
    }
    Add(ans, 1ll * dp[R[i]] * Sum[R[i] - 1] % md);
    Add(ans, A[R[i]]);
  }
  printf("%d\n", ans);
}
int main() {
  scanf("%d", &n);
  int a;
  for (int i = (1), i_END_ = (n); i <= i_END_; ++i) scanf("%d", &A[i]), A[i]--;
  Init();
  Solve();
  return 0;
}
