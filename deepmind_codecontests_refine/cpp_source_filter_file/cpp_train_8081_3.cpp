#include <bits/stdc++.h>
using namespace std;
int n, i, p, id, L[1111111], F[1111111], c[1111111][26], df[1111111],
    sk[1111111], f[1111111], _f[1111111], pre[1111111];
char s[1111111], A[1111111], B[1111111];
void add(int z, int n) {
  for (; s[n - L[p] - 1] != s[n]; p = F[p])
    ;
  if (!c[p][z]) {
    int q = ++id, k = F[p];
    L[q] = L[p] + 2;
    for (; s[n - L[k] - 1] != s[n]; k = F[k])
      ;
    F[q] = c[k][z];
    c[p][z] = q;
    df[q] = L[q] - L[F[q]];
    sk[q] = (df[q] == df[F[q]] ? sk[F[q]] : F[q]);
  }
  p = c[p][z];
}
int main() {
  scanf("%s%s", A + 1, B + 1);
  n = strlen(A + 1);
  for (int i = 1; i <= n; i++) s[i * 2 - 1] = A[i], s[i * 2] = B[i];
  id = F[0] = 1;
  L[1] = -1;
  n *= 2;
  _f[0] = 1;
  for (int i = 1; i <= n; i++) f[i] = 1e9;
  for (int i = 1; i <= n; i++) {
    add(s[i] - 'a', i);
    for (int x = p; x; x = sk[x]) {
      _f[x] = i - L[sk[x]] - df[x];
      if (df[F[x]] == df[x] && _f[x] > _f[F[x]]) _f[x] = _f[F[x]];
      if (i % 2 == 0 && f[i] > f[_f[x]] + 1)
        f[i] = f[_f[x]] + 1, pre[i] = _f[x];
    }
    if (i % 2 == 0 && s[i] == s[i - 1] && f[i] > f[i - 2])
      f[i] = f[i - 2], pre[i] = i - 2;
  }
  if (f[n] == 1e9) return puts("-1"), 0;
  printf("%d\n", f[n]);
  for (i = n; i; i = pre[i])
    if (i - pre[i] > 2) printf("%d %d\n", pre[i] / 2 + 1, i / 2);
}
