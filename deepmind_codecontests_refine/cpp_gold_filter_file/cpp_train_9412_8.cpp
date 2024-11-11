#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 21;
int n, m, d, t, r, Mn = M, A[N], C[M];
bool dp[1 << M];
int main() {
  scanf("%d%d%d", &n, &m, &d);
  for (int i = 0; i < m; i++) {
    scanf("%d", &t);
    while (t--) scanf("%d", &r), A[r] = i;
  }
  for (int i = 1; i <= n; i++, t = 0) {
    C[A[i]]++;
    if (i > d) C[A[i - d]]--;
    if (i < d) continue;
    for (int j = 0; j < m; j++)
      if (!C[j]) t |= (1 << j);
    dp[t] = 1;
  }
  for (int i = (1 << m) - 1; i >= 0; i--)
    for (int j = 0; j < m; j++) dp[i] |= dp[i | (1 << j)];
  for (int i = 1; i < (1 << m); i++)
    if (!dp[i]) Mn = min(Mn, __builtin_popcount(i));
  return !printf("%d", Mn);
}
