#include <bits/stdc++.h>
using namespace std;
const int N = 7100;
int n, m, k, T, X, K, t[N], l[N], r[N], x[N], L[N], R[N], f[2 * N];
int main() {
  scanf("%d%d", &n, &m);
  f[0] = -1;
  for (int i = 1; i < 2 * N; i++) f[i] = f[i >> 1] + 1;
  while (m--) {
    scanf("%d", &K);
    if (K == 1) {
      scanf("%d%d%d%d", t + k, l + k, r + k, x + k);
      k++;
    } else {
      scanf("%d%d", &T, &X);
      L[T] = R[T] = X;
      for (int i = T + 1; i <= n; i++) {
        L[i] = L[i - 1] + f[L[i - 1] - 1] + 1;
        R[i] = R[i - 1] + f[R[i - 1]] + 1;
        if (R[i] > 2 * n) {
          T = n + 1;
          break;
        }
      }
      set<int> ans;
      for (int i = 0; i < k; i++)
        if (t[i] >= T)
          if ((L[t[i]] <= r[i]) && (l[i] <= R[t[i]])) ans.insert(x[i]);
      printf("%d\n", ans.size());
    }
  }
  return 0;
}
