#include <bits/stdc++.h>
using namespace std;
inline int _r() {
  int o = 0, f = 0;
  char t = getchar();
  while (t < 48 || t > 57) f |= (t == '-'), t = getchar();
  while (t > 47 && t < 58) o = o * 10 + t - 48, t = getchar();
  return f ? -o : o;
}
void setIO() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
int n, m, A[505], P[105], M[505][505];
long long F[505][505], mod = 998244353;
long long f(int i, int j) { return i >= j ? 1 : F[i][j]; }
int main() {
  setIO();
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> A[i], P[A[i]] = i;
  for (int i = 1; i <= n; i++) {
    M[i][i] = A[i];
    for (int j = i + 1; j <= n; j++) M[i][j] = min(M[i][j - 1], A[j]);
  }
  for (int j = 1; j <= n; j++) {
    F[j][j] = 1;
    for (int i = j - 1; i >= 1; i--) {
      int t = P[M[i][j]];
      long long l = 0, r = 0;
      for (int k = i - 1; k < t; k++) l += f(i, k) * f(k + 1, t - 1), l %= mod;
      for (int k = t; k <= j; k++) r += f(t + 1, k) * f(k + 1, j), r %= mod;
      F[i][j] = l * r % mod;
    }
  }
  cout << F[1][n];
}
