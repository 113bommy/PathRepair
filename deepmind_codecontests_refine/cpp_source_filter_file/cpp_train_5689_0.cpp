#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chkmin(T &a, T const &b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool chkmax(T &a, T const &b) {
  return a < b ? a = b, 1 : 0;
}
const int M = 35;
const int N = 105;
const int Mod = 998244353;
long long A[M], a[M][M * N];
vector<int> F[M][M * N];
int Sz[M], C[N][N], S[N];
int n;
int Pow(int x, int k) {
  int res = 1;
  for (; k; k >>= 1, x = ((long long)(x) * (x) % Mod))
    if (k & 1) res = ((long long)(res) * (x) % Mod);
  return res;
}
int calc(vector<int> &P, long long l, long long r) {
  int res = 0, x = 1, y = 1;
  l = l % Mod * 616898040 % Mod;
  r = r % Mod * 616898040 % Mod;
  for (int i = (0), i_end__ = (P.size()); i < i_end__; i++) {
    res = (res + (long long)(y - x) * P[i]) % Mod;
    x = ((long long)(x) * (l) % Mod), y = ((long long)(y) * (r) % Mod);
  }
  return res;
}
int main() {
  for (int i = (0), i_end__ = (N); i < i_end__; i++) {
    C[i][0] = 1;
    for (int j = (1), j_end__ = (i + 1); j < j_end__; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % Mod;
  }
  scanf("%d", &n);
  for (int i = (0), i_end__ = (n); i < i_end__; i++) {
    double x;
    scanf("%lf", &x);
    A[i] = min(x, i + 1.0) * 1000000 + 0.5;
  }
  Sz[0] = 2;
  F[0][1].push_back(0), F[0][1].push_back(1);
  F[0][2].push_back(0);
  a[0][1] = A[0];
  for (int i = (1), i_end__ = (n); i < i_end__; i++) {
    for (int j = (1), j_end__ = (Sz[i - 1]); j < j_end__; j++)
      S[j] = (S[j - 1] + calc(F[i - 1][j], a[i - 1][j - 1], a[i - 1][j])) % Mod;
    int pos = lower_bound(a[i - 1], a[i - 1] + Sz[i - 1], A[i]) - a[i - 1];
    a[i - 1][pos] = A[i];
    a[i - 1][pos + 1] = 0x3f3f3f3f3f3f3f3fLL;
    F[i][0].push_back(0), Sz[i] = 1;
    int l = 0, r = 1;
    long long lp = -1000000, rp = 0;
    while (r <= pos) {
      long long Next = min(a[i - 1][l] - lp, a[i - 1][r] - rp);
      a[i][Sz[i]] = rp + Next;
      vector<int> &poy = F[i][Sz[i]];
      poy.resize(max(F[i - 1][r].size(), F[i - 1][l].size()) + 1);
      poy[1] = (calc(F[i - 1][l], 0, a[i - 1][l]) -
                calc(F[i - 1][r], 0, a[i - 1][r - 1])) %
               Mod;
      if (l < r) poy[1] = ((long long)poy[1] + S[r - 1] - S[l]) % Mod;
      for (int j = (0), j_end__ = (F[i - 1][r].size()); j < j_end__; j++)
        poy[j + 1] = (poy[j + 1] + F[i - 1][r][j]) % Mod;
      for (int j = (1), j_end__ = (F[i - 1][l].size()); j < j_end__; j++)
        for (int k = (0), k_end__ = (j + 1); k < k_end__; k++) {
          poy[k + 1] = (poy[k + 1] +
                        ((j - k) & 1 ? 1LL : -1LL) * C[j][k] * F[i - 1][l][j]) %
                       Mod;
        }
      for (int j = (1), j_end__ = (poy.size()); j < j_end__; j++)
        poy[j] = ((long long)(poy[j]) * (Pow(j, Mod - 2)) % Mod);
      if ((lp += Next) == a[i - 1][l]) l++;
      if ((rp += Next) == a[i - 1][r]) r++;
      Sz[i]++;
    }
    F[i][Sz[i]].push_back(0);
  }
  int ans = 0;
  for (int j = (1), j_end__ = (Sz[n - 1]); j < j_end__; j++)
    (ans += calc(F[n - 1][j], a[n - 1][j - 1], a[n - 1][j])) %= Mod;
  printf("%d\n", (ans + Mod) % Mod);
  return 0;
}
