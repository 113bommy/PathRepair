#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
const int MAXN = 200001;
const int MAXM = 3010;
const int INF = 999999;
const long long Mod = 998244353LL;
inline long long Pow(long long a, long long b) {
  long long ret = 1;
  for (; b; b >>= 1, a = a * a % Mod)
    if (b & 1) ret = ret * a % Mod;
  return ret;
}
int N, M;
long long S[2], a[MAXN + 1], b[MAXN + 1];
long long g[2];
long long Iv[MAXN + 1];
long long f[MAXM + 1][MAXM + 1];
int main() {
  N = read(), M = read();
  for (int i = 1; i <= N; i++) a[i] = read();
  for (int i = 1; i <= N; i++) b[i] = read();
  for (int i = 1; i <= N; i++) S[a[i]] += b[i];
  for (int i = 0; i <= 2 * MAXM; i++)
    Iv[i] = Pow((S[0] + S[1] + i - MAXM + Mod) % Mod, Mod - 2);
  f[0][0] = 1;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j <= i; j++) {
      if (!f[i][j]) continue;
      int ad = j, dl = i - j, all = ad - dl + S[0] + S[1];
      int n0 = S[0] - dl, n1 = S[1] + ad;
      n0 = n0 * Iv[ad - dl + MAXM] % Mod;
      n1 = n1 * Iv[ad - dl + MAXM] % Mod;
      (f[i + 1][j] += f[i][j] * n0 % Mod) %= Mod;
      (f[i + 1][j + 1] += f[i][j] * n1 % Mod) %= Mod;
    }
  }
  for (int i = 0; i <= M; i++) {
    g[0] = (g[0] - f[M][i] * (M - i) % Mod + Mod) % Mod;
    g[1] = (g[1] + f[M][i] * i % Mod) % Mod;
  }
  S[0] = Pow(S[0], Mod - 2);
  S[1] = Pow(S[1], Mod - 2);
  for (int i = 1; i <= N; i++) {
    long long ret = (b[i] + S[a[i]] * b[i] % Mod * g[a[i]] % Mod) % Mod;
    cout << ret << endl;
  }
  return 0;
}
