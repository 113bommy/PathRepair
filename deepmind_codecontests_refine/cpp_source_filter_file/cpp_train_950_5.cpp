#include <bits/stdc++.h>
using namespace std;
constexpr long long Mod = 1000000007;
int U[200001], Z[200001];
int Ufs(int u) { return U[u] == u ? U[u] : U[u] = Ufs(U[u]); }
long long Pow(int A, int B) {
  long long R = 1;
  while (B) {
    if (B & 1) R = R * A % Mod;
    A = A * A % Mod;
    B >>= 1;
  }
  return R;
}
int main() {
  int N, K;
  scanf("%d%d", &N, &K);
  for (int i = 1; i <= N; ++i) {
    U[i] = i;
    Z[i] = 1;
  }
  for (int i = 1; i < N; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (c) continue;
    auto ua = Ufs(a);
    auto ub = Ufs(b);
    if (Z[ua] < Z[ub]) swap(ua, ub);
    U[ub] = ua;
    Z[ua] += Z[ub];
  }
  long long Ans = Pow(N, K);
  for (int i = 1; i <= N; ++i)
    if (Ufs(i) == i) Ans -= Pow(Z[i], K);
  printf("%lld\n", (Ans % Mod + Mod) % Mod);
  return 0;
}
