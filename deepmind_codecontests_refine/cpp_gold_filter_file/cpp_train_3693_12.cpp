#include <bits/stdc++.h>
using namespace std;
const int mo = 10007;
char S[205];
int n, m, M, f[205][205][205], ans;
struct O {
  long long a[330][330];
  void clear() { memset(a, 0, sizeof a); }
} A, B, C;
O operator*(const O &A, const O &B) {
  for (int i = 0; i <= M; ++i)
    for (int j = i; j <= M; ++j) {
      C.a[i][j] = 0;
      for (int k = 0; k <= M; ++k) C.a[i][j] += A.a[i][k] * B.a[k][j];
      C.a[i][j] %= mo;
    }
  return C;
}
void fly(int l, int r) {
  if (f[l][r][m + 3]) return;
  if (l > r) {
    f[l][r][0] = 1;
    return;
  }
  if (S[l] == S[r]) {
    fly(l + 1, r - 1);
    for (int i = 0; i <= m; ++i) f[l][r][i] = f[l + 1][r - 1][i];
  } else {
    fly(l, r - 1);
    fly(l + 1, r);
    for (int i = 1; i <= m; ++i)
      f[l][r][i] = (f[l][r - 1][i - 1] + f[l + 1][r][i - 1]) % mo;
  }
  f[l][r][m + 3] = 1;
}
void ply(int l, int r) {
  if (f[l][r][m + 3]) return;
  if (l > r) {
    f[l][r][0] = 1;
    return;
  }
  if (S[l] == S[r]) {
    if (l == r) return;
    ply(l + 1, r - 1);
    for (int i = 0; i <= m; ++i) f[l][r][i] = f[l + 1][r - 1][i];
  } else {
    ply(l, r - 1);
    ply(l + 1, r);
    for (int i = 1; i <= m; ++i)
      f[l][r][i] = (f[l][r - 1][i - 1] + f[l + 1][r][i - 1]) % mo;
  }
  f[l][r][m + 3] = 1;
}
int main() {
  scanf("%s%d", S + 1, &n);
  m = strlen(S + 1);
  fly(1, m);
  for (int i = 1; i < m; ++i) A.a[i][i] = 24;
  for (int i = 1; i < m - 1; ++i) A.a[i][i + 1] = 1;
  for (int i = 1; i < m; ++i)
    A.a[i][m + (m + 1) / 2 - (m - i + 1) / 2] = f[1][m][i];
  A.a[0][m] = f[1][m][0];
  if (m > 1) A.a[0][1] = 1;
  for (int i = m; i <= m + (m + 1) / 2 - 1; ++i)
    A.a[i][i] = 25, A.a[i][i + 1] = 1;
  M = m + (m + 1) / 2;
  A.a[M][M] = 26;
  for (int i = 0; i <= M; ++i) B.a[i][i] = 1;
  for (int e = (n + m + 1) / 2 + 1; e; e >>= 1) {
    if (e & 1) B = B * A;
    A = A * A;
  }
  ans = B.a[0][M];
  if ((m + n) & 1) {
    memset(f, 0, sizeof f);
    ply(1, m);
    A.clear();
    for (int i = 1; i < m; ++i) A.a[i][i] = 24;
    for (int i = 1; i < m - 1; ++i) A.a[i][i + 1] = 1;
    for (int i = 1; i < m; ++i)
      A.a[i][m + (m + 1) / 2 - (m - i + 1) / 2] = f[1][m][i];
    A.a[0][m] = f[1][m][0];
    if (m > 1) A.a[0][1] = 1;
    for (int i = m; i <= m + (m + 1) / 2 - 1; ++i)
      A.a[i][i] = 25, A.a[i][i + 1] = 1;
    M = m + (m + 1) / 2;
    B.clear();
    for (int i = 0; i <= M; ++i) B.a[i][i] = 1;
    for (int e = (n + m + 1) / 2 + 1; e; e >>= 1) {
      if (e & 1) B = B * A;
      A = A * A;
    }
    ans -= B.a[0][M];
  }
  printf("%d\n", (ans % mo + mo) % mo);
  return 0;
}
