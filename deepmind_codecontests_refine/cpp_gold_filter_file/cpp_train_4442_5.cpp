#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, NX = 1e9 + 7;
int n, m, r, t, c, Mn = 1e9, A[N], C[N], B[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &B[i]), t += B[i];
  C[A[1]]++;
  r = 1;
  for (int j = 1; j <= m; j++)
    if (C[j] < B[j]) c++;
  for (int i = 1; i <= n; i++) {
    while (c && r < n) {
      r++;
      C[A[r]]++;
      if (C[A[r]] == B[A[r]]) c--;
    }
    if (c) break;
    Mn = min(Mn, r - i + 1);
    C[A[i]]--;
    if (C[A[i]] < B[A[i]]) c++;
  }
  if (Mn == 1e9) Mn = t - 1;
  return !printf("%d", Mn - t);
}
