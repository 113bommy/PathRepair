#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, X = 1e5;
int n, m, a[N], L[N], R[N];
int main() {
  scanf("%d%d", &n, &m);
  if (n == 1) return puts("0"), 0;
  for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
  for (int i = m; i >= 1; i--) {
    R[X + a[i] - i] = R[X + a[i] - i - 1] + 1;
    L[X + a[i] + i] = L[X + a[i] + i + 1] + 1;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    ans += min(n, i + m + 1 - R[i + X]) - max(1, i - (m + 1) + L[i + X]) + 1;
  printf("%I64d\n", ans);
  return 0;
}
