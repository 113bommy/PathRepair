#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const long long inf = 1LL << 60;
int gi() {
  int w = 0;
  bool q = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 0, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? w : -w;
}
long long f[N][N], L[N][N], R[N][N], ans[N];
int v[N], x[N];
int main() {
  int n = gi(), i, len, l, r;
  for (i = 1; i <= n; i++) v[i] = gi(), f[i][i] = v[1];
  for (i = 1; i <= n; i++) x[i] = gi();
  for (len = 2; len <= n; len++)
    for (l = 1, r = len; r <= n; l++, r++) {
      f[l][r] = -inf, L[l][r] = R[l][r] = l == r ? 0 : -inf;
      for (i = l; i < r; i++) f[l][r] = max(f[l][r], f[l][i] + f[i + 1][r]);
      for (i = l; i < r; i++)
        if (x[i] + 1 == x[r]) L[l][r] = max(L[l][r], L[l][i] + f[i + 1][r - 1]);
      for (i = l + 1; i <= r; i++)
        if (x[i] + 1 == x[l]) R[l][r] = max(R[l][r], R[i][r] + f[l + 1][i - 1]);
      for (i = l; i <= r; i++)
        if (L[l][i] > -1LL << 50 && R[i][r] > -1LL << 50)
          f[l][r] = max(f[l][r],
                        L[l][i] + R[i][r] + v[(x[i] << 1) - x[l] - x[r] + 1]);
    }
  for (i = 1; i <= n; i++) {
    ans[i] = -inf;
    for (l = 0; l < i; l++) ans[i] = max(ans[i], ans[l] + f[l + 1][i]);
  }
  cout << ans[n] << endl;
  return 0;
}
