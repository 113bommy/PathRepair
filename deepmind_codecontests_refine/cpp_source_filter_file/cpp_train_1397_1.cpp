#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 50;
long long n, k, A[MAXN], B[MAXN], C[MAXN];
long long dp1[100005], dp2[100005], p[20005];
int main() {
  cin >> n >> k;
  p[0] = 1;
  for (int i = 1; i <= 100000; i++) dp1[i] = dp2[i] = -0x3f;
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= n; i++) cin >> B[i], C[i] = A[i] - B[i] * k;
  for (int i = 1; i <= n; i++) {
    if (C[i] <= 0)
      for (int j = 100000; j >= -C[i]; j--)
        dp2[j] = max(dp2[j + C[i]] + A[i], dp2[j]);
    else
      for (int j = 100000; j >= C[i]; j--)
        dp1[j] = max(dp1[j - C[i]] + A[i], dp1[j]);
  }
  long long Ans = -0x3f;
  for (int i = 0; i <= 100000; i++) Ans = max(Ans, dp1[i] + dp2[i]);
  Ans > 0 ? cout << Ans : cout << -1;
  return 0;
}
